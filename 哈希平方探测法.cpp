#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int MSize;
int searchTimes = 0;

struct Num {
    int x;
    bool isInsert;
    Num():isInsert(false) {}
};

int H(const int &num) {
    return num % MSize;
}

void myHashInsert(vector<Num> &table, const int &num) {
    int key = H(num);
    for (int i = 0; i < MSize; ++i) {
        int newKey = (key+i*i) % MSize;
        if (!table[newKey].isInsert) {
            table[newKey].x = num;
            table[newKey].isInsert = true;
            return;
        }
    }
    printf("%d cannot be inserted.\n", num);
} 

void searchHash(vector<Num> &table, const int &num) {
    int key = H(num);
    for (int i = 0; i < MSize; ++i) {
        int newKey = (key+i*i) % MSize;
        ++searchTimes;
        if (table[newKey].isInsert && table[newKey].x == num) return;
        if (!table[newKey].isInsert) return;
    }
    ++searchTimes;
}

bool isPrime(const int &num) {
    int limit = (int) sqrt(1.0*num);
    for (int i = 2; i <= limit; ++i) {
        if (num % i == 0) return false; 
    } 
    return true;
}

int main() {
    int N, M;
    scanf("%d %d %d", &MSize, &N, &M);
    while (!isPrime(MSize)) ++MSize;
    vector<Num> myHashTable(MSize);
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        myHashInsert(myHashTable, num);
    }
    for (int i = 0; i < M; ++i) {
        int num;
        scanf("%d", &num);
        searchHash(myHashTable, num);
    }
    printf("%.1f\n", searchTimes*1.0/M);
    return 0;
} 
