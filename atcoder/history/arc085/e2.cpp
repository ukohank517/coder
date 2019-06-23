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
ll price[110];
ll N;
vector<ll>a;

void reset(){
  for(ll i = 1;i<=N;i++)
    price[i]=0;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector<ll>a;
  a.pb(0);
  rep(i,N){
    ll inp ; cin >> inp;
    a.pb(inp);
  }

  while(true){
    reset();
    ll loss =0;
    ll lossindex;
    for(ll i = 1;i<= N;i++){
      for(ll j = 1;(j*i)<= N ;j++){
	price[i]+=a[i*j];
      }
      if(price[i]<0){loss = price[i];lossindex = i;}
    }
    if(loss == 0) break;
    for(ll i = 1;(i*lossindex) <= N ;i++)
      a[i*lossindex]=0;
    
  }
  ll ans = 0;
  for(ll i = 1;i<=N;i++)
    ans += a[i];

  cout << ans << endl;
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
