#include <iostream>
using namespace std;
class Word{
	private: string word;
		     int count;
	         int total;
	public: Word(string text, int count, int total){
		word = text;
		this->count = count;
		this->total = total;
	}
	void increaseTotal(int value){
		total += value;
		count++;
	}
	double calculateScore(){
		if (count == 0){
			return 0;
		}
		return (double)total/count;
	}
	int getCount(){
		return count;
	}
	string getWord() const{
		return word;
	}
};