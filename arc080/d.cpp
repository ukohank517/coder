#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007
#define ll long long

using namespace std;

ll H,W;
ll N;
vector <ll>a;

int main(){
  ll inp;
  ll c[101][101];
  ll count = 0;
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W >> N;
  for(ll i =0;i<N;i++){
    cin >> inp;
    a.push_back(inp);
  }
  
  
  for(ll i = 0;i<H;i++){
    for(ll j = 0;j<W;j++){
      c[i][j]=(count+1);
      a[count]--;
      if(a[count]==0) count++;
    }
  }

  for(ll i = 0;i<H;i++){
    if(i%2==0){
      for(ll j = 0;j<W;j++){
	cout << c[i][j] << " ";
      }
    }
    else{
      for(ll j =W-1;j>=0;j--)cout << c[i][j] << " "; 
    }
    cout << endl;
  }
  return 0;
}
