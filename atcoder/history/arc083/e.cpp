#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}

int dp[310]={1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  ll N,A;
  cin >> N >> A;
  vector<ll> x;

  rep(i,N){
    ll inp; cin >> inp;
    x.pb(inp);
  }
  
  rep(i,260){
    if(dp[i]!=0)
      rep(j,N){
	dp[i+x[i]]+=dp[i];
      }
  }


  
  for(ll i=0;i<=250;i+=A){
    cout << dp[i] << endl;
  }
  return 0;
}
