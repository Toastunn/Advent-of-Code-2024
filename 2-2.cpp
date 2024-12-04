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

bool check(vector<int> report) {
  bool previousIncreasing;

  for (int i = 0; i < report.size(); i++) {
    bool localIncreasing;

    if(report[i+1] > report[i]) localIncreasing = true;
    else if (report[i+1] < report[i]) localIncreasing = false;
    else break;

    if(previousIncreasing != localIncreasing && i != 0) break;

    previousIncreasing = localIncreasing;

    int difference = abs(report[i] - report[i+1]);
    if(difference > 3 || difference < 1) break;

    if(i+1 == report.size()-1) {
      return true;
    }
  }
  return false;
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
    report = splice_str(newLine, "1234567890");

    bool safe = check(report);
    
    if(!safe) {
      vector<int> bufreport;
      for(int i = 0; i < report.size(); i++) {
        bufreport = report;
        bufreport.erase(bufreport.begin() + i);
        safe = check(bufreport);
        if(safe) break;
      }
    }

    if(safe) safeReports++;
  };
  
  cout << safeReports;

  FileToRead.close();
  return 0;
}