#include "iostream"
#include "vector"
#include "fstream"
#include "sstream"
using namespace std;

int numSafeReports(string path)
{
  ifstream file(path);
  string text;
  int inc = 0;
  int numOfLines = 0;
  while (getline(file, text))
  {
    numOfLines++;
    vector<int> array;
    istringstream lineStream(text);
    string entry;
    while (lineStream >> entry)
    {
      array.push_back(stoi(entry));
    }
    int order;
    for (int i = 0; i < array.size() - 1; i++)
    {
      if (i == 0)
        order = (array[i] > array[i + 1]) ? -1 : 1; // 1 for asc, -1 for desc
      int step = array[i + 1] - array[i];
      if (step * order > 3 || step * order < 1)
      {
        inc++;
        break;
      }
    }
    array.clear();
  }
  return numOfLines - inc;
}

int main()
{
  cout << numSafeReports("input.txt");
  return 0;
}
