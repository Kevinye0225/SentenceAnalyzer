#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <vector>   
#include <set>
#include "Sentence.h"
#include <iostream>
#include <fstream>
#include "Word.h"
#include <map>
#include "Analyzer.h"

using namespace std;





void delete_vector(vector<Sentence*> input){
    vector<Sentence*>::iterator it = input.begin();
    while (it != input.end()){
        delete *it;
        it++;
    }
}

void delete_set(set<Word*> input){
    set<Word*>::iterator it = input.begin();
    while (it != input.end()){
        delete *it;
        it++;
    }
}

int main(int argc, char** argv) {

    if (argc != 2){
        cout<<"Please enter valid input"<<endl;
        return 0;
    }

	char* file_name = argv[1];
    double score = 0;
    int quit = 0;
    string sentence_analysis;

	vector<Sentence*>& result = readFile(file_name);
    vector<Sentence*> empty_vector;
    set<Word*>& temp_set = allWords(result);
    // free the memory of vector
    delete_vector(result);
    result.swap(empty_vector);
    delete &result;
    
    // set<Word*>::iterator set_it = temp_set.begin();
    // while (set_it != temp_set.end()){
    //     cout<<(*set_it)->getWord()<<(*set_it)->getCount()<<endl;
    //     set_it++;
    // }

    map<string, double>& temp_map = calculateScores(temp_set);
    delete_set(temp_set);
    delete &temp_set;

// keep looping and asking for user input till seeing quit
    while (quit == 0){
        cout<<"Please enter a sentence: "<<endl;
        score = 0;
        getline(cin, sentence_analysis);
        vector<string> word_of_sentence;
        if (sentence_analysis == "quit"){
            quit = 1;
        } else {

            score += calculateScore(temp_map, sentence_analysis);
            cout<<"The score of the sentence you entered is: "<<score<<endl;

        }
   
    }


    delete &temp_map;




	return 0;
}


