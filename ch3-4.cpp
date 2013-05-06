#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int INF = 100000;
typedef pair<int,string> P;
vector<string> dic;
vector<int> d;
string n,m;

bool doublets(const string& a,const string& b) {
  if(a.size() != b.size()) return false;
  int diff = 0;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != b[i]) diff++;
    if(diff > 1) return false;
  }
  return true;
}

void print(const int& goal) {
  stack<int> route;
  route.push(goal);
  while(d[route.top()] != -1) route.push(d[route.top()]);
  while(route.size()) {
    int i = route.top(); route.pop();
    cout << dic[i] << endl;
  }
}

void solve() {
  d.assign(dic.size(),INF);
  queue<P> que;
  P start,end;
  for (int i = 0; i < dic.size(); ++i) {
    if(n == dic[i]) start = P(i,n);
    if(m == dic[i]) end = P(i,m);
  }
  que.push(start);
  d[start.first] = -1;

  while(que.size()) {
    P p = que.front(); que.pop();
    if(p.second == m) break;

    for (int i = 0; i < dic.size(); ++i) {
      if(doublets(p.second,dic[i]) && d[i] == INF) {
	que.push(P(i,dic[i]));
	d[i] = p.first;
      }
    }
  }
  if(d[end.first] != INF) print(end.first);
  else cout << "No solution." << endl;
  d.clear();
}

int main() {
  string str;
  while(getline(cin,str) && !str.empty()) dic.push_back(str);
  int i = 0;
  while(cin >> n >> m) {
    if(i++ != 0) cout << endl;
    solve();
  }
  return 0;
}
