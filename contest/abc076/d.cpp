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

  ll N ; cin >> N;
  vector<ld>t,limv;
  rep(i,N){
    ll inp; cin >> inp;
    t.pb(inp);
  }
  rep(i,N){
    ll inp; cin >> inp;
    limv.pb(inp);
  }
  

  vector<ld>v;
  //まずはvの初期値を入れる
  v.pb(0);
  for(ll i=0 ; i<N-1 ; i++){
    ld lim = min(limv[i], limv[i+1]);
    v.pb(lim);
  }
  v.pb(0);

  //次は左から順に見て行く。
  for(ll i = 0 ; i<v.size()-1 ; i++){
    if(v[i+1]>v[i])v[i+1] = min(v[i+1], v[i]+t[i]);
  }
  //次は右から順に見て行く。
  for(ll i =v.size()-1 ; i>=1 ; i--){
    if(v[i-1]>v[i])v[i-1] = min(v[i-1], v[i]+t[i-1]);
  }


  ld ans = 0.0;
  //両サイドの速度、その空間の制限速度より、そこの面積を出せる。
  //v[i]とv[i+1], limv[i]で囲む面積
  for(ll i = 0;i<v.size()-1;i++){
    ld l = v[i], r = v[i+1], lim = limv[i];

    if(l>r) swap(l,r);
    if(lim == r)
      ans += (l+(l+t[i]))*t[i]*0.5 - (l+t[i]-r)*(l+t[i]-r)*0.5;
    else{
      ld x = 0.5*(t[i]+r-l);
      ld y = 0.5*(t[i]-r+l);
      ld top = l+x-limv[i];
      if(top<0)top = 0;
      x -=top, y-=top;
      top*=2;
      
      if(top>0)	ans += ( (l+ l+x )*x*0.5 + (r+y + r)*y*0.5 + top*limv[i] ) ;
      
      else ans += ( (l+ l+x )*x*0.5 + (r+y + r)*y*0.5 );
      
      
    }
  }

  cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
