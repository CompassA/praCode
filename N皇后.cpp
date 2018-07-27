#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void generate(vector<int> &P, vector<int> &occur, const int &index, const int &n, int &count) {
	if (index == n) {
		++count;
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (occur[i] == 0) {
			bool isOK = true;
			for (int j = 0; j < index; ++j) {
				if (abs(j - index) == abs(P[j] - i)) {
					isOK = false;
					break;
				}
			}
			
			if (isOK) {
				occur[i] = 1;
				P.push_back(i);
				generate(P, occur, index+1, n, count);
				occur[i] = 0;
				P.pop_back(); 
			}
		}
	}
}

int main() {
	for (int i = 8; i <= 17; ++i) {
		vector<int> P, occur(20, 0);
		int count = 0;
		generate(P, occur, 0, i, count);
		printf("%d  %d\n", i, count);
	}
	return 0;
} 
