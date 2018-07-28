#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool cmp(const int &i1, const int &i2) {
	return i1 > i2;
}

int main() {
	int m;
	while (scanf("%d", &m) != EOF) {
		vector<int> data;
		vector<vector<int> > array(m, vector<int>(m));
		
		for (int i = 0; i < m; ++i) {
			int rowSum = 0;
			for (int j = 0; j < m; ++j) {
				scanf("%d", &array[i][j]);
				rowSum += array[i][j];
			}
			data.push_back(rowSum);
		}
		
		for (int col = 0; col < m; ++col) {
			int colSum = 0;
			for (int i = 0; i < m; ++i) {
				colSum += array[i][col];
			}
			data.push_back(colSum);
		}
		
		int xSum = 0;
		for (int i = 0; i < m; ++i) {
			xSum += array[i][i];
		}
		data.push_back(xSum);
		
		int ySum = 0;
		for (int i = 0; i < m; ++i) {
			ySum += array[i][m-1-i];
		}
		data.push_back(ySum);
		
		sort(data.begin(), data.end(), cmp);
		
		for (int i = 0; i < data.size(); ++i) {
			printf("%d", data[i]);
			if (i < data.size() - 1) printf(" ");
			else printf("\n");
		}
	}
	
	return 0;
}
