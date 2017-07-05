#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

vector <int> a;

int main(){
  int inp;
  
  for (int i = 0 ;i<3;i++){
    cin >> inp;
    a.push_back(inp);
  }

  sort(a.begin(),a.end());

  cout << a[0]+a[1] << endl;

  return 0;
}
