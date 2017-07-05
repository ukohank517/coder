#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define N 100000
#define MOD 1000000007
using namespace std;


vector <ll> fact(N+1);
vector <ll> rever_fact(N+1);

ll modulo (ll a, ll b){
  ll x = 1 , y = a;
  while(b>0){
    if(b%2 == 1)x=(x*y)%MOD;
    y = (y*y)%MOD;
    b /= 2;
  }
  return x % MOD ;
}


// in range 0 <= x <= N
// 1. x!
// 2. (x!)^{-1}
//   2-1. (N!)^{-1}
//   2-2. (N-1!)^{-1} = { (N!)^{-1} }* N
//   2-3. *****
void setfact(ll n){
  ll inp=1;
  ll a,b;
  
  //****************************1.x!************************
  fact[0]=1; //0!  
  for (ll i = 1;i <= n;i++){
    inp*=i;
    inp%=MOD;
    fact[i]=inp; 
  }

  //***********************2.(x!)^{-1}********************
  //***********2-1.(N!)^{-1}= (N!)^{MOD-2}****************
  rever_fact[n] = modulo(fact[n],MOD-2);
  //***********2-2 
  for(ll i = n-1;i>=0;i--) rever_fact[i]=rever_fact[i+1]*(i+1);
  
}


//  aCb = a! / {b!*(a-b)!}
//      = a! * b!^{-1} * (a-b)!^{-1}
ll aCb(ll a , ll b){
  if((a<0)||(b<0)) return 0;
  if(a<b) return 0;
  if(b == 0) return 1;
  return (fact[a]*rever_fact[b]*rever_fact[a-b])%MOD;
}

int main(){
  ll n;
  vector <ll> a ;
  
  setfact(n);

}
