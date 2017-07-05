#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
 
ll H,W;
 
ll maxfun(int  a, int b , int c){
  ll result;
  a>b? (result = a):(result =b);
  (result >c)? (result):(result = c);
  return result;
}
ll minfun(int  a, int b , int c){
  ll result;
  a<b? (result = a):(result =b);
  result <c? (result):(result = c);
  return result;
}
int main(){
  ll s1,s2,s3;
  ll result=100000;
  ll min, max;
  
  cin >> H >> W;
 
  if((H%3)*(W%3)==0){
    cout << "0" << endl;
    return 0;
  }
  else{
    result = std::min(H,W);
  }
  for(int i =H/3; i< H/2+1;i++){
    for(int j = W/3; j< W/2+1; j++){
      s1 = i*W;
      s2 = j*(H-i);
      s3 = (H-i)*(W-j);
      min = minfun(s1,s2,s3);
      max = maxfun(s1,s2,s3);
      if(result> (max-min)) result = max-min;
 
      s1 = j*H;
      s2 = i*(W-j);
      s3 = (H-i)*(W-j);
      min = minfun(s1,s2,s3);
      max = maxfun(s1,s2,s3);
      if(result> (max-min)) result = max-min;
    }
  }
 
  cout << result << endl;
  return 0;
}
