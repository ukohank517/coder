#include <iostream>
using namespace std;

int a,b;
int main(){
  cin >> a >> b;
  if(a+b>=10){
    cout << "error" << endl;
    return 0;
  }
  cout << a+b << endl;
  return 0;
}
