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
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}

ll N;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector<ll> a;
  a.pb(0);//index0潰し
  rep(i,N){
    ll inp; cin >> inp;
    a.pb(inp);
  }

  
  while(true){
 

    ll lossindex= 1000;
    for(int i = N;i>=1;i--){
      ll price = 0;
      for(int j = 1;(i*j)<= N;j++){
	price += a[i*j];
      }
      if(price<0){lossindex = i;break;}
    }
    if(lossindex==1000) break;


    for(ll i = 1;i*lossindex <= N;i++)
      a[i*lossindex]=0;
  }
 
  ll ans = 0;
  for(ll i = 1; i<= N ;i++)
    ans += a[i] ;
  cout << ans << endl;
  
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
