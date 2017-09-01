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
#define ERR cout << "err" << endl;
using namespace std;

ll R,C;
ll sy, sx;
ll gy, gx;
queue<pair<ll,ll> >job;
vector<vector<ll> >M;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> R >> C;
  cin >> sy >> sx;
  sy--;sx--;
  cin >> gy >> gx;
  gy--;gx--;
  for(ll i =0;i<R;i++){
    string L;
    cin >> L;

    vector<ll> Mi;
    for(ll i =0;i<L.size();i++){
      if(L[i]=='#')Mi.push_back(-1);
      else if(L[i]=='.')Mi.push_back(0);
    }
    M.push_back(Mi);
  }
  
  M[sy][sx] = 1;//スタートを1にする
  job.push(make_pair(sy,sx));


  while(job.size()!=0){
    ll y = job.front().first;
    ll x = job.front().second;
    ll dist = M[y][x];
    for(ll i = y-1;i<=y+1;i++){
      if(M[i][x]==0){
	M[i][x]=M[y][x]+1;
	job.push(make_pair(i,x));
      }
    }
    for(ll i = x-1;i<=x+1;i++){
      if(M[y][i]==0){
	M[y][i]=M[y][x]+1;
	job.push(make_pair(y,i));
      }
    }

    job.pop();
  }

  cout << M[gy][gx]-1<< endl;
  return 0;
}
