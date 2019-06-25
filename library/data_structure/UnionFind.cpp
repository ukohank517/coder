struct UnionFind {
    
    vector < int > node;
    UnionFind(int n) : node(n, -1) {}
    
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (node[y] < node[x]) swap(x, y);
            node[x] += node[y];
            node[y] = x;
        }
        return x != y;
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    
    int root(int x) {
        return node[x] < 0 ? x : node[x] = root(node[x]);
    }
    
    int size(int x) {
        return -node[root(x)];
    }
    
};
/*
 usage:
 
 初期化:
 UnionFind  UF(N);//ノードの数
 unite(x,y);// xとyノード連結
 same(a,b);// aとbが同じ所属かどうかを判別
 root(a); //aのルートのノードを計算
 */
