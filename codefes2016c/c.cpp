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

  ll N;
  vector<ll> T,A;
  vector<pair<ll,ll> > moutainf, moutainb;//hight, possible

  cin >> N;
  rep(i,N){ll inp; cin >> inp; T.pb(inp);}
  rep(i,N){ll inp; cin >> inp; A.pb(inp);}

  rep(i,N){moutainf.pb(mp(0,0));}
  rep(i,N){moutainb.pb(mp(0,0));}
  
  ll before = 0;
  rep(i,N){
    if(T[i]!=before){
      moutainf[i] = mp(T[i],1);
    }
    else{
      moutainf[i] = mp(T[i],T[i]);
    }
    before = T[i];
  }

  before = 0;
  rep(i,N){
    ll j = N-i-1;
    ll hight = A[j];
    if(hight != before){
      moutainb[j] = mp(hight,1);
    }
    else moutainb[j] = mp(hight,hight);
    before = hight;
  }

  ll ans = 1;

  
  
  rep(i,N){
    if(moutainf[i].second!=moutainb[i].second){//可能性が違うけど
      if((moutainf[i].second==1 && moutainf[i].first > moutainb[i].first) || (moutainb[i].second==1 && moutainb[i].first > moutainf[i].first)){
	cout << 0 << endl;
	return 0;
      }
    
      ans *= min(moutainf[i].second, moutainb[i].second);
    }
    else{//可能性が同じ状況で
      if(moutainf[i].second == 1)//どっちも1で
	if(moutainf[i].first != moutainb[i].first){ //可能の結果が違うと言ってたら
	  cout << 0 << endl;
	  return 0;
	}
      ans *= moutainf[i].second;
    }
    ans%=MOD;
  }

  cout << ans << endl;
  
  return 0;
}
