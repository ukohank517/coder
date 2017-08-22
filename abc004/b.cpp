#include <iostream>
#include <cstring>

using namespace std;
#define ll long long 
int main(){
  string A[4][4];

  for(ll i =3;i>=0;i--){
    for(ll j =3;j>=0;j--){
      cin >> A[i][j];
    }
  }
  
  for(ll i =0;i<4;i++){
    for(ll j = 0;j<4;j++){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
