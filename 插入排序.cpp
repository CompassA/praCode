#include <stdio.h>

void mySort(int *num, int length) {
    for (int i = 1; i < length; ++i) {
        int tmp = num[i], j = i - 1;
        while (j >= 0 && num[j] > tmp) {
            num[j+1] = num[j];
            --j;
        }
        num[j+1] = tmp;
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
