//2016059198_Áø½ÂÇö_A
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void max_heapify(int* A, int i, int N) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left <= N && A[left] > A[largest])
		largest = left;
	if (right <= N && A[right] > A[largest])
		largest = right;
	if (largest != i) {
		swap(A + i, A + largest);
		//swapping
		max_heapify(A, largest, N); //¼­ºê Æ®¸® Àç±Í
	}
}

void build_max_heap(int* A, int N) {
	//build_max_heap
	int i;
	for (i = (N - 1) / 2; i >= 0; i--) {
		max_heapify(A, i, N);
	}
}

void heap_sort(int* A, int N, int k) {
	int i;
	build_max_heap(A, N);
	for (i = N - 1; i >= N - k;) {
		swap(A, A + i);
		i--;
		max_heapify(A, 0, i);
	}
}

int main() {
	int N, k;
	int i;

	int numbers[100001];
	scanf("%d %d", &N, &k);
	for (i = 0; i < N; i++)
		scanf("%d", numbers + i);

	heap_sort(numbers, N, k);
	for (i = N - 1; i >= N - k; i--) {
		printf("%d ", numbers[i]);

	}
	printf("\n");
	for (i = 0; i < N - k; i++)
		printf("%d ", numbers[i]);
}
