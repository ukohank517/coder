#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#defint long long ll

ll dif(ll a , ll b){
  if(a>b) return a-b;
  else return b-a;
}

using namespace std;

ll n,a,b,c,d;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll diff_crease;
  ll a,b;
  
  cin >> n >> a >> b >> c >> d;

  if(a==b) {
    cout << "NO" << endl;
    return 0;
  }
  if(a>b){
    int temp=a;
    a = b;
    b = temp;
  }
  
  diff_crease = dif(c,d);

  if(a%2){//a is odd
    
  }
  return 0;
}
