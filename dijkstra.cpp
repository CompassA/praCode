#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 1001;
const int INF = 1000000000;
int G[MAXN][MAXN] = {0};
int cost[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};

void init() {
    for (int i = 1; i < MAXN; ++i) {
        visited[i] = false;
        for (int j = 1; j < MAXN; ++j) {
            G[i][j] = 0;
            cost[i][j] = 0;
        }
    }
}

void dijkstra(vector<vector<int>> &pre, vector<int> &d, const int &s, const int &nodeNum) {
    d[s] = 0;
    for (int i = 0; i < nodeNum; ++i) {
        int u = -1, MIN = INF;
        for (int i = 1; i <= nodeNum; ++i) {
            if (!visited[i] && d[i] < MIN) {
                u = i;
                MIN = d[i];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int i = 1; i <= nodeNum; ++i) {
            if (!visited[i] && G[u][i] != 0) {
                int newDis = d[u] + G[u][i];
                if (newDis < d[i]) {
                    d[i] = newDis;
                    pre[i].clear();
                    pre[i].push_back(u);
                } else if (newDis == d[i]) {
                    pre[i].push_back(u);
                }
            }
        }
    }
}

void DFS(vector<vector<int>> &pre, vector<int> &tmpPath, 
        const int &curID, const int &s, int &minCost)
{
    if (curID == s) {
        tmpPath.push_back(curID);
        int curCost = 0;
        for (int i = 0; i < tmpPath.size()-1; ++i) {
            int E = tmpPath[i], S = tmpPath[i+1];
            curCost += cost[S][E];
        }
        if (curCost < minCost) {
            minCost = curCost;
        }
        tmpPath.pop_back();
        return; 
    }
    
    for (int i = 0; i < pre[curID].size(); ++i) {
        tmpPath.push_back(curID);
        DFS(pre, tmpPath, pre[curID][i], s, minCost);
        tmpPath.pop_back();
    }
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF, n != 0 && m != 0) {
        init();
        for (int i = 0; i < m; ++i) {
            int a, b, d, p;
            scanf("%d%d%d%d", &a, &b, &d, &p);
            G[a][b] = G[b][a] = d;
            cost[a][b] = cost[b][a] = p;
        }
        int s, t;
        scanf("%d%d", &s, &t);
        vector<int> d(n+1, INF);
        vector<vector<int>> pre(n+1);
        dijkstra(pre, d, s, n);
        int minCost = INF;
        vector<int> tmpPath;
        DFS(pre, tmpPath, t, s, minCost);
        printf("%d %d\n", d[t], minCost);
    }
    return 0;
}
