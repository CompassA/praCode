#include <cstdio>

int month[13][2] = { {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31},
                             {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31},
							 {30, 30}, {31, 31}}; 

bool isLeap(const int &year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
} 

int main() {
	int data1, y1, m1, d1;
	int data2, y2, m2, d2;
	while (scanf("%d%d", &data1, &data2) != EOF) {
		if (data1 > data2) {
			int tmp = data1;
			data1 = data2;
			data2 = tmp;
		}
		
		int result = 1;
		y1 = data1 / 10000; m1 = data1 % 10000 / 100; d1 = data1 % 100;
		y2 = data2 / 10000; m2 = data2 % 10000 / 100; d2 = data2 % 100;
	
		while (y1 < y2 || m1 < m2 || d1 < d2) {
			++d1;
			++result;
			
			if (d1 == month[m1][isLeap(y1)] + 1) {
				d1 = 1;
				++m1;
			}
			if (m1 == 13) {
				m1 = 1;
				++y1;
			}
		}
		
		printf("%d\n", result);
	}
	
	return 0;
}
