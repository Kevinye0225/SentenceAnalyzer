// #include "Analyzer.cpp"
// struct wordComparator {
//   bool operator() (const Word* lhs, const Word* rhs) const
//   {return lhs->getWord() <  rhs->getWord();}
// };

vector<Sentence*>& readFile(char*);
set<Word*>& allWords(vector<Sentence*>&);
map<string, double>& calculateScores(set<Word*>&);
double calculateScore(map<string, double>& scores, string sentence) ;