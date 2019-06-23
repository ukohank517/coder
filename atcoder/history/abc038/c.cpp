#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll sum(ll l){return l*(l+1)/2;}
int main(){
  ll N;

  cin >> N;

  ll size = 0;
  ll before=0;
  ll result = 0;
  for(ll i =0;i<N;i++){
    ll inp;
    cin >> inp;

    if(inp > before)
      size++;
    else{
      result += sum(size);
      size = 1;
    }
    
      before = inp;    
  }

  result += sum(size);
  cout << result << endl;
  
}
