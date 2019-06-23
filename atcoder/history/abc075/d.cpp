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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,K;
  cin >> N >> K;
  vector<pair<ll,ll> > xy;
  vector<ll> x,y;
  rep(i,N){
    ll a,b;
    cin >> a >> b;
    xy.pb(mp(a,b));
    x.pb(a),y.pb(b);
  }
  
  sort(all(x));
  sort(all(y));


  ll ans = 5000000000000000000;
  //x:i<j
  //y:k<l
  rep(i,x.size())FOR(j,i+1,x.size())rep(k,y.size())FOR(l,k+1,y.size()){
    ll num = 0;
    rep(a,xy.size()){
      if(x[i]<=xy[a].first && xy[a].first<= x[j] && y[k]<=xy[a].second && xy[a].second<=y[l])num++;
    }

    if(num>=K){
      ans = min(ans,(x[j]-x[i])*(y[l]-y[k]));
    }
  }

  cout << ans << endl;;
  
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
