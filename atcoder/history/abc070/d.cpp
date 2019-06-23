/*
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int limit = 100010;
using edge = struct {int to; ll cost;};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d){
  depth[v]=d;
  for(auto &e:tree[v]){
    if(e.to==p) continue;
    dfs(e.to, v, d+e.cost);
  }
}

int main(){
  int n;
  cin >> n;
  for(int i = 0;i<n-1;++i){
    int a, b,c;
    cin >> a >> b >> c;
    a--,b--;
    tree[a].push_back({b,c});
    tree[b].push_back({a,c});
  }

  int q,k;
  cin >> q >> k;
  k--;

  dfs(k,-1,0);
  for(int i = 0;i<q;++i){
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << depth[x]+depth[y] << endl;
  }
  return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll  long long

struct E{
  vector<ll> to;
  vector<ll> cost;
};

ll N,Q,K;
//vector<E> Tree(100001);
E Tree[100001];
vector<ll> x,y;

ll re[100001]={0};


void solve(ll parent, ll co){
  if(re[parent]==0)
    {
      re[parent] = co;
      for(ll i = 0,l = Tree[parent].to.size(); i<l ; i++){
	if(Tree[parent].to[i]==K)continue;
	solve(Tree[parent].to[i],Tree[parent].cost[i]+co);
      }
    }
}

int main(){

  cin >> N;
  N--;
  for(ll i = 0;i<N;i++){
    ll ina,inb,inc;
    cin >> ina >> inb >> inc;

    Tree[ina].to.push_back(inb); Tree[ina].cost.push_back(inc);
    Tree[inb].to.push_back(ina); Tree[inb].cost.push_back(inc);
  }

  cin >> Q >> K;
  for(ll i = 0;i<Q;i++){
    ll inx, iny;
    cin >> inx >> iny;
    x.push_back(inx);
    y.push_back(iny);
  }
  /*
  //一応木の形を確認  
  for(ll i =0;i<=5;i++){
    cout << "i" << i << ":" ;
    for(ll j =0;j< Tree[i].cost.size();j++){
      cout << Tree[i].cost[j] << " " ;
    }
    cout << endl;
  }
  */
  solve(K,0);

  for(ll i = 0;i<Q;i++){
    cout << re[x[i]]+re[y[i]] << endl;
  }
  return 0;
}
