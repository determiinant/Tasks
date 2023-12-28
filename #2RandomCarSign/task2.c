#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));

	char* str;
	char x[3] = {'a', 'b', '\0'};
	char y[3] = { 'a', 'b', '\0'};
	int number = rand() % 10000;

	for (int i = 0; i < strlen(x); ++i) {
		x[i] = rand() % ('Z' + 1 - 'A') + 'A';
		y[i] = rand() % ('Z' + 1 - 'A') + 'A';
	}
	for (int i = 0; i < strlen(x); ++i) {
		for (int j = 0; j < strlen(y); ++j) {
			while(x[i] == y[j])
				y[j] = rand() % ('Z' + 1 - 'A') + 'A';
		}
	}
	char formattedNumber[5];
	sprintf(formattedNumber, "%04d", number); 

	int new_size = strlen(x) + strlen(y) + strlen(formattedNumber);
	str = (char*)malloc(new_size + 1);

	if (str == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}
	str[0] = '\0';
	strcat(str, x);
	strcat(str, formattedNumber);
	strcat(str, y);
	printf("Your sign is: %s", str);
	free(str);
}