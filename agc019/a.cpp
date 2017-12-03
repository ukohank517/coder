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

bool func(pair<ll,ll>a, pair<ll,ll>b){
  return (double)(a.first/a.second) <(double)(b.first/b.second);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  //price, size*4
  vector<pair<ll,ll> >P;

  ll price,size;
  ll N;

  for(ll i =0;i<4;i++){
    size = pow(2,i);
    cin >> price;
    P.push_back(make_pair(price, size));
  }

  cin >> N;
  N*=4;

  sort(P.begin(), P.end(), func);

  ll res = 0;
  for(ll i =0;i<P.size();i++){
    ll num = N/P[i].second;
    res += num*P[i].first;
    N%=P[i].second;
    //if(N==0) break;
  }
  cout << res << endl;
  return 0;
  
  
}

