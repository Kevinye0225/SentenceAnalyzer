#include <iostream>
using namespace std;
class Sentence{
	private: int score;
	         string text;
	public: Sentence(int score, string text){
		this->score = score;
		this->text = text;
	}
	int getScore(){
		return score;
	}
	string getText(){
		return text;
	}
};