#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<string> grid;
string q;

int dx[] = {1,0,1,-1,0,-1,-1,1};
int dy[] = {0,1,1,0,-1,-1,1,-1};
bool dfs(int pos,int x,int y,int direction) {
  if(pos == q.size()) return true;
  if(0 <= x && x<n && 0 <= y && y < m && grid[x][y] == q[pos]) {
    if(direction == -1) {
      for(int i = 0; i < 8; i++) if(dfs(pos+1,x+dx[i],y+dy[i],i)) return true;
    } else {
      if(dfs(pos+1,x+dx[direction],y+dy[direction],direction)) return true;
    }
  }
  return false;
}
void solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if(dfs(0,i,j,-1)) {
	cout << ++i << " " << ++j << endl;
	return;
      }
    }
  }
}

int main(int argc, char *argv[])
{
  int cases;
  cin >> cases;
  while(cases--) {
    cin >> n >> m;
    string read;
    for (int i = 0; i < n; ++i) {
      cin >> read;
      transform (read.begin(), read.end(), read.begin(), ::tolower);
      grid.push_back(read);
    }
    int a;
    cin.ignore();
    cin >> a;
    for (int i = 0; i < a; ++i) {
      cin >> q;
      transform (q.begin(), q.end(), q.begin(), ::tolower);
      solve();
    }
    if(cases != 0) cout << endl;
    grid.clear();
  }
  return 0;
}

