//2016059198_진승현_A
#include <iostream>
using namespace std;



void showFaren(int** s, int i, int j) {
	if (i == j)
		cout << i + 1;
	else
	{
		cout << "(";
		showFaren(s, i, s[i][j]);
		showFaren(s, s[i][j] + 1, j);
		cout << ")";
	}
}

int main() {
	int N;
	cin >> N;
	int* pNum = new int[N + 1];
	//Mat1 = pNum[0] * pNum[1], Mat2 = pNum[1] * pNum[2] ...
	for (int i = 0; i <= N; i++)
		cin >> pNum[i];
	int** M = new int*[N]; //cost
	int** S = new int*[N]; //ways
	for (int i = 0; i < N; i++) {
		M[i] = new int[N];
		S[i] = new int[N];
		M[i][i] = 0; //대각선 초기화
	}

	for (int len = 1; len < N; ++len) { //len is length of matrix chain
		for (int i = 0; i < N - len; ++i) { //from 0  to N-(len-1)
			int j = i + len; //j means possible chain's end
			M[i][j] = 9999999; //INF
			for (int k = i; k < j; ++k) { //split by k'th Mat
				int min = M[i][k] //left subMat's cost
					+ M[k + 1][j]//right subMat's cost
					+ pNum[i] * pNum[k + 1] * pNum[j + 1]; //k'th Mat's cost
				if (min < M[i][j]) { //M[i][j] is min
					M[i][j] = min;
					S[i][j] = k; //split by k'th Mat
				}
			}
		}
	}

	cout << M[0][N - 1] << endl; //0~(N-1) Mat's min
	showFaren(S, 0, N - 1);

	for (int i = 0; i < N; i++) {
		delete[] M[i];
		delete[] S[i];
	}
	delete[] M;
	delete[] S;
	delete[] pNum;
	return 0;
}