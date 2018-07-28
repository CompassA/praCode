#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

vector<int> data;

void merge(vector<int> &nums, const int &L1, const int &R1, const int &L2, const int &R2) {
	int i = L1, j = L2, index = 0;
	vector<int> sortedNums(R2 - L1 + 1);
	while (i <= R1 && j <= R2) {
		if (nums[i] < nums[j]) sortedNums[index++] = nums[i++];
		else sortedNums[index++] = nums[j++];
	}
	while (i <= R1) sortedNums[index++] = nums[i++];
	while (j <= R2) sortedNums[index++] = nums[j++];
	
	for (int i = 0; i < index; ++i) nums[i+L1] = sortedNums[i];
}

void mySort(vector<int> &nums, const int &left, const int &right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mySort(nums, left, mid);
		mySort(nums, mid + 1, right);
		merge(nums, left, mid, mid + 1, right);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	while (n--) {
		vector<int> empty;
		data.swap(empty);
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; ++i) {
			int m;
			scanf("%d", &m);
			data.push_back(m);
		}
		
		mySort(data, 0, data.size()-1);
		
		for (int i = 0; i < data.size(); ++i) {
			printf("%d\n", data[i]);
		}
	}
	return 0;
} 
