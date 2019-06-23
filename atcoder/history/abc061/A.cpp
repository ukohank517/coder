#include <iostream>
using namespace std;

int main(){
  int a,b,c;

  cin >> a >> b >> c;
  if(c>=a && c<=b){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
