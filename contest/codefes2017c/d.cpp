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
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}

ll alb[26]={0};
map<ll,bool> check;
map<ll,ll> fir;
map<ll,ll> las;

void albRenew(){
  rep(i,26)
    alb[i]=0;
}

ll countalb(){
  ll ret=0;
  rep(i,26){
    if((alb[i]%2) != 0) ret++;
  }
  return ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string str;
  cin >> str;
  rep(i,str.size()){
    alb[str[i]-'a']++;
  }
  ll ans = 0;
  rep(i,26){
    if((alb[i]%2==1)){ 
      check[i]=true;
      ans++;
    }
  }

  if(ans==0){cout << 1 << endl;return 0;}//全体で一つでよければそのまま
   //それぞれの奇数のアルファベットの最初と最後を取り出す
  rep(i,str.size()){
    if(check[str[i]-'a']){
      las[str[i]-'a'] = i;
      if(fir[str[i]-'a'] ==0) fir[str[i]-'a']=i;
    }
      
  }
  //一番最初の数字がどうしても0になるのでそのクリア
  if(check[str[0]-'a'])fir[str[0]-'a']=0;

  vector<ll> stoplist;
  rep(i,26){
    if(check[i]){
      ll a = fir[i];
      ll b = str.size()-1-las[i];

      if(a<b) stoplist.pb(fir[i]);
      else stoplist.pb(las[i]);
    }
  }

  stoplist.pb(str.size());
  sort(all(stoplist));

  ans=0;
  ll a = 0;
  ll b = stoplist[0]-1;
  albRenew();
  if(a!=b){
    for(ll i = a;i<=b;i++){
      alb[str[i]-'a']++;
    }
  }
  ans += countalb();
  //ans ++;
  //rep(i,stoplist.size())cout << stoplist[i]<< endl;

  ll flag = 0;
  rep(i,stoplist.size()-1){
    ll a = stoplist[i];
    ll b = stoplist[i+1]-1;
    albRenew();
    if(a!=b){
      for(ll i = a;i<=b;i++){
	alb[str[i]-'a']++;
      }
    }
    ll c = countalb();
    if(c==0) {c++;flag++;}
    ans += c;
  }
  
  cout << ans-flag << endl;
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
