#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main(){
  int N,S,T,W;
  vector<int> A;
  cin >> N >> S >> T;
  cin >> W;

  A.push_back(0);
  for(int i =1;i<N;i++){
    int inp;
    cin >> inp;
    A.push_back(inp);
  }

  int result=0;
  for(int i =0;i<A.size();i++){
    W+=A[i];
    if(S<=W && W<=T) result++;
  }

  cout << result << endl;

  return 0;
}
