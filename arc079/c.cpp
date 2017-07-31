#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007
#define ll long long

using namespace std;


ll N,M;
vector<ll> a;
vector<ll> b;

ll db[200001]={0};



int main(){
  ll ina,inb;
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  a.push_back(0);
  b.push_back(0);
  for(ll i = 0;i<M;i++){
    cin >> ina>> inb;
    a.push_back(ina);
    b.push_back(inb);
    if(ina == 1)db[inb]=1;
  }


  for(ll i = 1;i<=M;i++){
    if(db[a[i]]){
      if(b[i]==N){cout << "POSSIBLE" << endl;
	return 0;
      }
    }
  }
  
  cout << "IMPOSSIBLE" << endl;
  
  return 0;
}
