#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int x,a,b;

int main(){
  cin >> x>>a>>b;

  if((b-a)>x)cout << "dangerous"<<endl;
  else if(b<=a) cout << "delicious"<< endl;
  else cout << "safe"<<endl;
  
  return 0;
}
