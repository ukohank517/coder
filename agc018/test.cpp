#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  vector <pair<ll,ll> > a;

  pair<ll, ll >inp;
  for(ll i =0;i < 10 ;i++){
    cin >> inp.first ;
    inp.second = i;
    a.push_back(inp);
  }
  for(ll i =0;i < 10 ;i++){
    cout << a[i].first << " " << a[i].second<< endl;
  }

  return 0;
}
