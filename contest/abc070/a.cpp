#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007
#define ll long long

using namespace std;

ll N;
int main(){
  ll inp;
  cin >> N;

  if((N/100)==(N%10)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
