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

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  ll N , Z;
  cin >> N >> Z;

  ll ans = 1;
  rep(i,N){
    ll inp; cin >> inp;
    ll a = gcd(inp,Z);
    ll b = gcd(a,ans);
    ll c = a/b;
    ans*=c;
    ans = gcd(ans,Z);

  }
  cout << ans << endl;

  
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
