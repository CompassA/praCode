#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int> > f(n+1, vector<int>(n+1, 0));
    for (int x = 1; x <= n; ++x) f[x][0] = 1;
    for (int y = 1; y <= n; ++y) {
        for (int x = y; x <= n; ++x) {
            f[x][y] = f[x-1][y] + f[x][y-1];
        }
    }
    printf("%d", f[n][n]);
    return 0;
} 
