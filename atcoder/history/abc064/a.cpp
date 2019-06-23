#include <iostream>
using namespace std;

int a,b,c;
int main(){

  cin >> a >> b >> c;
  if((100*a+10*b+c)%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
