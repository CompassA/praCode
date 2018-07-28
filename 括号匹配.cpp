#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	string data;
	stack<char> op;
	vector<string> result;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> data;
		while (!op.empty()) op.pop();
		
		bool isMatch = true;
		for (int i = 0; i < data.size(); ++i) {
			switch (data[i]) {
				case '(':
				case '[':
				case '{':
					op.push(data[i]);
					break;
				case ')':
					if (op.empty() || op.top() != '(') isMatch = false;
					else op.pop();
					break;
				case ']':
					if (op.empty() || op.top() != '[') isMatch = false;
					else op.pop();
					break;
				case '}':
					if (op.empty() || op.top() != '{') isMatch = false;
					else op.pop();
					break;
			}
		}
		
		if (!op.empty()) isMatch = false;
		result.push_back(isMatch ? "yes" : "no");
	}
	for (int i = 0; i < result.size(); ++i) cout << result[i] << endl;
	return 0;
}
