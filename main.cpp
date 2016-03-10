#include <stdio.h>
#include <iostream>
#include <list>

#define INFINITE -1

using namespace std;

class UndirectedGraph{
	int _numVertices;
	list<int>* _adjacencyLists;

public:
	UndirectedGraph(int numVertices){
		_numVertices = numVertices;
		_adjacencyLists = new list<int>[numVertices];
	}

	void addEdge(int v1, int v2){
		_adjacencyLists[v1].push_back(v2);
		_adjacencyLists[v2].push_back(v1);
	}

	void printAdjacencyLists(){
		int i;
		for(i = 0; i < _numVertices; i++){
			cout << "Vertice: " << i+1 << " --> ";
			for(list<int>::iterator it = _adjacencyLists[i].begin(); 
				it != _adjacencyLists[i].end(); ++it)
				cout << (*it)+1 << " ";
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

	
	graph->printAdjacencyLists();

	/* FAZ ++ NOS VERTICES DEPOIS */

	delete graph;
	return 0;
}
