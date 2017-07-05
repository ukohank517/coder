#include <iostream>
#include <algorithm>
using namespace std;

char s[27];
int main(){
  int flag = 0;
  cin >> s;
  for (int i =0;i<strlen(s);i++){
    for(int j = i+1; j<strlen(s);j++){
      if (s[i] == s[j]) flag = 1;
    }
  }
  
  (flag==1)?(cout << "no" << endl):(cout <<"yes" << endl);
  
  return 0;
}
