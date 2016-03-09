#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** mat, int size){
	int i, j;
	for(i = 0; i<size; i++){
			for(j = 0; j<size; j++)
					printf("%d ", mat[i][j]);
			printf("\n");
	}
}

int main(int argc, char *argv[]){
	int num_v = 0, num_e = 0, i;
	
	/* Read the first line of the input feed */
	scanf("%d %d", &num_v, &num_e);
	
	/* Initializes an adjacency matrix populated with zeros */
	int** adj_matrix = calloc(num_v, sizeof(int));
	for(i = 0; i < num_v; i++)
		adj_matrix[i] = calloc(num_v, sizeof(int)); 

	/* */
	for(i = 0; i < num_e; )


	printMatrix(adj_matrix, num_v);
	

	return 0;
}	
