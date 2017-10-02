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

//以下の解き方があまりよくないと思い、変更します。
/*
ll A;
string S;
vector<ll> s;

void solve(){

  rep(i,s.size()-1){
    if((s[i]+A)<=26 && (s[i+1]-1)>=0){
      s[i]+=A;
      s[i+1]--;
    }
  }
  
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> A >> S;
  
  rep(i,S.size()){
    s.pb(S[i]-'a'+1);
  }


  rep(i,3*s.size())//ここの書き方があまりよくない。
    solve();

  rep(i,s.size()){
    if(s[i]==0) break;
    cout << (char)(s[i]+'a'-1);
  }
  cout << endl;
}
*/

