#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
  string s;
  stringstream ss;
  int read,n;
  vector<int> array;
  set<int> diff;
  while(getline(cin,s)) {
    ss.str(s);
    ss >> n;
    while(ss >> read) array.push_back(read);
    for(unsigned int i = 1; i < array.size(); ++i ) diff.insert(abs(array[i] - array[i-1]));
    if(n == 1 || (*diff.begin() == 1 && *diff.rbegin() == n-1 && diff.size() == n-1)) {
      cout << "Jolly" << endl;
    } else {
      cout << "Not jolly" << endl;
    }
    ss.clear();
    array.clear();
    diff.clear();
  }
}
