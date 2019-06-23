#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
 
ll H,W;
 
ll maxfun(ll a, ll b , ll c){
  ll  result;
  a>b? (result = a):(result =b);
  return (result >c)? (result):c;
}
ll minfun(ll a, ll b , ll c){
  ll result;
  a<b? (result = a):(result =b);
  return   (result <c)? (result):c;
}

ll solve(ll h, ll w){
  ll result;
  for(int i = h/3; i < h/2+1;i++){
    int j= w/2;
    ll s1 = i*w;
    ll s2 = j*(h-i);
    ll s3 = (h-i)*(w-j);
    result = min(result,(maxfun(s1,s2,s3)-minfun(s1,s2,s3)));
  }
  return result;
}

int main(){
  ll result=100000;

  
  cin >> H >> W;
 
  if((H%3)*(W%3)==0){
    cout << "0" << endl;
    return 0;
  }

  else result = H<W? H:W;
  cout << "" ;  //これがないとバグるのなぜ？
  cout << minfun(solve(H,W),solve(W,H),result) << endl;
  return 0;
 
}
