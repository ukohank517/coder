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

ll N,K;
  
vector<string>a;
vector<ll> b;

string toBit(ll inp){
  string ans = "";
   rep(i,31){
    if(inp%2 == 1) ans += '1';
    else ans += '0';
    inp/=2;
  }

  for(ll l = 0, r = ans.size()-1; l<r;l++,r--)
    swap(ans[l], ans[r]);
  return ans;
}

bool judge(string str, string a){
  rep(i,31){
    if(str[i]==a[i])
      continue;
    else if((str[i]=='1')&&(a[i]=='0'))
      continue;
    else return false;
  }
  return true;
}

ll solve(ll k){
  ll ans = 0;
  string str = toBit(k);
  rep(i,N)
    if(judge(str,a[i])) ans += b[i];
  
  return ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  

  cin >> N >> K;
  
  rep(i,N){
    ll ai,bi;
    string s;
    cin >> ai >> bi;

    a.pb(toBit(ai));
    b.pb(bi);   
  }

  ll ans = 0 ;
  while (K!=0){
    ans = max(ans,solve(K));
    K = K>>1;
  }
  cout << ans << endl;
  
  return 0;
}
