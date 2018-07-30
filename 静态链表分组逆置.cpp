#include <stdio.h>
#include <vector>
using namespace std;

struct node {
    int address, data, next;
    bool valid;
    node():valid(false) {}
}; 

vector<node> list(100010);

int main() {
    int headAddress, N, K;
    scanf("%d%d%d", &headAddress, &N, &K);
    for (int i = 0; i < N; ++i) {
        int inAddress;
        scanf("%d", &inAddress);
        list[inAddress].address = inAddress;
        scanf("%d%d", &list[inAddress].data, &list[inAddress].next);
    }
    
    int count = 0;
    for (int i = headAddress; i != -1; i = list[i].next) ++count;
    
    int times = count / K, nextHead = headAddress, nextHeadPrior = -1;
    for (int j = 0; j < times; ++j) {
        int p = nextHead, q = list[p].next, r = list[p].next;
        for (int i = 0; i < K-1; ++i) {
            r = list[q].next;
            list[q].next = p;
            p = q;
            q = r;
        }
        if (j == 0) {
            list[headAddress].next = q;
            nextHeadPrior = headAddress;
            headAddress = p;
            nextHead = q;
        } else {
            list[nextHeadPrior].next = p;
            list[nextHead].next = q;
            nextHeadPrior = nextHead;
            nextHead = q;
        }
    }
    for (int i = headAddress; i != -1; i = list[i].next) {
        if (list[i].next != -1) printf("%05d %d %05d\n", list[i].address, list[i].data, list[i].next);
        else printf("%05d %d %d", list[i].address, list[i].data, list[i].next);
    }
    return 0;
}
