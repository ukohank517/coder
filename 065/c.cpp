#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define M 1000000007
using namespace std;

ll n,m;

ll kaijyo(ll from, ll till, ll r){
  ll result=r;
  for(ll i=from+1;i<= till ;i++){
    result *=i;
    result %=M;
  }

  return result;
}
int main(){

  ll result = 1;
  ll tmp;
  
  cin >> n >> m;

  if(m<n){
    tmp = n;
    n=m;
    m=tmp;
  }           //n<m
  
  if((m-n)>1){
    cout << "0" << endl;
    return 0;
  }
  if(m-n==0)result = 2;


  tmp= kaijyo(1,n,1);
  
  result *= tmp;
  result %= M;
  result *= kaijyo(n,m,tmp);
  result %= M;
  cout << result << endl;
  return 0;
}
