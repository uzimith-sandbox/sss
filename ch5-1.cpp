#include <iostream>
using namespace std;

unsigned long n,c,rev;

unsigned long reverse(unsigned long a) {
  unsigned long res = 0;
  while(a) {
    res = res*10 + a % 10;
    a = a/10;
  }
  return res;
}

void solve() {
  for(c = 0;;c++) {
    rev = reverse(n);
    if(n == rev) break;
    n = n + rev;
  }
  cout << c << " " << n << endl;
}

int main(int argc, char *argv[])
{
  int cases;
  cin >> cases;
  while (cases--) {
    cin >> n;
    solve();
  }
  return 0;
}
