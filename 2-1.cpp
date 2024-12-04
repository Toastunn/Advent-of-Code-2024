#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> splice_str(string input, string splice) {
  vector<int> strings;
  for(int i = 0; i < input.size(); i++) {
    size_t spnsz = strspn(input.substr(i).c_str() , splice.c_str());
    strings.push_back(stoi(input.substr(i, spnsz)));
    i += spnsz;
  }
  return strings;
};

int main() {
  string newLine;
  string filePath;
  vector<int> report;
  int safeReports;

  cin >> filePath;

  //open and read input file
  ifstream FileToRead(filePath);

  //read each newLine of the file
  while (getline(FileToRead, newLine)) {
    cout << "b";
  }
  
  cout << safeReports; //0??

  FileToRead.close();
  return 0;
}