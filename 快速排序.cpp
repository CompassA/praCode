#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int partition(vector<int> &nums, int left, int right) {
	int p = round(1.0*rand()/RAND_MAX*(right-left)+left);
	swap(nums[p], nums[left]);
	int tmp = nums[left];
	while (left < right) {
		while (left < right && nums[right] > tmp) --right;
		nums[left] = nums[right];
		while (left < right && nums[left] <= tmp) ++left;
		nums[right] = nums[left];
	}
	nums[left] = tmp;
	return left;
}

void quickSort(vector<int> &nums, int left, int right) {
	if (left < right) {
		int pos = partition(nums, left, right);
		quickSort(nums, left, pos - 1);
		quickSort(nums, pos+1, right);
	}
}

int main() {
	srand((unsigned)time(NULL));
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);
		quickSort(nums, 0, n-1);
		for (int i = 0; i < n; ++i) printf("%d\n", nums[i]);
	}
	return 0;
} 
