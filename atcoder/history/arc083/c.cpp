#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll A,B,C,D,E,F;
  cin >> A >>B >> C >> D >> E >> F;

  
  ll maxwater,maxsugar;
  vector<ld> water,sugar;

  
  maxwater = F;


  ll ans = 0;
  rep(i,F/A+10){
    rep(j,F/B+10){
      if((i*100*A+j*100*B)<=F)
	water.pb(i*100*A+j*100*B);
      else break;
    }
  }

  rmsame(water);//こんな水が作れますよ
  
  rep(k,water.size()){
    maxsugar = min(water[k]/100*E, F-water[k]);
    
    ans = 0;
    rep(i,maxsugar/C+2){
      rep(j,maxsugar/D+2){
	if((i*C+j*D)<=maxsugar)
	  ans = max(ans, i*C+j*D);
	else break;
      }
    }
    sugar.pb(ans);
  }
  


  ll index=water.size()-1;
  ld maxrate = 0;
  rep(i,water.size()){
    if((sugar[i]+water[i])<=F){
      if((ld)(sugar[i]/water[i]) > maxrate){
	index = i;
	maxrate = (ld)(sugar[i]/water[i]);
      }
    }
  }
    
  cout << water[index]+sugar[index] << " " << sugar[index]<< endl;
  return 0;
}
