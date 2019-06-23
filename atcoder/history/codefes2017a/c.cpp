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
//template<class T = ll> T in(){T x; cin >> x; return (x);}

ll num[26];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll H, W;
  cin >> H >> W;

  ll two=0, four=0, el=0;
  
  rep(i,H){
    string s ;cin >> s;
    rep(j,s.size()) num[s[j]-'a']++;
  }


  rep(i,26){
    if(num[i]==0) continue;
    four += (num[i]/4);num[i]%=4;
    two +=(num[i]/2); num[i] %= 2;
    el += num[i];
  }

  if(H==1 || W==1){
    if(el <= 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }

  ll f=0,t=0,e=0;
  t = (H%2)*(W/2) + (W%2)*(H/2);
  f = (H*W-2*t)/4;
  e = H*W-f*4-t*2;

  
  if(four < f) {
    cout << "No" << endl;
    return 0;
  }
  two += ((four-f)*2);
  
  
  if(two==t && el == e) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
