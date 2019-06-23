#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define ll long long

using namespace std;
ll N;
ll P;


void comb(vector<vector <long long int> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}



int main(){
    
  ll inp;
  ll odd=0,even=0;
  ll a,b;
  ll result=0;

  
  cin >> N >> P;
  
  for(ll i = 0;i<N;i++){
    cin >> inp;
    if((inp%2)==1) odd++;
    else even++;
  }

  vector<vector<long long int> > v(N+1,vector<long long int>(N+1,0));
  comb(v);

  b = 0;
  for(ll i = 0;i<= even;i++){
    b+=v[even][i];
  }
  if(P){//oddから奇数
    for(ll i =1;i<=odd;i+=2){
      a=v[odd][i];
      result += (a*b);
    }
  }
  else{//oddから偶数
    for(ll i=0;i<=odd;i+=2){
      a = v[odd][i];
      result += (a*b);
    }
    
  }
  cout << result << endl;
  return 0;
}
