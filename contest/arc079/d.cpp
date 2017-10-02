#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long



int main(){
  ll K;
  ll q,c;
  cin >> K;

  cout << "50" << endl;
  vector <ll> a(50,49);
  q = K/50;
  c = K%50;

  for(ll i = 0;i<50;i++){a[i]+=q;};
  for(ll i =0;i<c;i++){
    for(ll j =0;j<50;j++){
      a[j]--;
    }
    a[i]+=51;
  }


  for(ll i = 0;i<50;i++){
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
