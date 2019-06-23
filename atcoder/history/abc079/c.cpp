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

string itob(int a){
  string ret = "";
  while(a!=0){
    if(a%2 == 1) ret+='1';
    else ret+='0';
    a/=2;
  }

  while(ret.size() <= 2){
    ret+='0';
  }
  reverse(ret.begin(), ret.end());
   return ret;
}

bool cal(string num, string op){
  int ans = num[0]-'0';
  rep(i,3){
    if(op[i]=='1')ans += num[i+1]-'0';
    else ans -= num[i+1]-'0';
  }
  if(ans == 7) return true;
  else
    return false;
}

void outp(string num, string op){
  cout << num[0];
  rep(i,3){
    if(op[i]=='1')cout << '+' << num[i+1];
    else cout << '-' << num[i+1];
  }
  cout << "=7" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string str; cin >> str;

  ll i = 0;
  while (i<= 100){
    string a = itob(i);
    if(cal(str,a)){
      outp(str,a);
      return 0;
    }
 
    i++;
  }
  
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
