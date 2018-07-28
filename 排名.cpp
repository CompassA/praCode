#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct student {
	char regis[16];
	int lNumber;
	int lRank;
	int score;
};

bool cmp(const student &s1, const student &s2) {
	if (s1.score != s2.score) return s1.score > s2.score;
	else return strcmp(s1.regis, s2.regis) < 0;
}

int main() {
	int N, K;
	vector<student> stu;
	
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &K);
		for (int j = 0; j < K; ++j) {
			student s;
			scanf("%s %d", s.regis, &s.score);
			s.lNumber = i;
			stu.push_back(s);
		}
		
		sort(stu.end() - K, stu.end(), cmp);
		
		//дя╣Ц 
		(*(stu.end() - K)).lRank = 1;
		for (int j = stu.size() - K + 1; j < stu.size(); ++j) {
			if (stu[j].score != stu[j-1].score) stu[j].lRank = j + 1 - ( stu.size() - K);
			else stu[j].lRank = stu[j-1].lRank;
		}
	}
	
	sort(stu.begin(), stu.end(), cmp);
	
	printf("%d\n", stu.size());
	
	int r = 1;
	for (int i = 0; i < stu.size(); ++i) {
		if (i > 0 && stu[i].score != stu[i-1].score) r = i + 1;
		if (i < stu.size() - 1) printf("%s %d %d %d\n", stu[i].regis, r, stu[i].lNumber, stu[i].lRank);	
		else printf("%s %d %d %d", stu[i].regis, r, stu[i].lNumber, stu[i].lRank);
	}
	
	return 0;
}
