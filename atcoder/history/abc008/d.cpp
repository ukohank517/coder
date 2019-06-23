#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
using namespace std;
#define all(a) a.begin(),a.end()
#define rmsame(a) a.erase(unique(all(a)), a.end())

#define MAX_N 30
#define MAX_W 100

ll dp[31][31][31][31], board[101][101], w, h,n;
vector<ll> x,y;

/*
  機械により囲まり、機械で場合分けする
  |-----------------------f(x,y)
  |            |            |
  |-------- i(x,y)--------- |
  |            |            |
 s(x,y)---------------------|
 */


ll dfs(ll sx, ll sy, ll fx, ll fy){
  if(dp[sx][sy][fx][fy] != 0)  return dp[sx][sy][fx][fy];

  //gold:機械を動かして取れる金塊の数
  ll ret = 0, gold = x[fx]-x[sx]+y[fy]-y[sy]-3;
  rep(i,n+1){
    if(x[sx] < x[i] && x[i] < x[fx] && y[sy] < y[i] && y[i] < y[fy])
      ret = max(ret, dfs(sx,sy,i,i)+dfs(sx,i,i,fy)+dfs(i,sy,fx,i)+dfs(i,i,fx,fy)+ gold );
  }
  dp[sx][sy][fx][fy] = ret;
  return ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  cin >> w >> h >> n;
  //機械がある場所
  x.resize(n+2);
  y.resize(n+2);
  x[0] = 0;x[n+1] = w+1;
  y[0] = 0;y[n+1] = h+1;//(0,0) (n+1)(n+1)にも機械があると仮定し、計算領域この二つの機械の間の範囲と置き換える。
  rep(i,n) cin >> x[i+1] >> y[i+1];

  cout << dfs(0,0,n+1,n+1) << endl;
  
  return 0;
}
