#include <stdio.h>
#include <vector>
using namespace std;

const int INF = 1000000000;

void floyd(const int &nodeNum, vector<vector<int>> &d) {
    for (int k = 0; k < nodeNum; ++k) {
        for (int i = 0; i < nodeNum; ++i) {
            for (int j = 0; j < nodeNum; ++j) {
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j]) 
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<vector<int>> d(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int dis;
                scanf("%d", &dis);
                if (i == j) d[i][j] = 0;
                else if (dis == 0) d[i][j] = INF;
                else d[i][j] = dis;
            }
        }
        floyd(n, d);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][j] == INF) printf("-1");
                else printf("%d", d[i][j]);
                if (j == n-1) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
