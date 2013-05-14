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

ostream& operator<<(ostream& os,record const& r) {
os << r.month << ":" << r.day << ":" << r.hour << ":" << r.minute << " " << r.status << r.location;
  return os;
};

struct bill {
  string license;
  int cost;
};

int fare[24];
map<string,vector<record> > records;
vector<bill> bills;

void solve() {
  map<string,vector<record> >::iterator car = records.begin();
  while(car != records.end()) {
    bill b;
    b.license = (*car).first;
    b.cost = 0;
    vector<record> v = (*car).second;
    sort(v.begin(),v.end());
    bool entered = false;
    record start;
    vector<record>::iterator ite = v.begin();
    while(ite != v.end()) {
      if(!entered) {
	if((*ite).status == "enter") {
	  start = (*ite);
	  entered = true;
	}
      } else {
    	if((*ite).status == "exit") {
	  b.cost += 100 + fare[start.hour]*(abs((*ite).location - start.location));
	  entered = false;
	}
      }
      ite++;
    }
    if(b.cost > 100) {
      b.cost += 200;
      bills.push_back(b);
    }
    car++;
  }

  for (int i = 0; i < bills.size(); i++) cout << bills[i].license << " " << "$" << fixed << setprecision(2) << bills[i].cost / 100.0 << endl;
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
    map<string,vector<record> >::iterator car = records.begin();
    solve();
    records.clear();
    bills.clear();
    if(cases != 0) cout << endl;
  }
  return 0;
}
