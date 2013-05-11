#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > ap;
int nap,n,cases = 1;

void solve() {
  int start;

  nap = 0;
  for (int i = ap.size() - 1; i >= 1; i--) {
    int tmp = ap[i].first - ap[i-1].second;
    if(nap <= tmp) {
      nap = tmp;
      start = ap[i-1].second;
    }
  }
  cout << "Day #" << cases++ << ": the longest nap starts at " << start/60 << ":" << setfill('0') << setw(2) << start%60 << " and will last for ";
  if (nap / 60) cout << nap/60 << " hours and ";
  cout << nap%60 << " minutes." << endl;
}

int main() {
  while(cin >> n) {
    cin.ignore();
    ap.clear();
    ap.push_back(make_pair(10*60,10*60));
    for (int i = 0; i < n; i++) {
      string line;
      getline(cin,line);
      int h1 = 10 * (line[0] - '0') + (line[1] - '0');
      int m1 = 10 * (line[3] - '0') + (line[4] - '0');
      int h2 = 10 * (line[6] - '0') + (line[7] - '0'); 
      int m2 = 10 * (line[9] - '0') + (line[10] - '0');
      ap.push_back(make_pair(h1*60+m1,h2*60+m2));
    }
    ap.push_back(make_pair(18*60,18*60));
    sort(ap.begin(),ap.end());
    solve();
  }
}

