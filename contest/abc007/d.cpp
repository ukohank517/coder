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
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

//変数を変換しながら使ってください.
//文字列sが、_withoutaと_withoutbの数を所持し、
ll digitDP(string s, ll _withouta, ll _withoutb){
  ll n = s.size();
  ll dp[n+1][2][2]; // keta,less,forbid
  rep(i,n+1)rep(j,2)rep(k,2) dp[i][j][k] = 0;

  dp[0][0][0] = 1;
  rep(keta,n)rep(less,2)rep(ng,2){
    int c = s[keta]-'0';
    for(ll d = 0;d < 10;d++){
      if(less || d<=c)
	dp[keta+1][less||d<c][ng||d==_withouta||d==_withoutb] += dp[keta][less][ng];
    }
  }
  ll result = 0;
  for(ll less = 0;less<2;less++){
    result += dp[n][less][1];
  }
  return result;
}
 


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string A,B;
  cin >> A >> B;

  A[A.size()-1] -= 1;
  ll na = digitDP(A, 4, 9);
  ll nb = digitDP(B, 4, 9);
  
  cout << nb-na << endl;
  return 0;
}
