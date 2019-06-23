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
ll c[10][10];
ll A[300][300];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll H , W; cin >> H >> W;
  rep(i,10)rep(j,10)
    cin >> c[i][j];

  rep(i,H)rep(j,W)
    cin >> A[i][j];


  rep(k,10)rep(i,10)rep(j,10)
    c[i][j] = min(c[i][j], c[i][k]+c[k][j]);

  ll ans = 0;
  rep(i,H)rep(j,W){
    if(A[i][j]==-1) continue;
    ans += c[A[i][j]][1];
  }

  cout << ans << endl;
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
