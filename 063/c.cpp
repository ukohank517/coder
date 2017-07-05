#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N ;
vector<int> s;
int main(){
  int a,flag=0;//whether exist mod 10 not= 0
  int sum = 0;
  cin >> N;
  flag = 0;
  for(int i = 0;i < N ; i++){
    cin >> a;
    s.push_back(a);
    sum+=s[i];
    if((s[i]%10)!= 0) flag =1;
  }
  
  if(flag == 0) {
    cout << "0" << endl;
    return 0;
  }

  else if(sum %10 !=0){
    cout << sum << endl;
    return 0;
  }
  sort (s.begin(),s.end());
  for(int i = 0;i<N;i++){
    if((sum - s[i])%10!=0){
      cout << sum -s[i] << endl;
      break;
    }
  }
  
  return 0;
}
