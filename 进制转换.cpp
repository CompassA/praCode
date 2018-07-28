#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int myatoi(char c) {       //char to int
    if(c >= '0' && c <= '9') return c - '0';
	else return c -'A' + 10;
}
char myitoa(int i){       //int to char
    if(i >= 0 && i <= 9) return '0'+ i;
	else return 'a'+ i - 10;
}
//模拟手动除法求余（过程类似将10进制转化成2进制） 10为M，2为N；
void m2n(char s1[],char s2[],int M,int N) {
    int data[10005],j = 0;
    for(int i = 0; i < strlen(s1); i++)
        data[i] = myatoi(s1[i]);
    while(1) {                           
        unsigned int i = 0;
        while(data[i] == 0 && i < strlen(s1)) i++;
        if(i == strlen(s1)) break;
        int yu = 0,tmp = 0;
        for(; i < strlen(s1);i++) {
            tmp = yu * M + data[i]; 
            yu = tmp%N;
            data[i] = tmp/N;
        }
        s2[j++] = myitoa(yu);
    }
    s2[j] = '\0';
    reverse(s2,s2+strlen(s2));
}

int main() {
    int M = 0,N = 0;
    char str1[1005],str2[1005];
    while(cin >> M >> N){
        cin >> str1;
        m2n(str1,str2,M,N);
        cout << str2 << endl;
    }
    return 0;
}
