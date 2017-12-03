#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
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

ll dp[100002];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N ;
  cin >> N;
  rep(i,N){
    ll inp;
    cin >> inp;
    if(dp > 0)dp[inp-1]++;
    dp[inp]++;
    dp[inp+1]++;
  }

  ll ans = 0;
  rep(i,100002){
    if(dp[i]>ans) ans = dp[i];
  }

  cout << ans << endl;

  
  return 0;
}
