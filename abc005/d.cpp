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

ll D[51][51]={{0}};
ll dp[2501]={0};
ll N,Q;
vector<ll> P;


ll check(ll x1, ll y1, ll x2, ll y2){
  ll sum = 0;
  for(ll i =x1;i<=x2;i++){
    for(ll j = y1;j<=y2;j++){
      sum += D[i][j];
    }
  }
  return sum;
}

int main(){
  ll inp;

  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  for(ll i =1;i<=N;i++){
    for(ll j =1;j<=N;j++){
      cin >> D[i][j];
    }
  }
  cin >> Q;
  for(ll i =0;i<Q;i++){
    cin >> inp;
    P.push_back(inp);
  }

for(ll i =1;i<=2500;i++){
  if(i>N*N) break;
  ll size = i;
  ll Max=0;
  for(ll h =size; h>0;h--){
    if(size%h) continue;//割り切れない
    ll w = size/h;
    ll big = 0;
    ll result = 0;
    //h,wの長方形の美味しさをそれぞれ調べて、その中から一番美味しいbigを返す
    for(ll m=1;m<=(N-h+1);m++){
      for(ll n =1;n<=(N-w+1);n++){
        result = check(m,n, m+h-1,n+w-1);
        big = max(result, big);
      }
    }
    Max = max(big, Max);
  }
  dp[i] = Max;
}
  for(ll i =1;i<=N*N;i++){
    if(dp[i]<dp[i-1]) dp[i] = dp[i-1];
  }

  for(ll i =0;i<Q;i++){
    cout << dp[P[i]] << endl;
  }
  return 0;
}
