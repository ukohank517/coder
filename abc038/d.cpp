#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long

bool cpr(pair<ll,ll> a , pair<ll,ll> b){
  return (a.first==b.first)?(a.second > b.second):(a.first < b.first);
}
ll N;
vector<pair<ll,ll> > box;
ll bit[100005];

ll get_max(ll i){
  ll ans = 0;
  while(i>0){
    ans=max(ans, bit[i]);
    i-= i&-i;
  }
  return ans;
}

void update(ll i, ll x){
  while(i<=100005){
    bit[i] = max(bit[i],x);
    i+= i&-i;
  }
}

int main(){
  cin >> N;
  for(ll i = 0;i< N;i++){
    ll h,w;
    cin >> h >> w;
    box.push_back(make_pair(h,w));
  }

  sort(box.begin(), box.end(), cpr);

  ll result = 0;
  for(ll i =0;i< N;i++){
    if(i && box[i].first == box[i-1].first && box[i].second == box[i-1].second) continue;
    ll a = get_max(box[i].second -1)+1;
    result = max(result, a);
    update(box[i].second,a);
  }

  cout << result << endl;

}
