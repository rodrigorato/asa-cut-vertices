#include <stdio.h>
#include <iostream>
#include <list>
#include <queue>
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
	list<int> L;
	list<int> articulationPoints;
	vector<int> artPts;
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
		int u, m=-2,M=-2,art=0;
		
		visited = 0;
		articulationPoints = list<int>();
		artPts = vector<int>(_numVertices, 0);
		L = list<int>();
		d = vector<int>(_numVertices, INFINITE); 
		low = vector<int>(_numVertices);
		traversed = vector<int>(_numVertices);

		for(u = 0; u < _numVertices; u++)
			if(d[u] == INFINITE)
				tarjanVisit(u);

		for(u = 0; u < _numVertices; u++){
			if(artPts[u]){
				
				art++;
				if (u<m || m==-2)m=u;
				if (u>M)M=u;
			}
		}
		cout << art<< endl;
		cout << m+1 << " " << M+1 << endl;

	}

	void tarjanVisit(int u){
		int v, child=0;
		d[u] = (low[u] = visited);
		visited++;
		traversed[u] = 1;
		L.push_back(u);

		list<int>::iterator it;
		for(it = _adjacencyLists[u].begin(); it != _adjacencyLists[u].end(); it++){
			v = (*it);
			if(d[v] == INFINITE || traversed[v] == 1){
				if(d[v] == INFINITE){
					tarjanVisit(v);
					low[u] = min(low[u], low[v]);
					if (u==0) child++;
					if((d[u] <= low[v] && u != 0) ||(u==0 && child>1)){
						artPts[u]++;
					}
				}
				else if(traversed[v] == 1)
					low[u] = min(low[u], d[v]);
			}
		}
		if(d[u] == low[u]){
			int j;
			for(; (j = L.back()) != u; L.pop_back()){
				traversed[j] = 0;
			}
			L.pop_back(); 
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


	delete graph;
	return 0;
}
