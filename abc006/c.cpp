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

ll N, M;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M;

  ll man,old,child;
  for(ll i =0;i<=N;i++){
    man = i;
    ll pn = N-i;
    ll fn = M-2*i;

    child = fn-3*pn;
    old = pn-child;
    if(child>=0 && old >=0) {
      cout << man << " " << old << " " << child << endl;
      return 0;
  }
}
  cout << "-1 -1 -1" << endl;
  return 0;
}
