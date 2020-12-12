
template <class T> struct Dijkstra {
    struct Edge{
        int to;
        T cost;
        Edge(int _to, T _cost) : to(_to), cost(_cost) {}
    };

    const T INF_ = numeric_limits<T>::max() / 2;
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
        fill(d.begin(), d.end(), INF_);
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
/*usage:
 O(N2): ノードの数の自乗
 初期化:
 Dijkstra<T> dj(N);// T: 経路の型, N: 点の数
 経路追加:
 dj.add_undirecter_edge(from, to , cost);
 dj.add_directer_edge(from, to , cost);
 計算:
 dj.init(root);//根元はrootから計算する
 cout << di.dist(N) << endl; // 点Nの最短距離を表示する。
 */
