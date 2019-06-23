#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>

#define MOD 1000000007
#define ll long long
#define ld long double

using namespace std;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;cin >> N;
  vector<ll> c;
  ll m=0;
  for(ll i =0;i< N;i++){
    ll inp;
    cin >> inp;
    c.push_back(inp);
  }

  vector<ll> dp;
  dp.push_back(c[0]);
  for(ll i =1;i<N;i++){
    if(c[i]>dp[dp.size()-1])
      dp.push_back(c[i]);
    else *lower_bound(dp.begin(), dp.end(),c[i])=c[i];
  }
  cout << N-dp.size() << endl;
  return 0;
}
