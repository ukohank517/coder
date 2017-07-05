#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

struct Combinations {

  long long mod ;
  vector< long long > inv;
  vector< long long > fact;
  vector< long long > inv_fact;

  ll Combinations (int n, int m) : inv(n), fact(n), inv_fact(n), mod(m) {
    inv[1] = 1;
    for (long long i = 2; i < n; i++) {
      inv[i] = inv[mod%i] * (mod - mod / i) % mod;
    }
    fact[0] = inv_fact[0] = 1;
    for (long long i = 1; i < n; i++) {
      fact[i] = (fact[i-1] * i) % mod;
      inv_fact[i] = (inv_fact[i-1] * inv[i]) % mod;
    }
  }

  long long nPr(long long n, long long r) {
    if (n < r || r < 0) return 0;
    return fact[n] * inv_fact[n-r] % mod;
  }

  long long nCr(long long n, long long r) {
    if (n < r || r < 0) return 0;
    return nPr(n,r) * inv_fact[r] % mod;
  }

  long long nHr(long long n, long long r) {
    return nCr(n+r-1,r);
  }

};
ll check[100005]={0};
int main(){
  ll n;
  vector <ll> a ;

  ll inp,oup;
  ll first,second;
  ll a1,a2,a3;
  ll dis;// the distance of two same number;
  
  cin >> n;
  
  for(ll i =0;i<n+1;i++){
    cin >> inp;
    
    if(check[inp]==0) check[inp]= i;
    else{
      first = check[inp];
      second = i;
      dis = second - first;
      a1 = first ;
      a2 = dis -1;
      a3 = n - second ;
      //cout << "aa " << a1<<";a3" << a3 <<endl;

    }
    a.push_back(inp);  
  }

  //cout << "aa " << a1<<";a3" << a3 <<endl;
  cout << nCr(1,1);
  for (int i =1;i<=n+1;i++){
    //cout << aCb(n,i)<< " "<<aCb(a1+a3 , i-1) << endl;
  }
}
