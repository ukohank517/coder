#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <int>s;

int main(){
  int inp;
  cin >> N;
  for(int i =0;i<N;i++){
    cin >> inp;
    s.push_back(inp);
  }

  sort(s.begin(),s.end());
  cout << s[N-1]-s[0] << endl;

  return 0;
}
