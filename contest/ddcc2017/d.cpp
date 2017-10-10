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
 
char m[500][500];
ll H,W,A,B;
 
ll AB(){
  //A+B
  ll ans = 0;
  for(ll i = 1;i<=(H+1)/2;i++){
    for(ll j = 1; j<= (W+1)/2;j++){
      if(m[i][j]=='S'&&m[H+1-i][j]=='S' && m[i][W+1-j]=='S' && m[H+1-i][W+1-j]=='S'){
	ans += ((A+B)+max(A,B));
	m[i][j]=m[H+1-i][j]=m[i][W+1-j]=m[H+1-i][W+1-j]='.';
      }
    }
  }
  return ans;
}
 
ll PA(){
  ll ans = 0;
  for(ll i =1;i<=(H+1)/2;i++){
    for(ll j = 1;j<=W;j++){
      if(m[i][j]=='S'&&m[H+1-i][j]=='S'){
	ans += A;
	//m[i][j]=m[H+1-i][j] ='.';
      }
      
    }
  }
  return ans;
}
 
ll PB(){
  ll ans = 0;
  for(ll i =1;i<=H;i++){
    for(ll j = 1;j<=(W+1)/2;j++){
      if(m[i][j]=='S'&&m[i][W+1-j]=='S'){
	ans += B;
	//m[i][j]=m[i][W+1-j] ='.';
      }
    }
  }
  return ans;
}
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  cin >> H >> W >> A >> B;
 
  rep(i,H){
    string inp;
    cin >> inp;
    rep(j,W)
      m[i+1][j+1] = inp[j];
  }
  
  ll ans = A+B;//最後の状態
  ans += AB();
  //if(A>B){ans += PA();ans += PB();}
  //else{ans += PB(); ans += PA();}
  // cout << ans <<  " "  << minus << endl;
  ans += max(PA(),PB());
 
 
 
 
  vector<pair<ll,ll> > S;
  for(ll i =1;i<=H;i++){
    for(ll j = 1;j<=W;j++){
      if(m[i][j]=='S')
	S.pb(mp(i,j));
    }
  }
 
  ll minus = A+B;
  rep(i,S.size()){
    if(m[S[i].first][S[i].second] =='S' && m[H+1-S[i].first][S[i].second]!='S'){
      minus -= A;
      break;
    }
  }
 
  rep(i,S.size()){
    if(m[S[i].first][S[i].second] == 'S' && m[S[i].first][W+1-S[i].second] != 'S'){
      minus -= B;
      break;
    }
  }
 
 
 
  
  cout << ans - minus << endl;
  return 0;
}#include <iostream>
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
 
char m[500][500];
ll H,W,A,B;
 
ll AB(){
  //A+B
  ll ans = 0;
  for(ll i = 1;i<=(H+1)/2;i++){
    for(ll j = 1; j<= (W+1)/2;j++){
      if(m[i][j]=='S'&&m[H+1-i][j]=='S' && m[i][W+1-j]=='S' && m[H+1-i][W+1-j]=='S'){
	ans += ((A+B)+max(A,B));
	m[i][j]=m[H+1-i][j]=m[i][W+1-j]=m[H+1-i][W+1-j]='.';
      }
    }
  }
  return ans;
}
 
ll PA(){
  ll ans = 0;
  for(ll i =1;i<=(H+1)/2;i++){
    for(ll j = 1;j<=W;j++){
      if(m[i][j]=='S'&&m[H+1-i][j]=='S'){
	ans += A;
	//m[i][j]=m[H+1-i][j] ='.';
      }
      
    }
  }
  return ans;
}
 
ll PB(){
  ll ans = 0;
  for(ll i =1;i<=H;i++){
    for(ll j = 1;j<=(W+1)/2;j++){
      if(m[i][j]=='S'&&m[i][W+1-j]=='S'){
	ans += B;
	//m[i][j]=m[i][W+1-j] ='.';
      }
    }
  }
  return ans;
}
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  cin >> H >> W >> A >> B;
 
  rep(i,H){
    string inp;
    cin >> inp;
    rep(j,W)
      m[i+1][j+1] = inp[j];
  }
  
  ll ans = A+B;//最後の状態
  ans += AB();
  //if(A>B){ans += PA();ans += PB();}
  //else{ans += PB(); ans += PA();}
  // cout << ans <<  " "  << minus << endl;
  ans += max(PA(),PB());
 
 
 
 
  vector<pair<ll,ll> > S;
  for(ll i =1;i<=H;i++){
    for(ll j = 1;j<=W;j++){
      if(m[i][j]=='S')
	S.pb(mp(i,j));
    }
  }
 
  ll minus = A+B;
  rep(i,S.size()){
    if(m[S[i].first][S[i].second] =='S' && m[H+1-S[i].first][S[i].second]!='S'){
      minus -= A;
      break;
    }
  }
 
  rep(i,S.size()){
    if(m[S[i].first][S[i].second] == 'S' && m[S[i].first][W+1-S[i].second] != 'S'){
      minus -= B;
      break;
    }
  }
 
 
 
  
  cout << ans - minus << endl;
  return 0;
}
