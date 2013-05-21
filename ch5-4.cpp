#include <iostream>
using namespace std;

unsigned long n;

void solve() {
  int i;
  for (i = 1; ; i++) {
    if(i%2 == 1) n = (n+8)/9;
    else n = (n+1) / 2;
    if(n <= 1) break;
  }
  if(i % 2 == 0) cout << "Ollie wins." << endl;
  else cout << "Stan wins." << endl;
}

int main(int argc, char *argv[])
{
  while (cin >> n) {
    solve();
  }

  return 0;
}
