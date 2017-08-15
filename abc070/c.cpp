#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007
#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b,a%b);
}

ll N;

int main(){
  ll inp;
  ll result=1;
  ll a;
  
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;

  for(ll i =0 ;i< N;i++){
    cin >> inp;
    a = gcd(inp, result);
    result = (result / a) * inp;

  }

  cout << result<< endl;
  
  return 0;
}
