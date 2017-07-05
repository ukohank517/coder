#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define ll long long

using namespace std;


int main(){
  string inp;
  int flag ;
  int l,i = 0;

  cin >> inp;

  do {
    i+=2;
    flag = 0;
    l = (inp.size() - i)/2;
    for(int i = 0; i < l ; i++){
      if(inp[i]!=inp[i+l]) flag = 1;
    }
  }while (flag);

  cout << l*2 << endl;
  
  return 0;
}
