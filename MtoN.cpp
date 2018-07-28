#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int myStoi(const char &c) {
	if ( c >= '0' && c <= '9' ) return c - '0';
	else if ( c >= 'A' && c <= 'Z' ) return c - 'A' + 10;
}

char myItos(const int &n) {
	if (n < 10) return '0'+n;
	else return 'a'+n-10;
}

struct bign {
	int num[1500];
	int len;
	
	bign():len(0) {fill(num, num+1500, 0);}
	
	void print() {
		for (int i = len-1; i >=0; --i) printf("%c", myItos(num[i]));
		printf("\n");
	}
};

bign getBign(char *input) {
	bign result;
	int sLen = strlen(input);
	for (int i = sLen-1; i >= 0; --i) 
		result.num[result.len++] = myStoi(input[i]);
	return result;
}

bool isZero(const bign& d) {
	return d.len == 1 && d.num[d.len-1] == 0;
}

bign divide(const bign &d, const int &M, const int &N, int &r) {
	bign result;
	result.len = d.len;
	for (int i = d.len-1; i >=0; --i) {
		r = r * M + d.num[i];
		if ( r < N ) result.num[i] = 0;
		else {
			result.num[i] = r / N;
			r %= N;
		}
	}
	while ( result.len-1 >= 1 && result.num[result.len-1] == 0 ) --result.len;
	return result;
}

int main() {
	int M, N;
	while (scanf("%d%d", &M, &N) != EOF) {
		char X[100];
		scanf("%s", X);
		bign numM = getBign(X), numN;
		do {
			int r = 0;
			numM = divide(numM, M, N, r);
			numN.num[numN.len++] = r;
		} while ( !isZero(numM) );
		numN.print();
	}
	return 0;
}
