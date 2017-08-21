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
  ll N;
  vector<ll> A;
  ll inp;
  ll memo=0,l1=0,l2=0;
  ll i;
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  for(ll i =0;i<N;i++){
    cin >> inp;
    A.push_back(inp);
  }

  
  sort(A.begin(), A.end());
  
  for(i= A.size()-1;i>=0;i--){
    if(A[i]==memo) {
      l1=A[i];
      memo = 0;
      break;
    }
    else{
      memo = A[i];
    }
  }

  for(i-=1;i>=0;i--){
    if(A[i]==memo) {
      l2=A[i];
      memo = 0;
      break;
    }
    else{
      memo = A[i];
    }
  }
  
  cout << l1*l2<< endl;
  
  return 0;
  
}
