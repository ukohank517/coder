#include <iostream>
using namespace std;

int h,w;
char A[102][102];
int main(){

  cin >> h >> w;

  for(int i=0;i<102;i++){
    for(int j = 0;j<102;j++){
      A[i][j]='#';
    }
  }
  
  for(int i =1;i<=h;i++){
    for(int j = 1;j<=w;j++){
      cin >> A[i][j];
    }
  }

  for(int i =0;i<=h+1;i++){
    for(int j = 0;j<=w+1;j++){
      cout << A[i][j];
    }
    cout << endl;
  }

  

  return 0;
}
