#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> strmonth = { {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
						   {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8}, 
						   {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12} };

map<int, string> strweek = {
	{1, "Monday"},{2, "Tuesday"}, {3, "Wednesday"}, {4, "Thursday"}, {5, "Friday"}, {6, "Saturday"}, {7, "Sunday"}
};

const int month[13][2] = {
	{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30},
	   		{31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31},
};

int d1 = 16, m1 = 7, y1 = 2018;
int result = 1;

bool isLeap(const int &year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
	int d2, y2;
	string M2;
	while (cin >> d2 >> M2 >> y2) {
		int m2 = strmonth[M2];
		int today = y1 * 10000 + m1 * 100 + d1;
		int target = y2 * 10000 + m2 * 100 + d2;
		
		if (target < today) {
			while (y1 > y2 || m1 > m2 || d1 > d2) {
				--result;
				--d1;
				
				if (d1 == 0) {
					--m1;
					if (m1 == 0) {
						m1 = 12;
						--y1;
					}
					d1 = month[m1][isLeap(y1)];
				}
				//cout << y1 << " " << m1 << " " << d1 << endl;
				if (result == 0) result = 7;
			}
			
		} else {
			while (y1 < y2 || m1 < m2 || d1 < d2) {
				++d1;
				++result;
				
				if (d1 == month[m1][isLeap(y1)]+ 1) {
					d1 = 1;
					m1++;
				}
				if (m1 == 13) {
					m1 = 1;
					++y1;
				}
				
				if (result == 8) result = 1;
			}
			
		}
		
		cout << strweek[result] << endl;
	}
	
	return 0;
}
