#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;

/*
题目描述
        输入一个字符串，求出其中最长的回文子串。子串的含义是：在原串中连续出现的字符串片段。回文的含义是：正着看和倒着看相同。如abba和yyxyy。在判断回文时，应该忽略所有标点符号和空格，且忽略大小写，但输出应保持原样（在回文串的首部和尾部不要输出多余字符）。输入字符串长度不超过5000，且占据单独的一行。应该输出最长的回文串，如果有多个，输出起始位置最靠左的。

输入
一行字符串，字符串长度不超过5000。

输出
字符串中的最长回文子串。

样例输入
Confuciuss say:Madam,I'm Adam.
样例输出
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
