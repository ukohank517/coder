#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>

#define MOD 1000000007
#define ll long long
#define ld long double

using namespace std;

ll from(ll t){
  return (t/5)*5;
}

ll to(ll t){
  if((t%5)==0) return t;
  else return (t/5+1)*5;
}

ll mtt(ll m){
  ll h = m/60;
  //m%=60;

  return (m/60*100+m%60);
}

int main(){
  ll check[24*60+1]={0};
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  for(ll i =0;i< N;i++){
    string s;
    cin >> s;
    ll sh = stoi(s.substr(0,2));
    ll sm = from(stoi(s.substr(2,2)));
    ll eh = stoi(s.substr(5,2));
    ll em = to(stoi(s.substr(7,2)));
    //cout << sh << " " << sm << " " << eh << " " << em << endl; 
    ll si = sh*60+sm;
    ll ei = eh*60+em;
    for(ll j=si; j<=ei; j++){
      check[j]=1;
    }
  }

  /*
  ll before =0;
  for(ll i =0;i<=24*60;i++){
    if(check[i]!=before){
      if(before==0)cout << setw(4) << setfill('0') << mtt(i) << "-";
      if(before==1) cout << mtt(i-1) << endl;
    }
    before = check[i];
  }

  if(check[24*60]==1) cout << "2400" << endl;
  */
  ll s;
  for (ll t=0; t<=24*60; t++)
    {
      if (check[t] && (t==0 || !check[t-1]))
	s = t;
      if (!check[t] && (t>0 && check[t-1]))
	printf("%02lld%02lld-%02lld%02lld\n", s/60, s%60, (t-1)/60, (t-1)%60);
    }
  if (check[24*60])
    //printf("%02lld%02lld-2400\n", s/60, s%60);
    cout << s/60 << s%60 << "-2400" << endl;

  return 0;
}
