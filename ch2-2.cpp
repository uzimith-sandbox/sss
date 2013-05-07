#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

vector< vector<string> > answer;
vector<string> dic;
map<char,int> ch;
vector<int> length,scan,dic_size;

void decode() {
  for (unsigned int i = 0; i < length.size(); i++) {
    vector<string> current;
    for (unsigned int j = 0; j < dic.size(); j++)
      if(length[i] == dic[j].size()) current.push_back(dic[j]);
    answer.push_back(current);
  }
}

bool output() {
  scan.clear();
  for(unsigned int i = 0; i < length.size(); ++i) scan.push_back(0);
  map<char,int> count;
  while(true) {
    string line = "";
    for (unsigned int i = 0; i < length.size(); ++i) line += answer[i][scan[i]];
    stringstream ss;
    char c;
    ss.str(line);
    while(ss >> c) count[c]++;
    if(count == ch) return true;
    scan[0]++;
    for(unsigned int i = 0; i < answer.size(); ++i) {
      if(scan[i] == answer[i].size()) {
	if(i == answer[i].size()-1) return false;
	scan[i] = 0;
	scan[i+1]++;
      }
    }
  }
}
int main()
{
  int n;
  cin >> n;

  string read;
  for(int i = 0; i < n; i++) {
    cin >> read;
    dic.push_back(read);
  }

  stringstream ss;
  cin.ignore();
  while(getline(cin,read)) {
    ss.str(read);
    while(ss >> read) {
      for(unsigned int i = 0; i < read.size(); i++) ch[read[i]]++;
      length.push_back(read.size());
    }
    decode();
    if(output()){
      for(unsigned int i; i < answer.size(); i++) {
	cout << answer[i][scan[i]];
	if(i != answer.size() -1) cout << " ";
      }
    } else {
      for(unsigned int i=0; i < length.size(); i++) {
	for(int j; j < length[i]; j++) cout << "*";
	if(i != length.size()-1) cout << " ";
      }
    }
    cout << endl;
    ss.clear();
    answer.clear();
  }
}
