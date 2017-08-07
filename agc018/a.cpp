#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>

#define MOD 1000000007
#define ll long long

using namespace std;

ll gcf(ll a, ll b){
  if(a < b){ll temp = a; a = b; b = temp;}

  if(b == 0) return a;
  else return gcf(b,a%b);
}


ll N,K;
vector<ll> A;

int main(){
  ll inp;
  ll cf;
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  //入力部分,0なら飛ばす
  cin >> N >> K;
  for(ll i = 0 ,l = N; i<l ; i++){
    cin >> inp;
    if(inp == 0) N--;
    else A.push_back(inp);
  }

  //そもそも求めたい数字がmaxより大きければ引き算で解けない
  sort(A.begin(), A.end());
  if(K>A[N-1]){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  cf = gcf(A[0],A[1]);
  for(ll i = 2; i< A.size();i++){
    cf = gcf(cf,A[i]);
    if(cf == 1){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }

  if(!(K%cf)) cout << "POSSIBLE" << endl;
  else  cout << "IMPOSSIBLE" << endl;

  return 0;
}
