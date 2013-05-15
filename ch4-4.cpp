#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

struct record {
  string status;
  int month,day,hour,minute,location;
  bool operator<(const record x) const {
    if(day < x.day) return true;
    if(day > x.day) return false;
    if(hour < x.hour) return true;
    if(hour > x.hour) return false;
    if(minute < x.minute) return true;
    if(minute > x.minute) return false;
    return true;
  };
};

int fare[24];
map<string,vector<record> > records;

void solve() {
  map<string,vector<record> >::iterator car = records.begin();
  for(;car != records.end();car++) {
    sort((*car).second.begin(),(*car).second.end());
    int cost = 200;
    vector<record> v = (*car).second;
    for (int i = 1; i < v.size(); i++)
      if(v[i].status == "exit" && (v[i-1].status == "enter"))
	 cost += 100 + fare[v[i-1].hour]*(abs(v[i].location - v[i-1].location));
    if(cost > 200)
      cout << (*car).first << " " << "$" << fixed << setprecision(2) << cost / 100.0 << endl;
  }
}

int main()
{
  int cases;

  cin >> cases;
  cin.ignore(); cin.ignore();
  while(cases--) {
    for (int i = 0; i < 24; i++) cin >> fare[i];
    cin.ignore();
    string line;
    while(getline(cin,line)) {
      if(line.empty()) break;
      record r;
      string license;
      stringstream ss;
      ss.str(line);
      char space;
      ss >> license >> r.month >> space >>
	r.day >> space >> r.hour >> space >> r.minute >> r.status >> r.location;
      records[license].push_back(r);
    }
    solve();
    records.clear();
    if(cases) cout << endl;
  }
  return 0;
}
