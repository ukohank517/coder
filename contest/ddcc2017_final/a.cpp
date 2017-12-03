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

ll calodd(ld rad, ld tip){
  ll ans = 0;
  for(ld i =0;i<100;i+=1.0L){
    if((i*tip+tip/2.0)>=(rad/2.0)) break;
    ld line = sqrt((rad/2.0)*(rad/2.0) - (tip/2.0+i*tip)*(tip/2.0+i*tip))-tip/2.0;
    ll m = (line/tip);m*=2;m++;

    
    ans += m;
    if(i!=0) ans += m;

  }

  return ans;
}

ll caleven(ld rad, ld tip){
  ll ans = 0;
  for(ld i = 0;i<100;i+=1.0L){
    if(((i+1.0L)*tip)>=(rad/2.0)) break;
    ld line = sqrt((rad/2.0)*(rad/2.0) - (i*tip)*(i*tip)) - tip/2.0;
    ll m = (line/tip);
    m*=4;
    ans += m;

  }
  return ans;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ld k ; cin >> k;

  ll K = k;
  ll ans2,ans3;
  if((200/K)%2 != 0) ans2 = calodd(200,k);
  else ans2 = caleven(200,k);

  if((300/K)%2 != 0) ans3 = calodd(300,k);
  else ans3 = caleven(300,k);

  cout << ans2 << " " << ans3 << endl;
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
