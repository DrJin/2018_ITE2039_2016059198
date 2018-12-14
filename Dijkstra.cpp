//2016059198_Áø½ÂÇö_A
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 2147483647
using namespace std;

class Vertex {
public:
	int index;//index of Vertex
	int distance;//distance to Vertex
	vector< pair<int, int> > weights;//Vertex to Vertex weight;
									 //Vertex* short_way;
	Vertex() {}
	Vertex(int i, vector< pair<int, int> > w) :index(i), weights(w), distance(INF) {}

	/*
	bool relaxation(Vertex& v) {
	if (this->distance + weights[v.index] < v.distance) {
	v.distance = this->distance + weights[v.index];
	return true;
	}
	else
	return false;
	}
	*/
};

struct cmp {
	bool operator()(const Vertex v1, const Vertex v2) { //less -> min heap
		return v1.distance > v2.distance;
	}
};

int main() {
	int N;
	cin >> N;
	Vertex* graph = new Vertex[N + 1];
	for (int i = 0; i < N; i++) {
		int index, E;
		cin >> index >> E;
		vector< pair<int, int> > e;
		for (int j = 0; j < E; j++) {
			int d, w;
			cin >> d >> w;
			e.push_back(pair<int, int>(d, w));
		}
		graph[index] = Vertex(index, e);
	}

	//input finish;
	priority_queue<Vertex, vector<Vertex>, cmp> Q;

	//dijkstra
	graph[1].distance = 0; //find from the first vertex
	Q.push(graph[1]);
	Vertex select;
	while(!Q.empty()) {
		select = Q.top();
		Q.pop();//Q pop
				//relaxation - for all edges
		for (vector< pair<int, int> >::iterator it = select.weights.begin();
			it != select.weights.end(); ++it) {
			/*
			if (select.relaxation(graph[(*it).first])) {
			Q.push(graph[(*it).first]);
			//select.short_way = &graph[(*it).first];//way check
			}
			*/
			if (select.distance + (*it).second < graph[(*it).first].distance) {
				graph[(*it).first].distance = select.distance + (*it).second;
				Q.push(graph[(*it).first]);
			}
		}
	}
	int max = 0;
	for (int i = 2; i <= N; i++) {
		if (max < graph[i].distance)
			max = graph[i].distance;
	}
	cout << max;
	delete[] graph;
	return 0;
}