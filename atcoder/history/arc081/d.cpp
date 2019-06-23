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


ll N;
string s1,s2;

int main(){
  ll result=0;
  ll before; // before case : 1 1      or 2
             //                           2
  ll i=0;
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  cin >> s1;
  cin >> s2;

  if(s1[i]==s2[i]){
    result = 3;
    before = 1;
  }
  else {
    result = 6;
    before = 2;
    i+=1;
  }
  for(i+=1;i<s1.size();i++){
    //case 1
    if(s1[i]==s2[i]){
      if(before == 1) result *= 2;//1->1     
      else  result *= 1;//2->1
      
      //renew
      before = 1;
    }
    //case 2
    else{
      if(before == 1) result*=2;// 1->2
      else result*=3;// 2-> 2

      //renew
      before = 2;
      i+=1;
    }
    result %= MOD;
  }


  cout << result << endl;
  return 0;
}
