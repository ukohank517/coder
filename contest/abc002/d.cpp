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

vector<pair<ll,ll> >relation;

bool cpr(pair<ll,ll> a, vector<pair<ll,ll> > A){
  for(ll i =0;i<A.size();i++){
    if(a==A[i]) return true;
  }
  return false;
}

 ll check(vector<ll> b){
   for(ll i =0;i<b.size();i++){
     for(ll j =i+1;j<b.size();j++){
      if(!cpr(make_pair(b[i],b[j]),relation)){
        return 1;
      }
     }
   }
   return b.size();
 }

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,M;
  cin >> N >> M;
  for(ll i =0;i<M;i++){
    ll x,y;
    cin >> x >> y;
    relation.push_back(make_pair(x,y));
    relation.push_back(make_pair(y,x));
  }
  for(ll i =1;i<=12;i++){relation.push_back(make_pair(i,i));}

  vector<vector<ll> > bit(4096);
  for(ll i =0;i<4096;i++){
    ll j = i;
    for(ll k =0;k<12;k++){
      bit[i].push_back(j%2);
      j/=2;
    }
  }

  ll result =0;
  for(ll i =0;i<4096;i++){
    vector<ll> member;
    for(ll j=0;j<12;j++){
      if(bit[i][j]==1) member.push_back(j+1);
    }
    ll r = check(member);
    if(r>result) result = r;
  }


  cout << result << endl;

  return 0;
}
