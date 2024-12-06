#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

void readFileIntoVectors(std::string filename, std::vector<int>& vector1, std::vector<int>& vector2) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        int value1, value2;
        if (lineStream >> value1 >> value2) {
            vector1.push_back(value1);
            vector2.push_back(value2);
        } else {
            std::cerr << "Warning: Invalid line format: " << line << std::endl;
        }
    }

    file.close();
}

int getSum(std::vector<int> vec1, std::vector<int> vec2){
  int sum =0;
  std::sort(vec1.begin(), vec1.end());
  std::sort(vec2.begin(), vec2.end());
  for(int i=0; i<vec1.size(); i++){
    sum += abs(vec2[i] - vec1[i]);
  }
  return sum;
}

int main(){
  std::vector<int> column1, column2;
  std::string filePath = "input.txt";
  readFileIntoVectors(filePath, column1, column2);
  int sum = getSum(column1, column2);
  std::cout << sum << std::endl;

  return 0;
}