#include <stdio.h>
#include <boost/algorithm/string.hpp>
#include <string>
#include <stdlib.h>
#include <vector>	
#include <set>
#include "Sentence.h"
#include <iostream>
#include <fstream>
#include "Word.h"
#include <map>
// #include "Analyzer.h"

using namespace std;
using namespace boost; 


vector<Sentence*>& readFile(char* filename) {

  // UNCOMMENT AND IMPLEMENT THIS FOR PART 1
	ifstream myfile;
	myfile.open(filename, ios::in);
  string line;
  string num;
  string sentences;
  int i,j;

  int score = 0;
  vector<Sentence*> *result = new vector<Sentence*>;

  if (!myfile.is_open()){
    cout<<"File not open/File not found"<<endl;
  } else {
    while (getline(myfile, line)){
      i = 0;
      string::iterator it = line.begin();
      while (*it != ' '){
        it++;
        i++;
      }
      num = line.substr(0,i);
      while (*it == ' '){
        it++;
        i++;
      }
      j = i;
      // cout<<num<<endl;
      score = stoi(num, nullptr);
      // cout<<score<<endl;
      while (it != line.end()){
        it++;
        j++;
      }
      sentences = line.substr(i,j-i+1);
      // cout<<sentences<<endl;
      Sentence* temp = new Sentence(score, sentences);
      result->push_back(temp);
    }
    myfile.close(); 

  }


	return *result;


}



// YOU WILL NEED THIS FOR PART 2
struct wordComparator {
  bool operator() (const Word* lhs, const Word* rhs) const
  {return lhs->getWord() <  rhs->getWord();}
};


set<Word*, wordComparator>& allWords(vector<Sentence*>& sentences) {

  // create the set using the wordComparator struct like this:
  set<Word*, wordComparator>* words = new set<Word*, wordComparator>;

  // UNCOMMENT AND IMPLEMENT THIS FOR PART 2
  vector<Sentence*>::iterator it = sentences.begin();

  while (it != sentences.end()){
    vector<string> fields;   
    string temp_string = (*it)->getText();
    split(fields, temp_string, is_any_of(" "));
    double score = (*it)->getScore();

    vector<string>::iterator temp_it = fields.begin();


    while (temp_it != fields.end()){
      string temp_text = *temp_it;
      to_lower(temp_text);
      if (temp_text[0] >= 'a' && temp_text[0] <= 'z'){

            Word* add_word = new Word(temp_text, 1, score);
            set<Word*, wordComparator>::iterator find_word = words->find(add_word);
            if (find_word == words->end()){
              words->insert(add_word);
            } else {
              (*find_word)->increaseTotal(score);
              delete add_word;
            }

      }

      temp_it++;
    }
    it++;
  }

  return *words;

}



map<string, double>& calculateScores(set<Word*>& words) {
  
  // UNCOMMENT AND IMPLEMENT THIS FOR PART 3
  map<string, double>* result = new map<string, double>;
  // if (words == NULL) return *result;
  set<Word*>::iterator it = words.begin();

  while (it != words.end()){
    string text = (*it)->getWord();
    double score = (*it)->calculateScore();
    (*result)[text] = score;
    it++;
  }

  return *result;

}




double calculateScore(map<string, double>& scores, string sentence) {

  // UNCOMMENT AND IMPLEMENT THIS FOR PART 4
  vector<string> fields;
  split(fields, sentence, is_any_of(" "));
  double result = 0;
  double score;
  int num_of_words = 0;

  vector<string>::iterator it = fields.begin();
  while (it != fields.end()){
    string temp = *it;
    to_lower(temp);
    map<string, double>::iterator map_it = scores.find(temp);
    if (map_it != scores.end()){
      score = scores.at(temp);
      result += score;
      num_of_words++;
    }
    it++;
  }
  if (num_of_words == 0){
    return 0;
  }

  return result/num_of_words;

}

