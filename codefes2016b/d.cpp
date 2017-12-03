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
  cin >> N;
  vector<ll> A;
  rep(i,N){
    ll inp; cin >> inp;
    A.pb(inp);
  }
  ll ans = 0;
  ll div = 2;
  if(A[0]!=1)ans += (A[0]-1);
  A[0] = 1;

  rep(i,N){
    if(A[i]==div){
      div++; continue;
    }
    if((A[i]%div)==0) ans += (A[i]/(div+1));
    else ans+=(A[i]/div);
  }

  cout << ans << endl;
  return 0;
}
