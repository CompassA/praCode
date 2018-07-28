#include <stdio.h>
#include <vector>
using namespace std;

int main() {
 	int N, M;
	while (scanf("%d", &N) != EOF) {
		vector<int> result;
		vector<int> data(N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &data[i]);
		}
		
		scanf("%d", &M);
		for (int i = 0; i < M; ++i) {
			int sum1 = 0, sum2 = 0;
			int start, end;
			scanf("%d%d", &start, &end);
			--start; --end;
			
			for (int j = start; j != end; j = (j + 1) % N) {
				sum1 += data[j];
			}
			//printf("%d\n",sum1);
			
			for (int j = end; j != start; j = (j + 1) % N) {
				sum2 += data[j];
			}
			//printf("%d\n",sum2);
			
			result.push_back(sum1 < sum2 ? sum1 : sum2);
		}
		
		for (int i = 0; i < result.size(); ++i) {
			printf("%d\n", result[i]);
		}
	}
	return 0;
}
