#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 101;
const int INF = 1000000000;
int G[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};

void init() {
    for (int i = 1; i <= MAXN; ++i) {
        visited[i] = false;
        for (int j = i; j <= MAXN; ++j) {
            G[i][j] = G[j][i] = 0;
        }
    }
}
void prim(vector<int> &d, int &ans, const int &N) {
    for (int i = 0; i < N; ++i) {
        int u = -1, MIN = INF;
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && d[i] < MIN) {
                u = i;
                MIN = d[i];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        ans += MIN;
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && G[u][i] != INF && G[u][i] < d[i]) {
                d[i] = G[u][i];
            }
        }
    }
}

int main() {
    int N;
    while (scanf("%d", &N), N != 0) {
        init();
        int M = N * (N-1) / 2;
        for (int i = 0; i < M; ++i) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            G[a][b] = G[b][a] = w;
        }
        vector<int> d(N+1, MAXN);
        d[1] = 0;
        int ans = 0;
        prim(d, ans, N);
        printf("%d\n", ans);
    }
    return 0;
} 
