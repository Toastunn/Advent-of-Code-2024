#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string newLine;
  string filePath;
  vector<int> vec1;
  vector<int> vec2;
  int simScore;

  cin >> filePath;

  //open and read input file
  ifstream FileToRead(filePath);

  //read each line of the file
  while (getline(FileToRead, newLine)) {
    vec1.push_back(stoi(newLine.substr(0, 5)));
    vec2.push_back(stoi(newLine.substr(8)));
  }

  for(int id1 : vec1) {
    int occurences = 0;

    for(int id2 : vec2) {
      if(id1 == id2) occurences++;
    }

    simScore += id1 * occurences;
  };
  
  cout << simScore;

  FileToRead.close();
  return 0;
}