#include <iostream>
#include <string>
using namespace std;

string standardlized(string s, const int &N, int &e) {
    int lengthOfInt = 0;
    while (s.length() > 0 && s[0] == '0') s.erase(s.begin());
    
    if (s.length() > 0 && s[0] == '.') {
        s.erase(s.begin());
        while (s.length() > 0 && s[0] =='0') {
            s.erase(s.begin());
            --e;
        }
    } else {
        while (lengthOfInt < s.length() && s[lengthOfInt] != '.') {
            ++e;
            ++lengthOfInt;
        }
        if (lengthOfInt < s.length()) s.erase(s.begin()+lengthOfInt);
    }
    
    if (s.length() == 0) e = 0;
    
    string result("");
    for (int i = 0; i < N; ++i) {
        if (i < s.length())  result += s[i];
        else result += '0';
    }
    return result;
}

int main() {
    int N, eA = 0, eB = 0;
    string A, B;
    cin >> N >> A >> B;
    string sA = standardlized(A, N, eA);
    string sB = standardlized(B, N ,eB);
    
    if (sA == sB && eA == eB) {
        cout<<"YES 0."<<sA<<"*10^"<<eA<<endl;
    } else {
        cout<<"NO 0."<<sA<<"*10^"<<eA<<" 0."<<sB<<"*10^"<<eB<<endl;
    }
    
    return 0;
} 
