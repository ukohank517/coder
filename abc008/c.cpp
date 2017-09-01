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
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  vector<pair<ll,ll> > C;
  
  cin >> N;
  rep(i,N) {
    ll inp;
    cin >> inp;
    C.push_back(make_pair(inp,0));
  }
  
  rep(i,N)rep(j,N){
    if(i==j) continue;
    if ((C[j].first%C[i].first)==0)
      C[j].second ++;
    
  }

  ld ans = 0.0;
  rep(i,N){
    if(C[i].second % 2){//奇数
      ans += 0.5;
    }
    else {//偶数
      ld S = (ld)C[i].second; 
      ans += ((S+2)/(2*S+2));
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
   
  
  return 0;
}
