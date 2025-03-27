#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct DSU{
    vector <int> p, siz; // 父节点，集合大小

    DSU(int n){
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x){
        if (x != p[x]){
            p[x] = find(p[x]);
        }
        return p[x];
    }

    bool merge(int x, int y){
        x = find(x), y = find(y);
        if (x == y){
            return true;
        }
        siz[y] += siz[x];
        p[x] = y;
        return false;
    }

    int size(int x){
        return siz[find(x)];
    }
};