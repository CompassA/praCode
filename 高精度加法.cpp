#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct bign {
	friend bign operator+(const bign &n1, const bign &n2);
	
	int num[1001];
	int len;
	
	bign(): len(0) {
		fill(num, num + 1001, 0);
	}
	
	void print() {
		for (int i = len-1; i >= 0; --i) {
			printf("%d", num[i]);
		}
		printf("\n");
	}
};

char s1[1001], s2[1001];

void change(char *num, bign &out) {
	int sLen = strlen(num);
	for (int i = sLen - 1; i >= 0; --i) {
		out.num[out.len++] = num[i] - '0';
	}
}

bign operator+(const bign &n1, const bign &n2) {
	bign result;
	
	int c = 0;
	for (int i = 0; i < n1.len || i < n2.len; ++i) {
		int tmp = n1.num[i] + n2.num[i] + c;
		result.num[result.len++] = tmp % 10;
		c = tmp / 10;
	}
	
	if (c) {
		result.num[result.len++] = c;
	}

	return result;
}

int main() {
	while (scanf("%s%s", s1, s2) != EOF) {
		bign d1, d2;
		change(s1, d1);
		change(s2, d2);
		bign result = d1 + d2;
		result.print();
	}
	return 0;
}
