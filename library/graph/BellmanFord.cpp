template<class T> struct BellmanFord {
    
    struct Edge {
        int from,to;
        T cost;
        Edge (int f, int t, T c) : from(f), to(t), cost(c) {}
    };
    
    const T INF = numeric_limits<T>::max() / 2;
    vector< vector< T > > d;
    vector< Edge > edge;
    BellmanFord (int n) : d(2,vector<T>(n)) {}
    
    void add_directed_edge(int from, int to, T cost) {
        edge.push_back(Edge(from,to,cost));
    }
    
    void init(int s) {
        for (int i = 0; i < d[0].size(); i++) d[0][i] = INF;
        d[0][s] = 0;
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < d[0].size(); j++) {
                for (int i = 0; i < edge.size(); i++) {
                    Edge e = edge[i];
                    if (d[k][e.from] != INF && d[k][e.to] > d[k][e.from] + e.cost) {
                        d[k][e.to] = d[k][e.from] + e.cost;
                    }
                }
            }
            if (k == 0) d[1] = d[0];
        }
    }
    
    bool find_negative_loop(int v) {
        return d[0][v] != d[1][v];
    }
    
    T dist(int v) {
        return d[0][v];
    }
    
};
/*
 使用方法:
 初期化:
 BellmanFord<T> bel(N);//T: 型, N: ノード数
 辺追加:
 bel.add_directed_edge(from, to, cost);
 計算開始:
 bel.init(0);
 無限負ループの存在を確認:
 bel.find_negative_loop(N-1);いくらでも経路距離が小さくできるループの存在
 最短距離:
 bel.dist(N);
 */
