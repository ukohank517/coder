#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long

int main(){
  ll N;
  cin >> N;


  ll A = N/5;
  ll B = N%5;

  vector<ll> card;
  for(ll i =0;i<6;i++){
    card.push_back((A+i)%6+1);
  }
  for(ll i =0;i< B;i++){
    swap(card[i],card[i+1]);
  }

  for(ll i =0;i<6;i++)cout << card[i];

  cout << endl;
  return 0;
}
