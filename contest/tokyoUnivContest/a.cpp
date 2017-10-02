#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cal(char S){
  if(S=='B') return 2;
  else if((S=='A')||(S=='D')||(S=='O')||(S=='P')||(S=='Q')||(S=='R')) return 1;
  else return 0;
}


int main(){
  string s;
  int res;
  
  cin >> s;
  res = cal(s[0])*1000+cal(s[1])*100+cal(s[2])*10+cal(s[3]);
  if(res==10) cout << "yes" << endl;
  else cout << "no" << endl;

  return 0;
}
