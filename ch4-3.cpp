#include <iostream>
#include <algorithm>

using namespace std;

struct task {
  int time,fine,n;
  bool operator<(const task x) const {
    float f1 = (float)fine / time;
    float f2 = (float)x.fine / x.time;
    return f1 > f2;
  }
} t[1000];

int main() {
  int cases;
  cin >> cases;
  cin.ignore(); cin.ignore();
  while(cases--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> t[i].time >> t[i].fine;
      t[i].n = i+1;
    }
    sort(t,t+n);
    for (int i = 0; i < n; i++) {
      if(i != n-1) cout << t[i].n << " ";
      else cout << t[i].n << endl;
    }
    if(cases != 0) cout << endl;
  }
}

