#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll N;
vector <ll> a;

int main(){
  ll inp;
  ll q,c;
  ll result = 0;
  
  cin >> N;
  for(ll i =0;i<N;i++){
    cin >> inp;
    a.push_back(inp);
  }

  while(true){
    sort(a.begin(),a.end());
    if(a[N-1]<N) break;
    q = a[N-1]/N;//何回操作したか
    a[N-1]%=N;
    for(ll i = 0;i<N-1;i++){
      a[i] += q;
    }
    result += q;
  }
  
  cout << result << endl;
  return 0;
}
