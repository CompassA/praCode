#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
/*int nums[n];
scanf("%d", &n);
for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);

输入 3     1 2 3 （按回车） 
和
输入 3 (按回车)
	 1 2 3
	 （按回车） 
有区别吗？ 
*/ 
int partition(vector<int> &nums, int left, int right) {
	int p = round(1.0*rand()/RAND_MAX*(right-left)+left);
	swap(nums[p], nums[left]);
	int tmp = nums[left];
	
	while (left < right) {
		while (left < right && nums[right] <= tmp) --right;
		nums[left] = nums[right];
		while (left < right && nums[left] > tmp) ++left;
		nums[right] = nums[left];
	}
	nums[right] = tmp;
	
	return right;
} 

int findK(vector<int> &nums, const int &left, const int &right, const int &K) {
	if (left == right) return nums[left];
	int pos = partition(nums, left, right), rank = pos - left + 1;
	
	if (K == rank) return nums[pos];
	else if (K > rank) return findK(nums, pos+1, right, K-rank);
	else return findK(nums, left, pos-1, K);
}

int main() {
	srand((unsigned)time(NULL));
	int K, N;
	
	while (scanf("%d%d", &N, &K) != EOF) {
		vector<int> input(N);
		for (int i = 0; i < N; ++i) scanf("%d", &input[i]);
		
		printf("%d\n", findK(input, 0, N-1, K));
	}
	
	return 0; 
} 
