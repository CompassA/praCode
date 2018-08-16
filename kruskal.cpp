#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int s, e, w;
    Edge(const int &_s, const int &_e, const int &_w):
        s(_s), e(_e), w(_w) {}
};

bool cmp(const Edge &e1, const Edge &e2) {
    return e1.w < e2.w;
}

int findFather(vector<int> &father, int x) {
    int elem = x;
    while (father[x] != x) {
        x = father[x];
    }
    while (elem != father[elem]) {
        int tmp = elem;
        elem = father[elem];
        father[tmp] = x;
    }
    return x;
}

void kruskal(vector<Edge> &adj, vector<int> &father, int &ans, bool &isConnected, const int &N) {
    int selected = 0;
    for (int i = 0; i < adj.size(); ++i) {
        Edge curEdge = adj[i];
        int fatherA = findFather(father, curEdge.s);
        int fatherB = findFather(father, curEdge.e);
        if (fatherA != fatherB) {
            father[fatherA] = fatherB;
            ans += curEdge.w;
            ++selected;
            if (selected == N-1) return;
        } 
    }
    if (selected != N - 1) isConnected = false;
}

int main() {
    int N, M;
    while (scanf("%d %d", &M, &N), M != 0) {
        int s, e, w;
        vector<Edge> adj;
        vector<int> father(N+1);
        for (int i = 1; i <= N; ++i) father[i] = i;
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &s, &e, &w);
            adj.push_back(Edge(s, e, w));
        } 
        sort(adj.begin(), adj.end(), cmp);
        int ans = 0;
        bool isConnected = true;
        kruskal(adj, father, ans, isConnected, N);
        if (isConnected) printf("%d\n", ans);
        else printf("?\n");
    }
    return 0;
}
