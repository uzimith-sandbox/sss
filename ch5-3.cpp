#include <iostream>
#include <cmath>

using namespace std;

unsigned long n;

void solve() {
  unsigned long N = 1;
  int c = 1;
  while(N != 0) {
    if(N < n) {
      N = N*10+1;
      c++;
    }
    N %= n;
    if(N == 0) break;
  }

  cout << c << endl;
}

int main(int argc, char *argv[])
{
  while (cin >> n) {
    solve();
  }

  return 0;
}
