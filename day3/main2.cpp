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
  regex secRegExp("don't\\(\\)");
  regex thirdRegExp("do\\(\\)");
  smatch m, m2;

  int counter = 0;
  bool calculate = true;

  while(getline(file, text)){

    auto search_start = text.cbegin();

    while(regex_search(search_start, text.cend(), m, rexp)){
      auto search_sub = m.prefix().second;
      string stemp;

      while(regex_search(search_start, search_sub, m2, secRegExp) || regex_search(search_start, search_sub, m2, thirdRegExp)){
        search_start = m2.suffix().first;
        stemp = m2[0].str();
      }
      search_start = m.suffix().first;
      calculate = (stemp == "don't()")?false:(stemp == "do()")?true: calculate; 
      if(!calculate){continue;}
      else counter += stoi(m[1].str()) * stoi(m[2].str());
    }

  }
  return counter;
}

int main(){
  cout << readThroughFile("input.txt") << endl;
  return 0;
}

// xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))