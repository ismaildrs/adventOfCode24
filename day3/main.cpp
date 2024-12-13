#include "iostream"
#include "vector"
#include "fstream"
#include "sstream"
#include "regex"
using namespace std;


int readThroughFile(string path){
  ifstream file(path);
  string text;
  regex rexp{R"(mul\((\d+),(\d+)\))"};
  smatch m;
  int counter = 0;
  while(getline(file, text)){
    auto search_start = text.cbegin();
    while(regex_search(search_start, text.cend(), m, rexp)){
      counter += stoi(m[1].str()) * stoi(m[2].str());
      search_start = m.suffix().first;
    }
  }
  return counter;
}

int main(){
  cout << readThroughFile("input.txt") << endl;
  return 0;
}