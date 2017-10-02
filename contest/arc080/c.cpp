#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007
#define ll long long

using namespace std;

ll N;
vector <ll> a;

int main(){
  ll inp;
  ll two=0,four=0;
  ll a;
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  for(ll i =0;i<N;i++){
    cin >> inp;
    inp%=4;
    if(inp == 2) two++;
    else if(inp== 0) four++;
  }

  if(two != 0){
    a = four*2+two;
    if(a >= N) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else {
    a = four*2+1;
    if(a>=N) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
  
  
  
  return 0;
}
