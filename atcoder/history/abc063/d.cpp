#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;


ll n,a,b;
vector<ll> h;



int check(ll t){
  vector<ll> v1 = h;
  ll ans;
  for(ll i = 0;i < n;i++)v1[i] -= b*t;
  for(ll i = 0;i < n;i++){
    if(v1[i] > 0){
      ans = v1[i]/(a-b);
      if(v1[i] % (a-b) != 0)ans++;
      t -= ans;
    }
  }
  if(t >=0)return 1;
  return 0;
}
int main(){
  ll inp;
  ll l,m,r;//left,middle,right
  
  cin >> n >> a >> b;
  for(ll i = 0;i<n;i++){
    cin >> inp;
    h.push_back(inp);
  }
  sort(h.begin(),h.end());

  l=0;
  r=h[n-1];


  while(l<r){
    m=(l+r)/2;
    if(check(m)==1)r=m;
    else l=m+1;
  }
  cout << l << endl;
  
  
}
