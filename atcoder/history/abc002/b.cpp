#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long

int main(){
string s;
cin >> s;
for(ll i =0;i<s.size();i++){
  if(s[i]=='a')continue;
  if(s[i]=='e')continue;
  if(s[i]=='i')continue;
  if(s[i]=='o')continue;
  if(s[i]=='u')continue;

  else cout <<s[i];
}
cout << endl;
return 0;
}
