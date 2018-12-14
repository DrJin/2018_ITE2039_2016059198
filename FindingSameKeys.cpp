//2016059198_Áø½ÂÇö_A
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	priority_queue<int> A, B;
	int c, keys = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &c);
		A.push(c);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &c);
		B.push(c);
	}
	while (!(A.empty() || B.empty())) {
		if(A.top() > B.top()){
			A.pop();
		}
		else if (A.top() < B.top()) {
			B.pop();
		}
		else {
			keys++;
			A.pop();
			B.pop();
		}
		
	}
	printf("%d", keys);

	return 0;
}