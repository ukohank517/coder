#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
 
#define MOD 1000000007
#define ll long long
#define ld long double
 
using namespace std;
 
//l<rは必ず成り立つ、
ll cal(int l, int r, int mid){
  //mid < l < r
  if(mid<=l && l<=r){//l~rまでの和
    ll left = l-mid;
    ll right = r-mid;
    return ((right+left)*(right-left+1))/2;
  }
 
  //l < mid < r
  else if(l<=mid && mid<=r){
    ll left = mid-l;
    ll right = r-mid;
    return (((left+1)*left)+((right+1)*right))/2;
  }
 
  //l < r < mdi
  else if(l<=r && r<=mid){
    ll left = mid-l;
    ll right = mid-r;
 
    return ((right+left)*(left-right+1))/2;
  }
 
}
 
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int R,G,B;
  cin >> R >> G >> B;
 
  ll result = 10e8;
  for(ll i =-450;i<=-100;i++){
    for(ll j =i+R;j<=300;j++){
      for(ll k = j+G;k<=450;k++){
	ll re = 0;
	re+= cal(i,i+R-1,-100);
	re+= cal(j,j+G-1,0);
	re+= cal(k,k+B-1,100);
	if(re<result) result = re;
      }
    }
  }
  
 
  cout << result << endl;
  return 0;
}
