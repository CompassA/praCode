#include <stdio.h>
#include <limits.h> 
#include <set>
using namespace std;

const int size = 100000;
int data[size] = {0};
int left[size] = {0};

set<int> result;

int main() {
    int N;
    scanf("%d", &N);
    
    int leftMax = INT_MIN;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &data[i]);
        if (leftMax < data[i]) {
            left[i] = 1;
            leftMax = data[i];
        }
    }
    
    int rightMin = INT_MAX; 
    for (int i = N-1; i >= 0; --i) {
        if (data[i] < rightMin) {
            if (left[i] == 1)   result.insert(data[i]);
            rightMin = data[i];
        }
    }
    
    int count = 0;
    printf("%d\n", result.size());
    for (set<int>::iterator i = result.begin(); i != result.end(); ++i) {
        printf("%d", *i);
        ++count;
        if (count != result.size()) putchar(' ');
        else putchar('\n');
    }
    if (result.size() == 0) putchar('\n');
    return 0;
}
