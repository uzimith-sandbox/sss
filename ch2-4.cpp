#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef vector<int> round;
int const rounds = 13;
int const categories = 13;
int const dices = 5;

bool round_cmp(const round& a,const round& b) {
  if(b.empty()) return true;
  return a[a.size()-1] > b[b.size()-1];
};

int sum(const round& r, int dice){
  return dice * count(r.begin(),r.end(),dice);
}

int chance(const round& r) {
  return accumulate(r.begin(),r.end(),0);
}

int kind(round& r,int num) {
  round::iterator i = r.begin();
  int n = 1;
  while(i+1 != r.end()) {
    if(*i == *(++i)) n++;
    else n = 1;
    if(n == num) return accumulate(r.begin(),r.end(),0);
  }
  return 0;
}

int straight(round& r,int num) {
  round::iterator i = r.begin();
  int n = 1;
  while(i+1 != r.end()) {
    if(*i == *(++i)) n++;
    else n = 1;
    if(n == num) return (num == 4) ? 25:35;
  }
  return 0;  
}

int full_hause(round& r) {
  if((r[0] == r[1] && r[3] == r[4]) && (r[1] == r[2] || r[2] == r[3]) && r[0] != r[4]) return 40;
  else return 0;
}


void score(vector<round>& game) {
  vector<int> comb;
  round max;
  for(int i = 0; i < rounds; i++) {
    comb.push_back(i);
  }

  do{
    round result(13,0);
    for (int i = 0; i < rounds; i++) result[comb[i]] = game[i][comb[i]];
    if(accumulate(&result[0],&result[5],0) >= 63) result.push_back(35);
    else result.push_back(0);
    result.push_back(accumulate(result.begin(),result.end(),0));
    if(round_cmp(result,max)) {
      max = result;
    }
  }while(next_permutation(comb.begin(),comb.end()));

  for (int i = 0; i < max.size(); i++) {
    cout << max[i];
    if(i != max.size()-1) cout << " ";
  }
  cout << endl;
}

int calc(round& r,int i) {
  switch(i) {
  case 0: return sum(r,1); break;
  case 1: return sum(r,2); break;
  case 2: return sum(r,3); break;
  case 3: return sum(r,4); break;
  case 4: return sum(r,5); break;
  case 5: return sum(r,5); break;
  case 6: return chance(r); break;
  case 7: return kind(r,3); break;
  case 8: return kind(r,4); break;
  case 9: return kind(r,5); break;
  case 10: return straight(r,4); break;
  case 11: return straight(r,5); break;
  case 12: return full_hause(r); break;
  }
}

int main(int argc, char *argv[])
{
  ios::sync_with_stdio(false); 
  int nd;
  vector< vector<round> > point_table;
  vector<round> game;
  round r,point;

  int i = 1;
  int cases = 0;
  while(cin >> nd) {
    r.push_back(nd);
    if(i % dices == 0 && i != 0) {
      sort(r.begin(),r.end());
      for(int c = 0; c < categories; c++) point.push_back(calc(r,c));
      game.push_back(point);
      r.clear();
      point.clear();
    }
    if(i % (dices * rounds) == 0) {
      cases++;
      point_table.push_back(game);
      game.clear();
    }
    i++;
  }
  for(int n = 0; n < cases; n++) {
    score(point_table[n]);
  }
}
