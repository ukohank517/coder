#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdlib>

#define MOD 1000000007
#define ll long long

using namespace std;

ll N;
vector<ll>a;

int main(){
  ll inp;
  ll sumall;
  ll sumhalf;
  ll di;
  ll result;
  
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N;
  sumall = 0;
  for(ll i =0;i<N;i++){
    cin >> inp;
    a.push_back(inp);
    sumall += inp;
  }
  result = abs(sumall-2*a[0]);
  sumhalf = a[0];
  for(ll i =1;i<N-1;i++){
    sumhalf += a[i];
    di = abs(sumall-(2*sumhalf));
    if(result > di) result = di;
  }

  cout << result << endl;
  return 0;
}
