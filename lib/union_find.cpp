struct UnionFind {
    vi data;
    UnionFind(int n) : data(n, -1) {}
    
    int find(int x) {
        if (data[x] < 0) return x;
        return data[x] = find(data[x]);
    }
    
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    int size(int x) {
        return -data[find(x)];
    }
};
