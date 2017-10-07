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

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}



map<ll,ll> A;
ll N,K;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  rep(i,N){
    ll inp; cin >> inp;
    A[gcd(K,inp)]++;//その最大公約数の数を更新
  }

  vector<ll> divisor;
  FOR(i,1,500){//500*500=250,000 > 200,000
    if((K%i)==0){
      divisor.pb(i);
      divisor.pb(K/i);
    }
  }
  rmsame(divisor);

  cout << "----" << endl; 
  rep(i,divisor.size())
    cout << divisor[i] <<" " << A[divisor[i]]<< endl;
  cout << "----" << endl;
  
  ll ans = 0;
  rep(i,divisor.size())rep(j,divisor.size()){
    if((divisor[i]*divisor[j])%K == 0){
      if(divisor[i]==divisor[j]){
	if (A[divisor[i]]<=1)continue; 
	else {
	  //cout << "aa" << endl;
	  ans += (A[divisor[i]]*(A[divisor[i]]-1));
	  continue;
	}
      }
      //自分と他人の掛け合わせ。
      else{
	ans += (A[divisor[i]]*A[divisor[j]]);
      }
	
    }
  }

  cout << ans/2 << endl;
  return 0;
}
