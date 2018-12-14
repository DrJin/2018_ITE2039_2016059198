//2016059198_진승현_A
#include <stdio.h>

int main() {
	int N, M, K;
	int* A;
	int* B;
	int* Count;
	int* keys;
	scanf("%d %d %d", &N, &M, &K);
	Count = new int[M]();
	keys = new int[N];
	A = new int[K];
	B = new int[K];
	for (int i = 0; i < K; i++)
		scanf("%d %d", &A[i], &B[i]);
	for (int i = 0; i < N; i++) {
		scanf("%d", &keys[i]);
		Count[keys[i]]++;//counting
	}

	//누적합
	for (int i = 1; i <= M; i++)
		Count[i] += Count[i - 1];
	for (int i = 0; i < K; i++) {
		printf("%d\n", Count[B[i]] - Count[A[i] - 1]);
	}
	return 0;
}