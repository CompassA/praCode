#include <stdio.h>
#include <string.h>

void remove(char *str, const char &c) {
	int i = 0;
	while (str[i] != '\0') {
		if (c == str[i]) {
			for (int j = i; str[j] != '\0'; ++j) {
				str[j] = str[j + 1];
			}
		} else {
			++i;
		}
	}
}

int main() {
	char input[10000], c;
	while (gets(input)) {
		c = getchar();
		getchar();
		remove(input, c);
		printf("%s\n", input);
	}
	return 0;
} 
