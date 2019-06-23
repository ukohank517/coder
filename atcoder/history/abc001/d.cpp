#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;
#define ll long long

ll from(ll i){
  if((i%5)==0) return i;
  else return (i/5)*5;
}
ll to(ll i){
  if((i%5)==0) return i;
  else {
    ll re =(i/5+1)*5;
    if(re%100!=60) return re;
    else return (re/100+1)*100;
  }
}

int main(){
  ll N ;
  cin >> N;

  vector<pair<ll,ll> >T;
  for(ll i =0;i<N;i++){
    string time;  
    cin >> time;
    ll t1 = stoi(time.substr(0, 4));
    ll t2 = stoi(time.substr(5, 9));
    T.push_back(make_pair(from(t1),to(t2)));
  }

  sort(T.begin(), T.end());

  vector<ll> s;
  vector<ll> e;

  ll start = T[0].first;
  ll end = T[0].second;
  for(ll i=1;i<N;i++){
    if(T[i].first>end){
      s.push_back(start);
      e.push_back(end);
      
      start = T[i].first;
      end = T[i].second;
    }
    else if(T[i].second>end)end = T[i].second;
  }
  s.push_back(start);
  e.push_back(end);

  for(ll i =0;i<s.size();i++){
    cout << setw(4) << setfill('0') << s[i] << "-" << e[i] << endl;
  }
  
  return 0;

}
