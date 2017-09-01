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
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;

bool func(pair<string,ll> a , pair<string, ll> b){
  return a.second > b.second;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;

  vector<pair<string,ll> > lead;

  rep(i,N){
    string name;
    cin >> name;
    
    ll index = 51;
    rep(j, lead.size()){
      if(lead[j].first == name){
	index = j;
	break;
      }
    }
    if(index != 51) lead[index].second+=1;
    else lead.push_back(make_pair(name,1LL));

  }

  sort(lead.begin(), lead.end(), func);
  cout << lead[0].first << endl;
  
  return 0;
}
