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

ll cal(ll line, ll tip){
  ll s = line/tip;
  ll ans = 0;
  ll rad = line*line;

  
  rep(i,s)rep(j,s){
    ll a = (line-i*tip)*(line-i*tip) + (line-j*tip)*(line-j*tip);
    ll b = (line-i*tip)*(line-i*tip) + (line-(j+1)*tip)*(line-(j+1)*tip);
    ll c = (line-(i+1)*tip)*(line-(i+1)*tip) + (line-j*tip)*(line-j*tip);
    ll d = (line-(i+1)*tip)*(line-(i+1)*tip) + (line-(j+1)*tip)*(line-(j+1)*tip);
    if((a<=rad)&&(b<=rad)&&(c<=rad)&&(d<=rad))ans ++;
  }
  

  return ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  cout << cal(200/2,N) <<" " << cal(300/2,N) << endl;

  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
