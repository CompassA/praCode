#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;

struct node {
    double num;
    char op;
    bool isNum;
    node(): num(0) {}
};

stack<node> s;
queue<node> q;
map<char, int> opOrder { {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1} };

void change(const string &data) {
    for (int i = 0; i < data.size(); /**/) {
        node tmp;
        if (data[i] >= '0' && data[i] <= '9') {
            tmp.isNum = true;
            
            while (data[i] >= '0' && data[i] <= '9') {
                tmp.num = tmp.num * 10 + (data[i] - '0');
                ++i;
            }
            
            q.push(tmp);
        } else {
            tmp.op = data[i];
            tmp.isNum = false;
            ++i;
            
            while (!s.empty() && opOrder[s.top().op] >= opOrder[tmp.op]) {
                q.push(s.top());
                s.pop();
            }
            
            s.push(tmp);
        }
    }
    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

double calc() {
    stack<double>  opNum;
    
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        
        if (tmp.isNum) {
            opNum.push(tmp.num);
        } else {
            double num2 = opNum.top();
            opNum.pop();
            double num1 = opNum.top();
            opNum.pop();
            
            switch (tmp.op) {
                case '+':
                    opNum.push(num1 + num2);
                    break;
                case '-':
                    opNum.push(num1 - num2);
                    break;
                case '*':
                    opNum.push(num1 * num2);
                    break;
                case '/':
                    opNum.push(num1 / num2);
                    break;
            }
        }
    }
    
    return opNum.top();
}

int main() {
    string data;
    while (getline(cin, data), data != "0") {
        for (string::iterator it = data.end(); it != data.begin(); --it) {
            if (*it == ' ') data.erase(it);
        }
        while (!s.empty()) s.pop();
        change(data);
        printf("%.2f\n", calc());
    }
    return 0;
}
