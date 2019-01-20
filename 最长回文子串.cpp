#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;

/*
��Ŀ����
        ����һ���ַ��������������Ļ����Ӵ����Ӵ��ĺ����ǣ���ԭ�����������ֵ��ַ���Ƭ�Ρ����ĵĺ����ǣ����ſ��͵��ſ���ͬ����abba��yyxyy�����жϻ���ʱ��Ӧ�ú������б����źͿո��Һ��Դ�Сд�������Ӧ����ԭ�����ڻ��Ĵ����ײ���β����Ҫ��������ַ����������ַ������Ȳ�����5000����ռ�ݵ�����һ�С�Ӧ�������Ļ��Ĵ�������ж���������ʼλ�����ġ�

����
һ���ַ������ַ������Ȳ�����5000��

���
�ַ����е�������Ӵ���

��������
Confuciuss say:Madam,I'm Adam.
�������
Madam,I'm Adam
*/ 


vector<int> posMap;

string getStr(const string &oldVal) {
    string newVal = "";
    posMap.resize(oldVal.size());
    for (int i = 0; i < oldVal.size(); ++i) {
        if (isalpha(oldVal[i]) || isdigit(oldVal[i])) {
            newVal.push_back(tolower(oldVal[i]));
            posMap[newVal.size()-1] = i;
        }
    }
    return newVal;
}
 
int main() {
    string oldVal, newVal;
    getline(cin, oldVal);
    newVal = getStr(oldVal);
    int maxL = 1;
    int leftPos = 0, rightPos = 0;
    vector<vector<int> > dp(newVal.size(), vector<int>(newVal.size(), 0));
    for (int i = 0; i < newVal.size(); ++i) {
        dp[i][i] = 1;
        if (i < newVal.size()-1 && newVal[i] == newVal[i+1]) {
            dp[i][i+1] = 1;
            if (maxL == 1) {
                leftPos = i;
                rightPos = i + 1;
            }
            maxL = 2;
        }
    }
    for (int len = 3; len <= newVal.size(); ++len) {
        for (int i = 0; i+len-1 < newVal.size(); ++i) {
            int j = i+len-1;
            if (newVal[i] == newVal[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                if (maxL < len) {
                    leftPos = i;
                    rightPos = j;
                }
                maxL = len;
            }
        }
    }
    for (int i = posMap[leftPos]; i <= posMap[rightPos]; ++i) {
        printf("%c", oldVal[i]);
    }
    return 0;
}
