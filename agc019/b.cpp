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

using namespace std;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string inpstr;
  cin >> inpstr;

  ll size = inpstr.size();

  vector<vector<ll> > R(27); 
  for(ll i =0;i<size;i++){
    R[inpstr[i]-'a'].push_back(i);
  }

  ll ans = size*(size-1);
  ans /=2;

  //-----------------------
  for(ll i = 0;i< 26;i++){
    if(R[i].size()<=1) continue;

    vector<ll> lar;
    ll num =0;
    for(ll j =1;j<R[i].size();j++){
      if(R[i][j]==(R[i][j-1])){
	num++;
      }
      else{
	num++;
	lar.push_back(num);
	num=0;
      } 
    }
    lar.push_back(num);
    ll rem =1;
    for(ll i =0;i<lar.size();i++){
      rem*=lar[i];
    }
    ans = ans-rem-(lar.size()*(lar.size()-1)/2);
  }
  
  cout << ans+1 << endl;
  return 0;
}
