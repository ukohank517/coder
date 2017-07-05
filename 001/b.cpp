#include <iostream>
#define ll long long
using namespace std;


int main(){
  ll m;

  cin >> m;
  
  if(m<100) cout << "00" << endl;
  else if(m<=5000){
    m/=100;
    if(m<10) cout << "0";
    cout << m << endl;
  }
  else if(m<=30000) cout << m/1000+50 << endl;
  else if(m<=70000) cout << (m/1000-30)/5+80 << endl;
  else cout << "89" << endl;

  return 0;
  
}
