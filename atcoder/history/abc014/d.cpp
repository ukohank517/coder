#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
#define ll long long

struct LCA {

  int N,LOG_N;
  vector< vector< int > > parent;
  vector< vector< int > > G;
  vector< int > depth;

  LCA (int n) : N(n), depth(n), G(n), LOG_N((int)(log2(n)+1)) {
    parent = vector< vector< int > >(LOG_N, vector<int>(N));
  }

  void add_edge(int a, int b) {
    G[a].push_back(b);
    G[b].push_back(a);
  }
    
  void init(int root) {
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < LOG_N; k++) {
      for (int v = 0; v < N; v++) {
	if (parent[k][v] < 0) parent[k+1][v] = -1;
	else parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }

  void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (int i = 0; i < G[v].size(); i++) {
      if (G[v][i] != p) dfs(G[v][i], v, d+1);
    }
  }

  int dist(int a, int b) {
    int par = getParent(a,b);
    return depth[a] + depth[b] - depth[par] * 2;
  }
    
  int getParent(int u, int v) {
    if (depth[u] > depth[v]) swap(u,v);
    for (int k = 0; k < LOG_N; k++) {
      if (((depth[v] - depth[u]) >> k) & 1) v = parent[k][v];
    }
    if (u == v) return u;
    for (int k = LOG_N - 1; k >= 0; k--) {
      if(parent[k][u] != parent[k][v]){
	u = parent[k][u];
	v = parent[k][v];
      }
    }
    return parent[0][u];
  }

};

int main(){
  ll N,Q;

  vector<ll> a,b;
  cin >> N;
  LCA inst(N);

  for(ll i = 1; i< N;i++){
    ll x,y;
    cin >> x >> y;
    x--,y--;
    inst.add_edge(x,y);
  }
  cin >> Q;
  for(ll i =0;i<Q;i++){
    ll ina,inb;
    cin >> ina >> inb;
    ina--,inb--;
    a.push_back(ina);
    b.push_back(inb);
  }
  
  inst.init(0);
  
  for(ll i =0;i< Q;i++){
    ll p = inst.getParent(a[i],b[i]);
    cout << inst.dist(0,a[i])+inst.dist(0,b[i])-2*inst.dist(0,p)+1 << endl;
  }
}
