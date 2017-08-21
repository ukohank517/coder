#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
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


ll N;
vector<ll> x,y,t,r;
map<pair<ll,ll>,ll> point;

int main(){
  cin >> N;
  for(ll i = 0;i<N;i++){
    ll ix,iy,it,ir;
    cin >> ix >> iy >> it >> ir;
    x.push_back(ix);
    y.push_back(iy);
    t.push_back(it);
    r.push_back(ir);

    point[make_pair(ix,iy)]=i;
  }
  
  Dijkstra<ld>Tako(1010);
  for(ll i = 0;i<N;i++){
    for(ll j =  0;j<N;j++){
      if(i==j)continue;
      ld time = sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
      time /= (ld)min(t[i],r[j]);
      Tako.add_directed_edge(i,j,time);
    }
  }

  Tako.init(0);

  ld result=0.0;
  vector<ld> te;
  for(ll i =0;i<N;i++){
    te.push_back(Tako.dist(i));
  }
  sort(te.begin(), te.end());
  result = te[1];
  for(ll i=2;i<N;i++){
    if((te[i]-result)<1.0) result += 1.0;
    else result = te[i];
  }
  
  /*
  reverse(te.begin(),te.end());
  for(ll i =0;i<N-1;i++){
    ld a = te[i] + (ld)i;
    result = max(result,a);
  }
  */
  cout << fixed;
  cout << setprecision(6) << result << endl;
  return 0;
}
