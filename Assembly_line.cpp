//2016059198_Áø½ÂÇö_A
#include <stdio.h>

int main() {
	int N, e1, e2, x1, x2;
	int* a[2]; //assembly time
	int* t[2]; //transfer time
	int S[2][2]; //find shortest time;
	int* L[2]; //find shortest line;
	int* Line;
	int s_time, s_line; //short time, short line


	scanf("%d", &N);

	for (int i = 0; i < 2; i++) {
		a[i] = new int[N];
		t[i] = new int[N - 1];
		L[i] = new int[N];
	}
	Line = new int[N];
	
	scanf("%d %d", &e1, &e2);
	scanf("%d %d", &x1, &x2);
	for (int i = 0; i < N; i++)		scanf("%d", &a[0][i]);
	for (int i = 0; i < N; i++)		scanf("%d", &a[1][i]);
	for (int i = 0; i < N - 1; i++)		scanf("%d", &t[0][i]);
	for (int i = 0; i < N - 1; i++)		scanf("%d", &t[1][i]);

	for (int i = 0; i < N; i++) {
		int s1, s2;
		if (i == 0) {
			S[0][i] = a[0][i] + e1;
			S[1][i] = a[1][i] + e2;
			L[0][i] = -1;
			L[1][i] = -1;
		}
		else {
			//Line 1
			s1 = s2 = a[0][i];
			s1 += S[0][(i - 1) % 2];
			s2 += S[1][(i - 1) % 2] + t[1][i-1];
			if (s1 <= s2) {
				S[0][i % 2] = s1;
				L[0][i] = 0;
			}
			else {
				S[0][i % 2] = s2;
				L[0][i] = 1;
			}

			//Line 2
			s1 = s2 = a[1][i];
			s1 += S[0][(i - 1) % 2] + t[0][i-1];
			s2 += S[1][(i - 1) % 2];
			if (s1 <= s2) {
				S[1][i % 2] = s1;
				L[1][i] = 0;
			}
			else {
				S[1][i % 2] = s2;
				L[1][i] = 1;
			}
;
		}

	}
	S[0][(N - 1) % 2] += x1;
	S[1][(N - 1) % 2] += x2;
	if (S[0][(N - 1) % 2] <= S[1][(N - 1) % 2]) {
		s_time = S[0][(N - 1) % 2];
		s_line = 0;
	}
	else {
		s_time = S[1][(N - 1) % 2];
		s_line = 1;
	}
	printf("%d\n", s_time);
	Line[N-1] = s_line + 1;
	
	for (int i = N - 1; i >= 1; i--) { 
		s_line = L[s_line][i];
		Line[i - 1] = s_line + 1;
	}
	for (int i = 0; i < N; i++)
		printf("%d %d\n", Line[i], i+1);

	for (int i = 0; i < 2; i++) {
		delete[] a[i];
		delete[] t[i];
		delete[] L[i];
	}
	delete[] Line;
	return 0;
}
