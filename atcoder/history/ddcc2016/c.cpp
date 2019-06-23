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


ll N , K;
map<ll,ll> ctr;
vector<ll> divisor;

int main(){
  cin >> N >>K;
  rep(i,N){
    ll inp; cin >> inp;
    ctr[__gcd(K,inp)] +=1;
  }

  //‘S–ñ”‚ğì¬‚·‚éB
  FOR(i,1,501){
    if((K%i) == 0) {
      divisor.pb(i);
      divisor.pb(K/i);
    }
  }
  rmsame(divisor);

  /*
  cout << "----" << endl;
  rep(i,divisor.size()){
    cout << divisor[i] << " " << ctr[divisor[i]] << endl;
  }
  cout << "---" << endl;
  */
  
  ll ans = 0;
  rep(i,divisor.size())rep(j,divisor.size()){
    if(((divisor[i]*divisor[j])%K)  !=  0)continue;

    //©•ª©g‚Ì“ñæ
    if(i == j){
      if(ctr[divisor[i]] <=1)continue;
      else {
	ans+= (ctr[divisor[i]] *(ctr[divisor[i]]-1));
	//cout << divisor[i] <<" " << divisor[i] <<" " << ctr[divisor[i]] *(ctr[divisor[i]]-1) << endl;
      }
    }
    
    //©•ª‚Æ‘¼‚ÌŠ|‚¯‡‚í‚¹
    else{
      ans += (ctr[divisor[i]]  *  ctr[divisor[j]]);
      // cout << divisor[i] <<" " << divisor[j] <<" " << ctr[divisor[i]] *ctr[divisor[j]] << endl;
    }
  }

  cout << ans/2 << endl;

  return 0;
}
