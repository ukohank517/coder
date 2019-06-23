#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007
#define ll long long

using namespace std;

vector <ll> A;
int main(){
  ll inp;
  
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  for(ll i = 0;i< 4;i++){
    cin >> inp;
    A.push_back(inp);
  }

  if(A[1] <= A[2]) cout << "0" << endl;
  else if(A[3] <= A[0]) cout << "0" << endl;
  else{
    sort(A.begin(), A.end());
    cout << A[2]-A[1] << endl;
  }
  
  
  return 0;
}
