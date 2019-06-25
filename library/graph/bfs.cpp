#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iomanip>
using namespace std;

#define REP(i,n) for(long long (i)=0;(i)<(long long)(n);(i)++)
#define RREP(i,n) for(long long (i)=(long long)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
typedef long long ll;

int N,M;
vector<int> G[100010]; //グラフ，隣接リスト
bool used[100010]; //頂点を訪れたかどうか

void bfs(int v) {
    queue<int> que;
    que.push(v);
    while (!que.empty()) {
        int vt = que.front();
        que.pop();
        if (used[vt]) continue;
        used[vt] = true;
        REP(i,G[vt].size()) {
            que.push(G[vt][i]);
        }
    }
}

int main() {

    cin >> N >> M; //例えば，Nが頂点数，Mが辺の数
    REP(i,M) {
        int a,b; cin >> a >> b;
        G[a].push_back(b); // 無向グラフなら
        G[b].push_back(a); // 2方向に
    }

    bfs(1);

    return 0;
}
