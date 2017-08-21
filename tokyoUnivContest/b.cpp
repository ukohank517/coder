#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

#define ll long long

ll y,m;

//うなぎ暦の年数を渡す
ll check(ll u){
  ll reu = u + (u*(u+1))/2 ;
  ll res = y*12+m;
  if(reu>res)return 1;
  
  return 0;
}

int main(){
  ll mid;
  ll l=0,r=10e16;
  
  cin >> y >> m;
  y-=2013;

  cout << r << endl;
  cout << LONG_MAX << endl;
  return 0;
  
  do{
    mid = (l+r)/2;
    if(check(mid)) r = mid;
    else l = mid;
  }while((l+1)<r);

  cout << l << endl;
  
  
  return 0;
}
