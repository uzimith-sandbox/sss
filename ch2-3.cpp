#include <iostream>
#include <vector>
using namespace std;

int deck[52];
vector< vector<int> > methods;

void shuffle(int index) {
  int temp_deck[52];
  for(int i = 0; i < 52; ++i) temp_deck[i] = deck[methods[index][i]];
  for(int i = 0; i < 52; ++i) deck[i] = temp_deck[i];
}

int main(int argc, char *argv[])
{
  string values[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
  string suits[] = {"Clubs","Diamonds","Hearts","Spades"};
  int cases;
  cin >> cases;
  while(cases--) {
    for (int i = 0; i < 4*13; ++i) deck[i] = i;
    int number_of_shuffle;
    cin >> number_of_shuffle;
    int read;
    vector<int> sh;
    for (int i = 0; i < number_of_shuffle ;i++ ) {
      sh.clear();
      for(int j = 0; j < 52; j++) {
	cin >> read;
	sh.push_back(--read);
      }
      methods.push_back(sh);
    }
    for(int i = 0; i < number_of_shuffle; i++) {
      cin >> read;
      shuffle(--read);
    }
    for (int i = 0; i < 52; ++i) cout << values[deck[i] % 13] << " of " << suits[deck[i] / 13] << endl;
    if(cases != 0) cout << endl;
    methods.clear();
  }
}
