#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

vector<int> occur(9, 0);

void generate(vector<int> &P, vector<vector<int> > &result, const int &index, const int &target, int &count) {
	if (index == 8) {
		++count;
		if (count == target) result.push_back(P);
		return;
	}
	
	for (int i = 1; i <= 8; ++i) {
		if (occur[i] == 0) {
			bool flag = true;
			for (int j = 0; j < index; ++j) {
				if (abs(index - j) == abs(P[j] - i)) {
					flag = false;
					break;
				}
			}
			
			if (flag) {
				P.push_back(i);
				occur[i] = 1;
				generate(P, result, index + 1, target, count);
				P.pop_back();
				occur[i] = 0;
			}
		}
	}
}

int main() {
	int n, N;
	while (scanf("%d", &N) != EOF) {
		vector<vector<int> > result;
		
		for (int k = 0; k < N; ++k) {
			scanf("%d", &n);
			vector<int> P;
			int count = 0;
			generate(P, result, 0, n, count);
		}
		
		for (int i = 0; i < result.size(); ++i) {
				for (int j = 0; j < result[i].size(); ++j) {
					printf("%d", result[i][j]);
				}
				printf("\n");
			}
	}
	
	return 0;
}
