#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007
#define ll long long

using namespace std;

struct ABC{
  ll a,b,c;
};

bool comp(pair<ll,ABC> lhs, pair<ll,ABC> rhs) {
    return lhs.first > rhs.first;
}

int main(){
  ll X, Y , Z, N;
  pair<ll,ABC> inp;
  vector<pair<ll,ABC> > coin;
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> X >> Y >> Z;
  N = X+Y+Z;
  for(ll i = 0;i < N; i++){
    cin >> inp.second.a >> inp.second.b >> inp.second.c;
    inp.first = inp.second.a-inp.second.b;
    coin.push_back(inp);
  }

  sort(coin.begin(), coin.end(),
       [] (const pair<ll,ABC> a, const pair<ll,ABC> b)  {
	 return a.first < b.first;
       });
  
  for(ll i = 0;i< N;i++){
    cout << coin[i].first << " " <<coin[i].second.a <<" " << coin[i].second.b<<" "  << coin[i].second.c <<endl;
  }
  
  return 0;
}
