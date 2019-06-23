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

ll mine[51][51];
char ch[51][51];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll H,W;
  cin >> H >> W;
  rep(i,H){
    string a; cin >> a;
    rep(j,a.size()){
      ch[i][j]=a[j];
    }
  }
  rep(i,H)rep(j,W){
    if(ch[i][j]=='#') {
      mine[i][j]=100;
      FOR(m,-1,2)FOR(n,-1,2){
	if(i+m<0)continue;
	if(j+n<0)continue;
	if(i+m > 50) continue;
	if(j+n>50)continue;
	mine[i+m][j+n]++;
      }
    }
    
  }

  rep(i,H){
    rep(j,W){
      if(mine[i][j]>90)cout << '#' ;
      else cout << mine[i][j] ;
    }
    cout << endl;
  }
  

  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
