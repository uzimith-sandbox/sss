#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
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
  char buffer[258];
  scanf("%d\n\n",&cases);
  while (cases--) {
    while(gets(buffer) != NULL && strcmp(buffer, "") != 0){
      line.push_back(string(buffer));
    }

    solve();
    if(cases > 0) cout << endl;
    line.clear();
  };
  return 0;
}
