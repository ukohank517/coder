#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iterator>

#define ll long long

using namespace std;


ll N;
vector <ll> a;

int check(ll k){
  vector <ll> vec;
  ll q,c;
  ll result = 0;
  
  for(ll i =0;i<N;i++){
    vec.push_back(a[i]+k);
  }
  for(ll i = 0;i<N;i++){
    q = vec[i]/(N+1);
    c = vec[i]%(N+1);
    if(q>=0){
      result += q;
      if(c>0) result ++;
    }
  }
  if(result >k) return 0;
  else return 1;
}


int main(){
  ll inp;
  ll l=0,r=500000000000000000,k;
  ll bl=0,br=0;
  ll result=r;
  ll flag1,flag2;
  
  cin >> N;
  for(ll i = 0;i< N ;i++){
    cin >> inp;
    a.push_back(inp-N+1);
  }

  flag1 = 0;
  
  do{
    flag2 = 1;
    do{
      k = (l+r)/2;
      if(check(k)) r=k;
      else l = k;
      if((bl==l)&&(br==r)){
	for(ll i = l;i<=r;i++){
	  if(check(k)){
	    r = i;
	    flag1 = 1;
	    break;
	  }
	}
	flag2 = 0;
	break;
      }
    }while(flag1);
    if((result != r)&&(flag2==1)){
      result = r;
      l = 0;
    }
    else{
      flag2 = 0;
    }
  }while(flag2);

  cout << result << endl;
  cout << check(1234567894846) << endl;
  cout << check(1234567894847) << endl;
  cout << check(1234567894848) << endl;
  cout << check(1234567894849) << endl;
  cout << check(1234567894850) << endl;
}
