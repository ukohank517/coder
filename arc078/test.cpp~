#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define ll long long


ll N=3;

void sw(vector <pair<ll,ll> > *a, ll i){
  pair < ll,ll> s;

}

int main(){

  vector <pair<ll,ll> > a;
  pair<ll,ll>b;

  b.first = 13;b.second = 14;
  a.push_back(b);
  b.first = 14;b.second = 15;
  a.push_back(b);
  b.first = 15;b.second = 16;
  a.push_back(b);
  b.first = 13;b.second = 14;
  a.push_back(b);

  for( ll j = 0;j< a.size();j++){
    cout << a[j].first << "  " << a[j].second << endl;
  }
  cout << "          " << endl;
  for(ll i =0;i<a.size();i++){
    if((a[i].first == 13)||(a[i].second == 13)){
      b = a[i];
      a[i] = a[N];
      a[N] = b;
      N--;
      a.pop_back();
      
      i--;
      cout << "              " << endl;
      for( ll j = 0;j< a.size();j++){
	cout << a[j].first << "  " << a[j].second << endl;
      }
    }
  }
  return 0;
}
