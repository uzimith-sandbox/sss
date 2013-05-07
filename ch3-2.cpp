#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

vector<string> line;
string key = "the quick brown fox jumps over the lazy dog";
map<char,char> table;

bool make_table(string s) {
  int i;
  table.clear();
  for (i = 0; i < s.size(); ++i) {
    if(s[i] != ' ') {
      if(table.find(s[i]) != table.end() && table[s[i]] != key[i]) break;
      else table[s[i]] = key[i];
    } else if(key[i] != ' ') break;
  }
  return i == s.size();
}

bool decode() {
  for (unsigned int i = 0; i < line.size(); ++i) {
    if(line[i].size() == key.size()) {
      if(make_table(line[i])) return true;
    }
  }
  return false;
}

void solve() {
  if(decode()) {
    for (int i = 0; i < line.size(); ++i) {
      for (int j = 0; j < line[i].size(); ++j) {
	if(line[i][j] != ' ') cout << table[line[i][j]];
	else cout << ' ';
      }
      cout << endl;
    }
  } else {
    cout << "No solution." << endl;
  }
}

int main()
{
  int cases;
  cin >> cases;
  cin.ignore(2048,'\n').ignore(2048,'\n');
  while (cases--) {
    string read;
    while(getline(cin,read) && !read.empty()) line.push_back(read);

    solve();
    if(cases > 0) cout << endl;
    line.clear();
  };
  return 0;
}
