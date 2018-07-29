#include <stdio.h>
#include <string.h>

const int size = 100000;
char s[size];
int leftNumP[size] = {0};

int main() {
    scanf("%s", s);
    
    int lengthOfS = strlen(s);
    for (int i = 0; i < lengthOfS; ++i) {
        if (s[i] == 'P') {
            if (i > 0) leftNumP[i] = leftNumP[i-1] + 1;
            else leftNumP[i] = 1;
        } else {
            if (i > 0) leftNumP[i] = leftNumP[i-1];
            else leftNumP[i] = 0;
        }
    }
    
    int countT = 0, result = 0;
    for (int i = lengthOfS-1; i >= 0; --i) {
        if (s[i] == 'T') ++countT;
        else if (s[i] == 'A') {
            result += leftNumP[i] * countT;
            result %= 1000000007;
        }
    }
    printf("%d\n", result);
    return 0;
}
