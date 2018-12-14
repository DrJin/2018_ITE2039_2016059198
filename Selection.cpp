//2016059198_Áø½ÂÇö_A

#include <stdio.h>

void SelectionSort(int *list, int n, int m) {
	for (int i = 0; i < m; i++) {
		//find min
		int *min = &list[i];
		for (int j = i + 1; j < n; j++)
			if (*min > list[j])
				min = &list[j];
		//swap
		int tmp = *min;
		*min = list[i];
		list[i] = tmp;
	}

}

int main() {
	int n, m;
	int list[30000];

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	SelectionSort(list, n, m);

	for (int i = 0; i < n; i++)
		printf("%d\n", list[i]);
	return 0;
}
