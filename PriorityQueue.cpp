//2016059198_������_A
#include <stdio.h>

static void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

class Node {
public:
	int i;
	Node* Next;
};

class LinkedList {
public:
	Node * Head;
	Node * current;
	int ListSize;
	LinkedList() {
		Head = NULL;
		ListSize = 0;
	}
	void Create(int a) {
		Node *tmp = new Node();
		tmp->i = a;
		tmp->Next = NULL;
		Head = tmp;
		current = tmp;
	}
	void push(int a) { //�������� �߰�
		ListSize++;
		if (Head == NULL) {
			Create(a);
			return;
		}
		Node *tmp = new Node();
		tmp->i = a;
		tmp->Next = NULL;
		current->Next = tmp;
		current = tmp;
	}
	Node* pop() { //head ��ȯ & ������ ��� head��
		ListSize--; //size--
		Node* tmp = new Node(); //Head ����
		tmp->i = Head->i;
		tmp->Next = NULL;
		Head->i = current->i; //Head���� current�� ������
		delete current; //current �޸� ����
		current = getIndex(ListSize - 1); //current �缳��
		return tmp;
	}
	Node* getIndex(int index) {//index�� node��������
		Node* tmp = Head;
		for (int i = 0; i < index; i++)
			tmp = tmp->Next;
		return tmp;
	}
	void printList() {
		Node* tmp = Head;
		if (!tmp)
			return;
		printf("%d ", tmp->i);
		while (tmp != current)
		{
			tmp = tmp->Next;
			printf("%d ", tmp->i);
		}
	}
};

class Heap {
public:
	int heapSize;
	LinkedList* list;
	Heap() {
		heapSize = 0;
		list = new LinkedList();
	}
	void max_heapify(int i, int N) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int largest = i;
		if (left <= N - 1 && list->getIndex(left)->i >= list->getIndex(largest)->i)
			largest = left;
		if (right <= N - 1 && list->getIndex(right)->i >= list->getIndex(largest)->i)
			largest = right;
		if (largest != i) {
			swap(&list->getIndex(i)->i, &list->getIndex(largest)->i);
			//swapping
			max_heapify(largest, N); //���� Ʈ�� ���
		}
	}
	void build_max_heap(int N) {
		//build_max_heap
		int i;
		for (i = (N - 1) / 2; i >= 0; i--) {
			max_heapify(i, N);
		}
	}
	void insert(int a) {
		list->push(a); //a�߰�
		heapSize++; //size ++
		build_max_heap(heapSize); //max_heapȭ
	}

	Node* extract() {
		Node* max = list->pop();
		heapSize--;
		build_max_heap(heapSize);
		return max;
	}

	void substitute(int index, int sub) {
		list->getIndex(index - 1)->i = sub;//��ü
		build_max_heap(heapSize); //max_heapȭ
	}
	void printHeap() {
		list->printList();
	}

};


int main() {
	Heap* h = new Heap();
	LinkedList* extracted = new LinkedList();
	while (1) {
		int input;
		scanf("%d", &input);
		if (input == 0)
			break;
		switch (input) {
		case 1:
			int insert;
			scanf("%d", &insert);
			h->insert(insert);
			break;
		case 2:
			if (h->heapSize == 0)
				continue;
			extracted->push(h->extract()->i);
			break;
		case 3:
			int index, sub;
			scanf("%d %d", &index, &sub);
			h->substitute(index, sub);
			break;

		default:
			continue;
		}
	}
	if (extracted->ListSize != 0)
		extracted->printList();
	printf("\n");
	if (h->heapSize != 0)
		h->printHeap();
	delete h;
	delete extracted;
	return 0;
}