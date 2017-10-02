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

template <class T> struct Dijkstra {

  struct Edge{
    long long to;
    T cost;
    Edge(long long _to, T _cost) : to(_to), cost(_cost) {}
  };

  const T INF = numeric_limits<T>::max() / 2;
  vector< vector< Edge > > G;
  vector< T > d;
  Dijkstra (long long n) : G(n), d(n) {}

  void add_directed_edge(long long a, long long b, T c) {
    G[a].push_back(Edge(b,c));
  }

  void add_undirected_edge(long long a, long long b, T c) {
    G[a].push_back(Edge(b,c));
    G[b].push_back(Edge(a,c));
  }

  void init(long long s) {
    priority_queue< pair<T,long long>,vector< pair<T,long long> >, greater< pair<T,long long> > > que;
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    que.push(make_pair(0,s));
    while (!que.empty()){
      pair<T,long long> p = que.top();
      que.pop();
      long long v = p.second;
      if (d[v] < p.first) continue;
      for (long long i = 0; i < G[v].size(); i++) {
	Edge e = G[v][i];
	if (d[e.to] > d[v] + e.cost) {
	  d[e.to] = d[v] + e.cost;
	  que.push(make_pair(d[e.to],e.to));
	}
      }
    }
  }

  T dist(long long a) {
    return d[a];
  }

  vector<long long> route(long long a, long long b){

  }
};


int main(){
  ll N,M;
  vector<ll> l;
  vector<pair<ll,ll> >uv;
  vector<pair<ll,ll> >memo;//pair(to, cost)

  vector<ll> result;

  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M;


  for(ll i = 0;i< M;i++){
    ll inu,inv,inl;
    cin >> inu >> inv >> inl;
    inu--;inv--;

    if(inu==0)memo.push_back(make_pair(inv, inl));
    else if(inv==0)memo.push_back(make_pair(inu, inl));
    else{
      uv.push_back(make_pair(inu,inv));
      l.push_back(inl);
    }
  }

  Dijkstra<ll> road(N);
  if(uv.size()==0){
    cout << "-1" << endl;
    return 1;
  }
  for(ll i =0;i<uv.size();i++){
    road.add_undirected_edge(uv[i].first,uv[i].second,l[i]);
  }

//memoから一つずつ取り出して、ダイクストラ構築して計算
  for(ll i =0;i<memo.size();i++){
    road.init(memo[i].first);
    for(ll j = i+1;j<memo.size();j++){
      ll d=road.dist(memo[j].first);
      if(d==-1) continue;
      d+=memo[i].second;
      d+=memo[j].second;
      result.push_back(d);
    }
  }

  sort(result.begin(), result.end());
  if(result.size()==0) cout << "-1" << endl;
  else cout << result[0] << endl;

  return 0;
}
