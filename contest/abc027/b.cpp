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
ll B[101];

void binary(ll bina){
  for(ll i = 0;i<100;i++){
    B[i] = (bina%2);
    bina /=2;
  }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  ll N ;cin >> N;
  vector<ll> a;
  rep(i,N){
    ll inp; cin >> inp;
    a.pb(inp);
  }
  
  ll sum = 0;
  rep(i,N)sum += a[i];
  
  if((sum % N)!=0) {
    cout << -1 << endl;
    return 0;
  }


  
  ll M = sum/N;
  ll ans = 0;
  ll P  = 0 ;//people
  ll B = 0;//島
  rep(i,N){
    P += a[i];
    B++;
    if((P%B)==0  && (P/B)==M){//人数ちょうどなら、ここで一区切りで
      P=0;
      B=0;
    }
    else {
      ans ++;
    }
  }
  cout << ans << endl;
  return 0;
}
