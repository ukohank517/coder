#include <iostream>
using namespace std;

int main(){
  int m,n,a,b;
  int result[51]={0};
  
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    if(a!=b){
      result[a]++;
      result[b]++;
    }
  }

  for(int i = 1; i <= n; i++){
    cout << result[i] << endl;
  }
  
  return 0;
}
