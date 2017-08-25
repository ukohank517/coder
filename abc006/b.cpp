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
  ll inp;

  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> inp;
  vector<ll> a(1e6+2);
  a[0]=0;
  a[1]=0;
  a[2]=1;
  ll i;
  for(i =3;i<inp;i++){
    a[i] = (a[i-1]+a[i-2]+a[i-3])%10007;
  }
  cout << a[inp-1] << endl;
  return 0;
}
