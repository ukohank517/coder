#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
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

  ll N,M;
  cin >> N >> M;
  vector<pair<ll,ll> > E;
  map<ll, vector<ll> > G;
  rep(i,M){
    ll a,b; cin >> a >> b;
    a--,b--;
    E.pb(mp(a,b));
    G[a].pb(b);
    G[b].pb(a);
  }

  ll ans = 0;
  rep(i,M){
    //1番目取り除く
    ll a = E[i].first, b = E[i].second;
    G[a].erase(remove(G[a].begin(), G[a].end(),b),G[a].end());
    G[b].erase(remove(G[b].begin(), G[b].end(),a),G[b].end());

    ll used[51]={0};
    stack<int> sta;
    sta.push(1);
    while(!sta.empty()){
      ll vt = sta.top();
      sta.pop();
      if(used[vt]==1)continue;
      used[vt]=1;
      rep(i,G[vt].size())sta.push(G[vt][i]);
    }


    rep(i,N){
      if(used[i]!=1){
	ans++;
	break;
      }      
    }
    
    G[a].pb(b);G[b].pb(a);
  }
  
  cout << ans << endl;

  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
