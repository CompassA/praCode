#include <stdio.h>

void mySort(int *num, int length) {
    for (int i = 0; i < length; ++i) {
    	int minIndex = i;
		for (int j = i + 1; j < length; ++j) {
			if (num[j] < num[minIndex]) {
				minIndex = j;
			}
		} 
		
		if (minIndex != i) {
			int tmp = num[i];
			num[i] = num[minIndex];
			num[minIndex] = tmp;
		}
	} 
}

void print(int *num, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int *num = new int[N];
        for (int i = 0; i < N; ++i) {
            scanf ("%d", &num[i]);
        }
        
        mySort(num, N);
        print(num, N);
        delete[] num;
    }
    return 0;
}
