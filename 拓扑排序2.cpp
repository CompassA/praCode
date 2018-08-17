#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 50;
int G[MAXN][MAXN] = {0};
int inDegree[MAXN] = {0};

void init(int MAXN) {
    for (int i = 0; i < MAXN; ++i) inDegree[i] = 0;
}

bool topologicalSort(int n, vector<int> &path) {
    stack<int> q;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int v = q.top();
        q.pop();
        path.push_back(v);
        ++cnt;
        for (int i = 0; i < n; ++i) {
            if (G[v][i] != 0) {
                G[v][i] = 0;
                if ( (--inDegree[i]) == 0 ) q.push(i);
            }
        }
    }
    if (cnt == n) return true;
    else return false;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        init(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &G[i][j]);
                if (G[i][j] == 1) ++inDegree[j];
            }
        }
        vector<int> path;
        if (topologicalSort(n, path)) {
            for (int i = 0; i < path.size(); ++i) {
                if (i == path.size()-1) printf("%d\n", path[i]);
                else printf("%d ", path[i]);
            }
        } else {
            printf("ERROR\n");
        }
    }
    return 0;
}
