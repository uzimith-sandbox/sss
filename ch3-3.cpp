#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

vector<string> line;

class sizecmp{
public:
  bool operator()(const string& a,const string& b) {
    return a.size() > b.size();
  }
};

void solve() {
  
}

int main()
{
  int cases;
  cin >> cases;
  cin.ignore(2048,'\n').ignore(2048,'\n');
  while (cases--) {
    string read;
    while(getline(cin,read) && !read.empty()) line.push_back(read);
    sort(line.begin(),line.end(),sizecmp());
    solve();
    if(cases > 0) cout << endl;
    line.clear();
  };
  return 0;
}


