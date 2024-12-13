#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_map>

long readFileIntoVectors(std::string filename) {
    std::vector<int> vector1, vector2;
    std::ifstream file(filename);
    std::unordered_map<int, int> map;
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return -1;
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

    for(int elem: vector2){
      map[elem]++;
    }

    long sum;
    for(int elem: vector1){
      sum += elem*map[elem];
    }
    return sum;
}

int main(){
  std::string filePath = "input.txt";
  std::cout << readFileIntoVectors(filePath)<< std::endl;

  return 0;
}