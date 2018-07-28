#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std; 

int main() {
	vector<int> data;
	int N;
	
	while (scanf("%d", &N), N != 0) {
		vector<int> nums(N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &nums[i]);
		}
		
		sort(nums.begin(), nums.end());
		
		if (N & 1) data.push_back(nums[N/2]);
		else data.push_back((nums[N/2] + nums[N/2-1]) / 2);
	}
	
	for (int i = 0; i < data.size(); ++i) {
		printf("%d\n", data[i]);
	}
	return 0;
}
