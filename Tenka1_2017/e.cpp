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


ld x,y;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ld N ;
  cin >> N;
  vector<ld> A,B,C;
  
  rep(i,N){
    ld a,b,c; cin >> a >> b >> c;
    A.pb(a); B.pb(b); C.pb(c);
  }
  A.pb(0),B.pb(1),C.pb(0);
  A.pb(1),B.pb(0),C.pb(0);
  
  rep(i,N+2){
    FOR(j,i+1,N+2){
      x+=(C[i]*B[j] - C[j]*B[i])/(A[i]*B[j]-A[j]*B[i]);
      y+=(A[j]*C[i] - A[i]*C[j])/(A[j]*B[i]-A[i]*B[j]);
    }
  }

  cout << fixed;
  cout << setprecision(15) << x/(N+2) << " " << y/(N+2) << endl;
  return 0;
}
