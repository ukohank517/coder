#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
 
#define ll long long
#define ld long double
 
template <class T> struct Dijkstra {
 
  struct Edge{
    int to;
    T cost;
    Edge(int _to, T _cost) : to(_to), cost(_cost) {}
  };
    
  const T INF = numeric_limits<T>::max() / 2;
  vector< vector< Edge > > G;
  vector< T > d;
  Dijkstra (int n) : G(n), d(n) {}
 
  void add_directed_edge(int a, int b, T c) {
    G[a].push_back(Edge(b,c));
  }
    
  void add_undirected_edge(int a, int b, T c) {
    G[a].push_back(Edge(b,c));
    G[b].push_back(Edge(a,c));
  }
 
  void init(int s) {
    priority_queue< pair<T,int>,vector< pair<T,int> >, greater< pair<T,int> > > que;
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    que.push(make_pair(0,s));
    while (!que.empty()){
      pair<T,int> p = que.top();
      que.pop();
      int v = p.second;
      if (d[v] < p.first) continue;
      for (int i = 0; i < G[v].size(); i++) {
	Edge e = G[v][i];
	if (d[e.to] > d[v] + e.cost) {
	  d[e.to] = d[v] + e.cost;
	  que.push(make_pair(d[e.to],e.to));
	}
      }
    }
  }
    
  T dist(int a) {
    return d[a];
  }
    
}; 
 
ld distan(ld x1, ld y1, ld x2, ld y2){
  ld x = x1-x2;
  ld y = y1-y2;
  return sqrt(x*x+y*y);
}
 
map<pair<ll,ll>, ll>v;
ll xs,ys,xt,yt;
ll N;
 
int main(){  
 
  cin >> xs >> ys >> xt >> yt;
  cin >> N;
  
  vector<ll> x(N+10),y(N+10),r(N+10);
  x[0]=xs,y[0]=ys,x[N+1]=xt,y[N+1]=yt;
  r[0]=0, r[N+1]=0;
  for(ll i = 1;i<=N;i++){
    cin >> x[i] >> y[i] >> r[i];
  }
  for(ll i =0;i<N+2;i++){
    v[make_pair(x[i],y[i])]=i;
  }
  
  Dijkstra<ld> Root(N+2);
  for(ll i = 0;i < N+2;i++){
    for(ll j = 0;j < N+2;j++){
      if(i==j)continue;
      ll v1 = v[make_pair(x[i],y[i])];
      ll v2 = v[make_pair(x[j],y[j])];
      ld cost = distan(x[i],y[i], x[j],y[j]);
      Root.add_undirected_edge(v1,v2,max((ld)0, (cost-(ld)r[i]-(ld)r[j])));
    }
  }
 
  Root.init(0);
  cout << fixed << setprecision(10) << Root.dist(N+1) << endl;
  return 0;
}


