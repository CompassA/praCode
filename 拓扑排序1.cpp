#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct Vode {
    int inDegree = 0;
    vector<int> adj;
};

void topologicalSort(vector<int> &path, Vode *G, int n) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        if (G[i].inDegree == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.top();
        path.push_back(v);
        q.pop();
        for (int i = 0; i < G[v].adj.size(); ++i) {
            int u = G[v].adj[i];
            if (--G[u].inDegree == 0) {
                q.push(u);
            }
        }
    }
}

int main() {
    int N, M;
    while (scanf("%d%d", &N, &M), N != 0) {
        Vode G[N+1];
        for (int i = 0; i < M; ++i) {
            int s, e;
            scanf("%d %d", &s, &e);
            G[s].adj.push_back(e);
            ++G[e].inDegree;
        }
        vector<int> path;
        topologicalSort(path, G, N);
        for (int i = 0; i < path.size(); ++i) {
            if (i == path.size()-1) printf("%d\n", path[i]);
            else printf("%d ", path[i]);
        }
    }
    return 0;
}
