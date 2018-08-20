#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <unordered_map> 
using namespace std;

struct Edge {
    int v, w;
    Edge(const int &_v, const int &_w): v(_v), w(_w) {}
};

int getID(unordered_map<char, int> &ID, const char &name, int &seed) {
    if (ID.find(name) != ID.end()) return ID[name];
    else {
        ID[name] = seed;
        return seed++;
    }
}
 
void topologicalSort(vector<vector<Edge>> &adj, vector<int> &inDegree, unordered_map<int, char> &ID) {
    vector<int> ve(inDegree.size(), 0);
    stack<int> s;
    queue<int> q;
    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        s.push(u);
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].v;
            if (--inDegree[v] == 0) {
                q.push(v);
            }
            if (ve[u] + adj[u][i].w > ve[v]) ve[v] = ve[u] + adj[u][i].w;
        }
    }
    int max = -1;
    for (int i = 0; i < ve.size(); ++i) {
        if (max < ve[i]) max = ve[i];
    }
    vector<int> vl(inDegree.size(), max);
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].v;
            if (vl[u] > vl[v] - adj[u][i].w) vl[u] = vl[v] - adj[u][i].w;
        }
    }
    
    for (int u = 0; u < adj.size(); ++u) {
        for (int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j].v;
            int e = ve[u], l = vl[v]-adj[u][j].w;
            if (e == l) {
                printf("(%c,%c) ", ID[u], ID[v]);
            }
        }
    }
    printf("%d\n", max);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        while (n--) {
            int x, y;
            scanf("%d%d", &x, &y);
            vector<vector<Edge>> adj(x);
            unordered_map<char, int> ID;
            unordered_map<int, char> getIndex;
            vector<int> inDegree(x, 0);
            int seed = 0;
            while (getchar() != '\n');
            for (int i = 0; i < x; ++i) {
                char c = getchar();
                getIndex[seed] = c;
                getID(ID, c, seed);
            }
            while (getchar() != '\n');
            for (int i = 0; i < y; ++i) {
                char a, b;
                int w; 
                scanf("%c %c %d", &a, &b, &w);
                while (getchar() != '\n');
                int aID = getID(ID, a, seed);
                int bID = getID(ID, b, seed);
                adj[aID].push_back(Edge(bID, w));
                ++inDegree[bID];
            }
            topologicalSort(adj, inDegree, getIndex);
        }
    }
    return 0;
}
