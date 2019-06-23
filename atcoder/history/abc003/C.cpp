#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
  int N,K;
  vector<int> R(100);
  double result;
  cin >> N >> K;

  for(int i = 0;i<100;i++){
    R[N]=0;
  }
  
  for(int i = 0;i<N;i++){
    cin >> R[i];
  }

  sort(R.begin(), R.end());

  result = 0;
  for(int i =100-K;i<100;i++){
    result += R[i];
    result /=2.0;
  }

  cout << fixed << setprecision(10)<<result << endl ;
  return 0;
}
