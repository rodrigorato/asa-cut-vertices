#include <stdio.h>
#include <stdlib.h>

typedef struct fila_node* link_f;

struct fila_node{
	int nV;
	link_f next;
};

typedef struct{
	link_f first;
	link_f last;
} fila;


typedef struct graph_node {
	int num_children, low, d, visited;
	fila* children;
} graphNode;


void insertSon(fila* f, int n){
	link_f son = malloc(sizeof(struct fila_node));
	son->nV =n;
	son->next=NULL;
	if (!f->first) f->first=son;
	else f->last->next=son;
	f->last=son;
}

fila* newFila(){
	fila * f = malloc(sizeof(fila));
	f->first=NULL;
	f->last=NULL;
	return f;
}


/*
	Coisas bonitas da lista de adjacencias
*/

typedef graphNode* adjList;

adjList newAdjList(int num_v){
	int i;
	adjList adjacencyList = malloc(sizeof(graphNode) * num_v);
	for (i = 0; i< num_v; i++){
		adjacencyList[i].children = NULL;
		adjacencyList[i].num_children = 0;
	}
	return adjacencyList;
}

void addConnection(adjList adjacencyList, int a, int b){
	if (!adjacencyList[a].children) adjacencyList[a].children=newFila();
	insertSon(adjacencyList[a].children,b);
	adjacencyList[a].num_children +=1;	
}


/* Tarzan */
/* global vars because why not */
int num_v = 0, num_e = 0;
adjList adjacencyList;
#define INFINITE -1

int tarjanVisit(int u_num, int visited){
	link_f temp = adjacencyList[u_num].children;

	adjacencyList[u_num].d = (adjacencyList[u_num].low = visited);
	visited++;

	for(; temp; temp = temp->next){
		if(adjacencyList[temp->nV].d == INFINITE){
			if()

		}
	}

	return visited;
}

void tarjanAlg(){
	int i, visited = 0;
	for(i = 0; i < num_v; i++){
		adjacencyList[i].d = INFINITE;
		adjacencyList[i].visited = 0;
	}

	for(i = 0; i < num_v; i++){
		/* if(adjacencyList[i].d == INFINITE) */
		visited = tarjanVisit(i, visited);
	}
}




int main(int argc, char *argv[]){
	int i;
	
	/* Read the first line of the input feed */
	scanf("%d %d", &num_v, &num_e);
		
	adjList adjacencyList = newAdjList(num_v);

	for(i = 0; i < num_e; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--; /* FAZ ++ DEPOIS */

		addConnection(adjacencyList, a, b);
		addConnection(adjacencyList, b, a);
	}

	for(i = 0; i < num_v; i++){
		printf("%d %p\n", adjacencyList[i].num_children, adjacencyList[i].children);
	}

	
	/* FAZ ++ NOS VERTICES DEPOIS */

	return 0;
}	
