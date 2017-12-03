#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
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

ll N,M;
map<ll,vector<ll> > G;
ll num[100010];
vector<ll> three;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;  
  rep(i,M){
    ll a,b;
    cin >> a >> b;
    G[a].pb(b);
    G[b].pb(a);
    num[a]++;
    num[b]++;
    if(num[a]>=3)three.pb(a);
    if(num[b]>=3)three.pb(b);
  }

  rmsame(three);
  bool flag = false;

  rep(i,three.size()){
    ll check = three[i];
    rep(j,G[check].size()){
      ll a = G[check][j];
      if(G[a].size()>=2){
	flag = true;
      }
    }
  }

  ll minu = 0;
  ll odd = N/2, even = N/2;
  if(N%2) odd++;

  minu = (odd*(odd-1)/2)+(even*(even-1)/2);
  //cout << "final" << endl;
  cout << (N*(N-1)/2)-minu-M << endl;
  //cout << fixed << setprecision(16) << ans << endl;

  
  if(M>=N){//三角存在する//できる
    cout << (N*(N-1)/2)-M << endl;
    return 0;
  }

  if(three.size()==1) {
    cout << "0" << endl;
    return 0;
  }
  
  
  return 0;
}
