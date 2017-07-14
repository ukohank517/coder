#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define ll long long

using namespace std;

ll N,M;
vector <ll> A;
vector <ll> X;
vector <ll> Y;

void solve(){
  vector<ll> cop(A.size());
  ll result =0;
  ll siz;
    
  copy(A.begin(),A.end(),cop.begin());
  sort(cop.begin(),cop.end());
  do{
    siz = cop.size();
    if(cop[cop.size()-1]==siz){
      while(cop[cop.size()-1]==siz){
	cop.pop_back();
      }
    }
    else{
      result++;
      cop[cop.size()-1]=siz;
    }
  }while (cop.size()!=0);
  cout << result << endl;
  return ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int ina,inx,iny;

  cin >> N >> M;
  for(int i =0;i<N;i++){
    cin >> ina;
    A.push_back(ina);
  }

  for(int i =0;i<M;i++){
    cin >> inx >> iny;
    X.push_back(inx);
    Y.push_back(iny);
  }
  for(int i = 0;i<M;i++){
    A[X[i]]=Y[i];
    solve();  
  }
  
  return 0;
}
