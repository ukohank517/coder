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
//template<class T = ll> T in(){T x; cin >> x; return (x);}

char color[1005][1005];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll H,W,d;
  cin >> H >> W >> d;//2*(d-1)

  string C = "RGBY";

  if(d==1){
    rep(i,H) rep(j,W){
      color[i][j] = C[(i+j)%4];
    }

    rep(i,H){
      rep(j,W){
	cout << color[i][j];
      }
      cout << endl;
    }
    
    return 0;
  }

  if(d<4){
    rep(i,H/2+1){
      rep(j,W/(d-1)+1){
	ll si = 2*i;
	ll sj = (d-1)*j;
	rep(k,2)rep(l,d-1) color[si+k][sj+l]=C[(4+i*2+j)%4];
      }
    }
    
    rep(i,H){
      rep(j,W){
	cout << color[i][j];
      }
      cout << endl;
    }
    return 0;
  }

  d--;
  d/=2;
  d+=1;
  rep(i,H/(d-1)+1){
    rep(j,W/(d+1)+1){
      ll si = (d-1)*i;
      ll sj = (d+1)*j;
      rep(k,d-1)rep(l,d+1) color[si+k][sj+l]=C[(4+i*2+j)%4];
    }
  }
  
  rep(i,H){
    rep(j,W){
      cout << color[i][j];
    }
    cout << endl;
  }
  return 0;
  
  
  
}
