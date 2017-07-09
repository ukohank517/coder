#include <iostream>
using namespace std;

int main(){

  int N,result=0;
  cin >> N;
  
  for(int i=1;i<=N;i++){
    result+=i;
  }

  cout << result*10000/N << endl;
}
