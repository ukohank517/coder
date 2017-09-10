#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
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

ll N, M, R;
vector<ll> r;
ll road[201][201];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M >> R;
  rep(i,R){ll inp; cin >> inp; r.pb(inp);}

  rep(i,201)rep(j,201)
    road[i][j]=1e9;

  rep(i,M){
    ll a,b,c; cin >> a >> b >> c;
    road[a][b]=c;
    road[b][a]=c;
  }

  rep(k,N+1)rep(i,N+1)rep(j,N+1)
    road[i][j]=min(road[i][j], road[i][k]+road[k][j]);


  
  ll ans = 1e9;
  sort(all(r));
  
  //ll times = 1;FOR(i,1,R+1)times*=i;
  do{
    ll sum=0;
    rep(j,r.size()-1){
      sum+=road[r[j]][r[j+1]];
    }
    ans = min(ans,sum);
  }while( next_permutation(all(r)) );
  

  cout << ans << endl;
  
  
  return 0;
}
