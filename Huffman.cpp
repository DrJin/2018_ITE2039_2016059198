//2016059198_진승현_A
#include <iostream>
#include <queue>
#include <math.h>
#include <string.h>
using namespace std;

class Node {
public:
	char code[5];
	int frequency;
	Node* l;
	Node* r;
	Node(const char _code[5], int _frequency) : frequency(_frequency) {
		strcpy(code, _code);
		l = NULL;
		r = NULL;
	};

	bool isLeaf() const {
		return (this->l == NULL && this->r == NULL);
	}


};
struct comp {
	bool operator() (Node* n1, Node* n2) const {
		return n1->frequency > n2->frequency;
	}
};

void Preorder(Node* node, int N, int codelen, int& sum) {
	if (node == NULL)
		return;
	else {
		if (!node->isLeaf()) { //말단 노드가 아니면
			codelen++;
			Preorder(node->l, N, codelen, sum);
			Preorder(node->r, N, codelen, sum);
		}
		else { //leaf node이면

			sum += node->frequency*codelen;

		}

	}
}

int main() {
	priority_queue<Node*, vector<Node*>, comp > heap; //mean heap
	int N, S;
	//scanf("%d", &N);
	cin >> N;
	int* frequency = new int[N];
	char** code = new char*[N];
	for (int i = 0; i < N; i++)
		code[i] = new char[5];


	for (int i = 0; i < N; i++) {
		//scanf("%s %d", w.word, &w.frequency);
		cin >> code[i] >> frequency[i];
		heap.push(new Node(code[i], frequency[i]));
	}//heap 화

	 //scanf("%d", &S);
	cin >> S;
	Node* tmp;
	while (heap.size()>1) { //heap이 하나 남을 때까지
							//Node* n1 = new Node(heap.top());
		Node* n1 = heap.top();
		heap.pop();
		Node* n2 = heap.top();
		heap.pop();
		tmp = new Node("....", n1->frequency + n2->frequency);
		tmp->l = n1;
		tmp->r = n2;
		heap.push(tmp);
	}


	int l = (int)log2(N) + 1;

	//printf("%d\n", S * l);
	cout << S * l << endl;

	int costs = 0;
	Preorder(heap.top(), N, 0, costs);

	cout << costs << endl;

	for (int i = 0; i < N; i++)
		delete[] code[i];
	delete[] code;
	delete[] frequency;
}