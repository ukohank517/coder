template <class T> struct Dinic {
    struct Edge {
        int to,rev; T cap;
        Edge (int t, int r, T c) : to(t), rev(r), cap(c) {}
    };

    vector < vector< Edge > > G;
    vector < int > level, iter;
    const T INF = numeric_limits < T > ::max();
    Dinic (int n) : G(n), level(n, 0), iter(n, 0) {}

    void add_edge(int from, int to, T cap) {
        G[from].push_back(Edge(to, (int)(G[to].size()), cap));
        G[to].push_back(Edge(from, (int)(G[from].size()) - 1, 0));
    }

    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue < int > que({s});

        level[s] = 0;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); i++) {
                Edge& e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    T dfs(int cur, int t, T f) {
        if (cur == t) return f;
        for (int &i = iter[cur]; i < G[cur].size(); i++) {
            Edge& e = G[cur][i];
            if (e.cap > 0 && level[e.to] > level[cur]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d == 0) continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }

    T max_flow(int s, int t) {
        T flow = 0, d;
        while (true) {
            bfs(s);
            if(level[t] < 0) break;
            fill(iter.begin(), iter.end(), 0);
            while ((d = dfs(s, t, INF)) > 0) {
                flow += d;
            }
        }
        return flow;
    }

};
/*
 O(N*N*M)
 //Usage
 Dinic<ll> D(N);
 D.add_edge(from, to , cap);
 D.max_flow(s, t);

 don't forget -std=c++11
 */
