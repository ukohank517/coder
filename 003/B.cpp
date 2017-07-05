#include <iostream>
#include <string.h>
using namespace std;

int main(){

  string a, b;
  int size;
  bool flag=true;
  
  cin >> a >> b;
  a.size()>b.size()? size = a.size(): size = b.size();
  
  for(int i=0;i<size;i++){
    if(a[i]==b[i]) continue;
    if(a[i]=='@' &&(b[i]=='a'||b[i]=='t'||b[i]=='c'||b[i]=='o'||b[i]=='d'||b[i]=='e'||b[i]=='r'||b[i]=='@'))continue;
    if(b[i]=='@' &&(a[i]=='a'||a[i]=='t'||a[i]=='c'||a[i]=='o'||a[i]=='d'||a[i]=='e'||a[i]=='r'||a[i]=='@'))continue;

    cout << "You will lose" << endl;
    return 0;
    
  }
  cout << "You can win" << endl;
  return 0;
  
}
