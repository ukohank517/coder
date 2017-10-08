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
  ll ans=0;
  for(ll i=1; i<=W/2; i++){
    for(ll j=1; j<=H/2; j++){
      if(m[i][j]=='S' && m[H+1-i][j]=='S' && m[i][W+1-j]=='S' && m[H+1-i][W+1-j]=='S'){
	ans +=((A+B)+max(A,B));
	
	m[i][j]='.';
	m[H+1-i][j]='.';
	m[i][W+1-j]='.';
	m[H+1-i][W+1-j]='.';
	
      }
    }
  }

  return ans;
}

ll PB(){
  ll ans = 0;
  for(ll i=1; i<=W; i++){
    for(ll j = 1;j<=H/2;j++){
      if(m[i][j]=='S' && m[i][W+1-j]=='S'){
	
	m[i][j] = '.';
	m[i][W+1-j]='.';
	
	ans += B;
      }
    }
  }
  return ans;
}
ll PA(){
  ll ans = 0;
  for(ll i=1; i<=W/2; i++){
    for(ll j = 1;j<=H;j++){
      if(m[i][j]=='S' && m[H+1-i][j]=='S'){
	
	  m[i][j] = '.';
	  m[H+1-i][j]='.';
	
	ans += A;
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

  ll ans=(A+B);//最後の空白

  vector<pair<ll,ll> > S;
  for(ll i=1; i<=W; i++){
    for(ll j = 1;j<=H;j++){
      if(m[i][j] == 'S')
	S.pb(mp(i,j));    
    }
  }


  ll minus = A+B;//初期状態、仮に東西、南北対称
  //A
  rep(i,S.size()){
    if(m[S[i].first][S[i].second] == 'S' && m[H+1-S[i].first][S[i].second]!='S'){
      minus-=A;//南北対称じゃなければ、Aを引く
      break;
    }
  }

  //B
  rep(i,S.size()){
    if(m[S[i].first][S[i].second] == 'S' && m[S[i].first][W+1-S[i].second]!='S'){
      minus-=B;//東西対称じゃなければBを引く
      break;
    }
  }
  // if(minus == (A+B)) minus += max(A,B);//初期値のままなら、四方位対称となる
  


  ans += AB();
  if(A>B) {
    ans += PA();
    ans += PB();
  }
  
  else{
    ans += PB();
    ans += PA();
  }

  //空の状態
  cout << ans- minus << endl;
  return 0;
}
  
