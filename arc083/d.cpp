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


ll road[301][301];
ll cpr[301][301];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  rep(i,301)rep(j,301){
    road[i][j]=10e10;
    cpr[i][j]=10e10;
  }
  
  rep(i,N) rep(j,N){
    cin >> road[i][j];
    cpr[i][j]=road[i][j];
  }

  rep(k,N)rep(i,N)rep(j,N)
    cpr[i][j]=min(cpr[i][j], cpr[i][k]+cpr[k][j]);

  rep(i,N)rep(j,N){
    if(road[i][j]!=cpr[i][j])
      {
	cout << -1 << endl;
	return 0;
      }
  }


  rep(k,N)rep(i,N)rep(j,N){
    if(cpr[i][j]==road[i][k]+road[k][j] && k!=i && k!=j)
      cpr[i][j]=0;
  }

  ll ans = 0;
  rep(i,N){
    rep(j,N){
    ans+=cpr[i][j];
    }
  }
  cout << ans/2 << endl;
  return 0;
}
