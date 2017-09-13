#include <iostream>
#include <cstring>

using namespace std;
#define ll long long
int main(){
  string s = "atcoder";
  char c = 'd';
  cout << s.find_first_of(c,5) << endl;
}
