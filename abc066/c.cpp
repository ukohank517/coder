#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll n;
vector <ll> a;

int main(){
  ll inp;

  vector <ll> odd;
  vector <ll> even;
  cin >> n;
  
  for ( int i =0;i<n;i++){
    cin >> inp;
    a.push_back(inp);
  }

  for (int i = 0; i < n ;i++){
    if((i%2)==0) even.push_back(a[i]);
    else odd.push_back(a[i]);
  }

  //even
  if((n%2)==0){
    reverse(odd.begin(),odd.end());
    for(int i =0;i<odd.size();i++) cout << odd[i] << " ";
    for(int i =0;i<even.size();i++) cout << even[i] << " ";
  }

  //odd
  else{
    reverse(even.begin(),even.end());
    for(int i =0;i<even.size();i++) cout << even[i] << " ";
    for(int i =0;i<odd.size();i++) cout << odd[i] << " ";
  }

  cout << endl;
  return 0;
}
