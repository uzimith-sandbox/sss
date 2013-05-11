#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int s[501];

int distance(int mid) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += abs(s[i] - s[mid]);
  }
  return res;
}

void solve() {
  sort(s,s+n);
  int sum;
  if(n%2 == 0) {
    sum = min(distance(n/2),distance(n/2+1));
  } else {
    sum = distance(n/2);
  }
  cout << sum << endl;
}

int main() {
  int cases;
  cin >> cases;

  while(cases--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    solve();
  }
}

