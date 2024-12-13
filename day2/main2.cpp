#include "iostream"
#include "vector"
#include "fstream"
#include "sstream"
using namespace std;

bool isSafe(vector<int>& levels) {
    if (levels.size() <= 1) return true; 

    int order = (levels[1] > levels[0]) ? 1 : -1;
    for (int i = 0; i < levels.size() - 1; i++) {
        int step = levels[i + 1] - levels[i];
        if (step * order > 3 || step * order < 1 || step == 0) {
            return false;
        }
    }
    return true;
}

bool isSafeWithDampener(vector<int>& levels) {
    if (isSafe(levels)) return true;
    for (int i = 0; i < levels.size(); i++) {
        vector<int> modified = levels;
        modified.erase(modified.begin() + i);
        if (isSafe(modified)) {
            return true;
        }
    }
    return false;
}

int numSafeReports(string path) {
    ifstream file(path);
    string text;
    int safeReports = 0;

    while (getline(file, text)) {
        vector<int> array;
        istringstream lineStream(text);
        string entry;
        while (lineStream >> entry) {
            array.push_back(stoi(entry));
        }

        if (isSafeWithDampener(array)) {
            safeReports++;
        }
    }

    return safeReports;
}

int main() {
    cout << numSafeReports("input.txt") << endl;
    return 0;
}
