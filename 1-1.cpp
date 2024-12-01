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
  int result;

  cin >> filePath;

  //open and read input file
  ifstream FileToRead(filePath);

  //read each line of the file
  while (getline(FileToRead, newLine)) {
    vec1.push_back(stoi(newLine.substr(0, 5)));
    vec2.push_back(stoi(newLine.substr(8)));
  }

  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());

  for(int i = 0; i < vec1.size(); i++) {
    result += abs(vec1[i] - vec2[i]);
  };
  
  cout << result;

  FileToRead.close();
  return 0;
}