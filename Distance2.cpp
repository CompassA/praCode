#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
 	int N, M;
	while (scanf("%d", &N) != EOF) {
		vector<int> result;
		vector<int> data(N);
		vector<int> dis(N + 1);
		
		dis[0] = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &data[i]);
			dis[i+1] = dis[i] + data[i];
		}
		
		scanf("%d", &M);
		for (int i = 0; i < M; ++i) {
			int sum1 = 0, sum2 = 0;
			int start, end;
			scanf("%d%d", &start, &end);
			--start; --end;
			
			if (start > end) swap(start, end);
			sum1 = dis[end] - dis[start];
			sum2 = dis[N] - sum1;
			result.push_back(sum1 < sum2 ? sum1 : sum2);
		}
		
		for (int i = 0; i < result.size(); ++i) {
			printf("%d\n", result[i]);
		}
	}
	return 0;
}
