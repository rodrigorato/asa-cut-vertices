#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#define INFINITE -1

using namespace std;

class UndirectedGraph{
private:
	int _numVertices;
	list<int>* _adjacencyLists;

	/* Tarjan's algorithm variables */
	int visited;
	vector<int> d;
	vector<int> low;
	vector<int> traversed;

public:
	UndirectedGraph(int numVertices){
		_numVertices = numVertices;
		_adjacencyLists = new list<int>[numVertices];
	}

	~UndirectedGraph(){
		delete[] _adjacencyLists;
	}

	void addEdge(int v1, int v2){
		_adjacencyLists[v1].push_back(v2);
		_adjacencyLists[v2].push_back(v1);
	}

	void tarjanTraversal(){
		int u;
		
		visited = 0;
		d = vector<int>(_numVertices, INFINITE);
		low = vector<int>(_numVertices);
		traversed = vector<int>(_numVertices);

		for(u = 0; u < _numVertices; u++)
			if(d[u] == INFINITE)
				tarjanVisit(u);
	}

	void tarjanVisit(int u){
		int v;
		d[u] = low[u] = visited;
		visited++;
		traversed[u] = 1;

		list<int>::iterator it;
		for(it = _adjacencyLists[u].begin(); it != _adjacencyLists[u].end(); it++){
			v = (*it);
			if(d[v] == INFINITE || traversed[v] == 1){
				if(d[v] == INFINITE)
					tarjanVisit(v);
				low[u] = min(low[u], low[v]);
			}
		}
	}


	void printAdjacencyLists(){
		/* APAGA ESTE CODIGO DAQUI */
		int i;
		for(i = 0; i < _numVertices; i++){
			cout << "Vertice: " << i+1 << " --> ";
			for(list<int>::iterator it = _adjacencyLists[i].begin(); 
				it != _adjacencyLists[i].end(); ++it)
				cout << (*it)+1 << " ";
			cout << "\t| d=" << d[i] << " low=" << low[i] << " visited=" << traversed[i];
			cout << endl;
		}

	}
};

int main(){
	int num_v, num_e, i;
	
	/* Read the first line of the input feed to allocate the graph */
	scanf("%d %d", &num_v, &num_e);
		
	UndirectedGraph* graph = new UndirectedGraph(num_v);

	for(i = 0; i < num_e; i++){
		/* Reads and adds an edge to the graph */
		int vertice1, vertice2;
		scanf("%d %d", &vertice1, &vertice2);

		/* Internally we start the vertices' indexes at zero */
		vertice1--; vertice2--; 

		graph->addEdge(vertice1, vertice2);
	}

	graph->tarjanTraversal();
	graph->printAdjacencyLists();

	/* FAZ ++ NOS VERTICES DEPOIS */

	delete graph;
	return 0;
}
