//2016059198_Áø½ÂÇö_A
#include <stdio.h>

void rodCutting(int n, int* price, int& max_price, int *(&length)) {
	int *r;
	r = new int[n + 1];

	r[0] = 0;
	length[0] = 0;
	for (int i = 1; i <= n; i++) {
		int q = -1;
		for (int j = 1; j <= i; j++) {
			if (q < price[j] + r[i - j]) {
				q = price[j] + r[i - j];
				length[i] = j;
			}
			r[i] = q;
		}
	}
	for (int i = 1; i <= n; i++)
		if (r[i] > max_price)
			max_price = r[i];

	delete[] r;
}

int main() {
	int N;
	int* price;
	int max_price = 0;
	int* length;
	scanf("%d", &N);
	price = new int[N + 1];
	length = new int[N + 1];
	price[0] = 0;
	for (int i = 1; i <= N; i++)
		scanf("%d", &price[i]);
	rodCutting(N, price, max_price, length);
	printf("%d\n", max_price);
	for (int i = N; i > 0; i = i - length[i])
		printf("%d ", length[i]);

	delete[] length;
	delete[] price;
	return 0;
}