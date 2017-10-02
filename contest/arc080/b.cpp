#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007
#define ll long long

using namespace std;


int main(){
  string inp;
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> inp;
  cout << inp[0] <<inp.size()-2<<inp[inp.size()-1]<< endl;
  
  return 0;
}
