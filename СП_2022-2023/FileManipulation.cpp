#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX_PATHS = 100;
const int MAX_DIRS = 100;

void readPaths(string fileName, string paths[][MAX_DIRS], int &numPaths) {
    ifstream input(fileName);
    string line;
    numPaths = 0;
    while (getline(input, line)) {
        stringstream ss(line);
        int numDirs = 0;
        string dir;
        while (getline(ss, dir, '/')) {
            if (!dir.empty()) {
                paths[numPaths][numDirs] = dir;
                numDirs++;
            }
        }
        numPaths++;
    }
    input.close();
}

string findCommonDir(string paths[][MAX_DIRS], int numPaths) {
    string commonDir;
    for (int i = 0; i < MAX_DIRS; i++) {
        string dir = paths[0][i];
        for (int j = 1; j < numPaths; j++) {
            if (paths[j][i].empty() || paths[j][i] != dir) {
               cout << "Nothing" << endl;
               return 0;
            }
        }
        if (!dir.empty()) {
            commonDir += "/" + dir;
        }
    }
    return commonDir;
}

int main() {
    string paths[MAX_PATHS][MAX_DIRS];
    int numPaths = 0;
    readPaths("paths.txt", paths, numPaths);
    string commonDir = findCommonDir(paths, numPaths);
    cout << "The common directory is: " << commonDir << endl;
    return 0;
}