#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

struct Factor {
	int x, n;
	Factor(const int &_x):
		x(_x), n(0) {}
};

vector<int> prime;
vector<Factor> result;
vector<int> nums(100001, 0);

int main() {
	//构造素数表
	for (int i = 2; i < nums.size(); ++i) {
		if (nums[i] == 0) {
			for (int j = i + i; j < nums.size(); j += i) nums[j] = 1;
			prime.push_back(i);
		}
	}
	
	int N, Ncopy;
	scanf("%d", &N);
	if (N==1) {
		printf("1=1\n");
		return 0; 
	}
	int limit = (int)sqrt(1.0 * N);
	Ncopy = N;
	
	for (int i = 0; i < prime.size() && prime[i] <= limit; ++i) {
		if (N % prime[i] == 0) {
			result.push_back(Factor(prime[i]));
			
			while (N % prime[i] == 0) {
				++result[result.size()-1].n;
				N /= prime[i];
			}
		}
	}
	
	if (N != 1) {
		result.push_back(Factor(N));
		++result[result.size()-1].n;
	}
	
	int size = result.size() - 1;
	printf("%d=", Ncopy); 
	for (int i = 0; i <= size; ++i) {
		if (result[i].n == 1) printf("%d", result[i].x);
		else printf("%d^%d", result[i].x, result[i].n);
		
		if (i == size) printf("\n");
		else printf("*");
	}
	
	return 0;
} 
