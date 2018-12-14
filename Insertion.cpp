// 2016059198_Áø½ÂÇö_A
#include <stdio.h>

int main() {
	int N;
	int i=0, j=0;
	int numbers[30000];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", numbers + i);
	for (i = 0; i < N; i++){
		for (j = 0; j < i; j++) {
			if (numbers[i] >= numbers[j]) {
				int tmp;
				tmp = numbers[j];
				numbers[j] = numbers[i];
				numbers[i] = tmp;
			}
		}
	}
	for (i = 0; i < N; i++)
		printf("%d\n", numbers[i]);
	return 0;
}