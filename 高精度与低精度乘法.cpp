#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct bign {
	friend bign operator*(const bign &d1, const int &d2);
	
	int num[3000];
	int len;
	
	bign(): len(0) {
		fill(num, num + 1500, 0);
	}
	
	void print() {
		for (int i = len-1; i >= 0; --i) {
			printf("%d", num[i]);
		}
		printf("\n");
	}
};

bign operator*(const bign &d1, const int &d2) {
	bign result;	
	int c = 0;
	for (int i = 0; i < d1.len; ++i) {
		int tmp = d1.num[i] * d2 + c;
		result.num[result.len++] = tmp % 10;
		c = tmp / 10;
	}
	while (c) {
		result.num[result.len++] = c % 10;
		c /= 10;
	}
	
	return result;
}

void change(int input, bign &out) {
	while (input) {
		out.num[out.len++] = input % 10;
		input /= 10;
	}
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		if (N == 0) {
			printf("1\n");
			continue;
		}
		
		bign s;
		change(N, s);
		for (int i = N-1; i > 0; --i) {
			s = s * i;
		}
		s.print();
	}
	return 0;
}
