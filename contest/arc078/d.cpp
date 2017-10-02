#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>

#define ll long long

using namespace std;

ll N;
vector<pair<ll,ll> > ab;


void solve(pair<ll,ll>*a,ll *stat, ll *finis){
  ll newstat;
  
  for (ll i = 0;i<=ab.size();i++){
    
  }
}
int main(){
  pair<ll, ll> a;// just for input

  ll first, second;
  
  vector <ll> Fennec;
  vector <ll> Snuke;
  
  ll Fb,Fe,nFe;// Fennec begin, Fennc end, new Fennec end
  ll Sb,Se,nSe;// Snuke begin, Snuke end, new Snuke end
  ll swap;

  int flag = 0;
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N ;
  for(ll i = 0;i<N-1;i++){
    cin >> a.first >> a.second;
    ab.push_back(a);
  }

  Fb = 0;Fe = 0;
  Sb = 0;Se = 0;

  
  Fennec.push_back(1);
  Snuke.push_back(N);
  
  do{
    flag =0;
    nFe = Fe;
    for(int i = 0;i<N-1;i++){
      for(int j = Fb; j<= Fe; j++){
	if((ab[i].first == Fennec[j]) || (ab[i].second == Fennec[j])){
	  first = ab[i].first;second = ab[i].second;
	  if(first != Fennec[j]){
	    swap = first;
	    first = second;
	    second = swap;
	  }//secondはもう一方になる。
	  Fennec.push_back(second);
	  nFe++;
	  flag =1;
	  
	  swap = ab.size()-1;
	  a = ab[i];
	  ab[i] = ab[swap];
	  ab[swap] = a;
	  i--;
	  ab.pop_back();
	}
      }
    }
    if(flag){
      Fb = Fe+1;
      Fe = nFe;
    }

    
    flag =0;
    nSe = Se;
    //Se ++;
    for(int i = 0;i<N-1;i++){
      //nSe = Se;
      for(int j = Sb; j<= Se; j++){
	if((ab[i].first == Snuke[j]) || (ab[i].second == Snuke[j])){
	  first = ab[i].first;second = ab[i].second;
	  if(first != Snuke[j]){
	    swap = first;
	    first = second;
	    second = swap;
	  }//secondはもう一方になる。
	  Snuke.push_back(second);
	  nSe++;
	  flag =1;

	  swap = ab.size()-1;
	  a= ab[i];
	  ab[i] = ab[swap];
	  ab[swap] = a;
	  i--;
	  ab.pop_back();  
	}
      }
    }
    if(flag){
      Sb = Se+1;
      Se = nSe;
    }
    cout << "a" << endl;
  }while(ab.size()!=0);

  if(Fennec.size()  > Snuke.size()) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
  return 0;
  
}
