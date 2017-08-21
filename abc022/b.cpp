#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define ll long long

ll N;
vector<ll> A;
int main(){
  ll check[100001]={0};
  cin >> N;
  for(ll i =0;i<N;i++){
    ll inp;
    cin >> inp;
    A.push_back(inp);
  }

  ll result=0;
  for(ll i =N-1;i>=0;i--){
    if(check[A[i]]==1) result++;
    else{
      check[A[i]]=1;
    }
  }
  cout << result << endl;
  return 0;
}
