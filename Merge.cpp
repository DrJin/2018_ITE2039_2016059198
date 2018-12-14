// 2016059198_진승현_A
#include <stdio.h>

void Merge(int* A, int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	int tmp[100000];

	//tmp = (int*)malloc(sizeof(int)*(right-left+1));
	while (i <= mid && j <= right) { //순서대로 좌우의 크기를 비교
		if (A[i] <= A[j])
			tmp[k] = A[j++];
		else
			tmp[k] = A[i++];
		k++;
	}
	while (j <= right) //남은 부분
		tmp[k++] = A[j++];
	while (i <= mid)
		tmp[k++] = A[i++];

	for (i = left; i <= right; i++)
		A[i] = tmp[i];

}

void MergeSort(int* A, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2; //q는 중간값
		MergeSort(A, p, q); //Left Side
		MergeSort(A, q + 1, r); //Right Side
		Merge(A, p, q, r); //합치기
	}

}


int main() {
	int N;
	int i = 0, j = 0;

	int numbers[100000];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", numbers + i);

	MergeSort(numbers, 0, N - 1);
	for (i = 0; i < N; i++)
		printf("%d\n", numbers[i]);
	printf("\n");

}