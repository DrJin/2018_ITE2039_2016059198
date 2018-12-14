//2016059198_Áø½ÂÇö_A
#include <stdio.h>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Vertex {
public:
	int index;
	int t_dis;
	int t_fin;
	Vertex() :t_dis(-1), t_fin(-1) {}
};

class Graph {
private:
	int N;
	vector< list<int> > adj;
	Vertex* v;
	stack<int> order;
public:
	Graph(int _N, vector< list<int> > _adj) :N(_N), adj(_adj) {
		v = new Vertex[N];
		for (int i = 0; i < N; i++)
			v[i].index = i + 1;
		makeDFS();
	}
	~Graph() {
		delete[] v;
	}


	void DFSvisit(Vertex* select, int& time) {
		time++;
		select->t_dis = time;
		for (list<int>::iterator it = adj[select->index - 1].begin();
			it != adj[select->index - 1].end(); ++it) {
			if (v[(*it) - 1].t_dis == -1) {//not visited
				DFSvisit(&v[(*it) - 1], time);
			}
		}
		select->t_fin = ++time;
		order.push(select->index);
	}

	void makeDFS() {
		int time = 0;
		for (int i = 0; i < N; i++) {
			if (v[i].t_dis == -1)
				DFSvisit(&v[i], time);
		}

	}

	int checkDAG() {
		int check = 1;
		for (int i = 0; i < N; i++) {
			for (list<int>::iterator it = adj[i].begin();
				it != adj[i].end(); ++it) {
				if (v[i].t_dis > v[(*it)].t_dis &&
					v[i].t_fin < v[(*it)].t_fin)
					check = 0;
			}
		}
		return check;
	}

	void printTopologicalOrder() {
		while (!order.empty()) {
			printf("%d ", order.top());
			order.pop();
		}
		printf("\n");
	}
};


int main() {
	int N;
	scanf("%d", &N);
	//vector< pair<int, int> > adj;
	vector< list<int> > adj(N);
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		adj[a - 1].push_back(b);
	}
	for (vector< list<int> >::iterator it = adj.begin();
		it != adj.end(); ++it) {
		(*it).sort();
	}
	Graph g(N, adj);
	int isDAG = g.checkDAG();
	printf("%d\n", isDAG);
	if (isDAG == 1)
		g.printTopologicalOrder();

	return 0;
}