#include <stdio.h>
#include <stdlib.h>

#define infty 9223372036854775807

typedef struct node{
	int i;
	int j;
	unsigned long dist;
} node;

unsigned long min_dist(int**, int);

int main(void){
	int **matrix, n = 80, i, j;
	FILE *pf;

	pf = fopen("matrix.txt", "r");
	if(pf == NULL){printf("Err: No file\n"); return 1;}

	matrix = (int**)malloc(n*sizeof(int*));
	for(i = 0; i < n; i++)
		matrix[i] = (int*)malloc(n*sizeof(int));
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			fscanf(pf, "%d,", &matrix[i][j]);
	
	printf("%lu\n", min_dist(matrix, n));

	return 0;
}

/*Using dijkstra to compute only the length from the top-left to the right-bottom*/
unsigned long min_dist(int **matrix, int n){
	node *Q;
	int i, j;

	Q = (node*)malloc(n*n*sizeof(node));
	if(Q == NULL){printf("Err: NoMem\n"); return 0;}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			Q[n*i+j].i = i;
			Q[n*i+j].j = j;
			Q[n*i+j].dist = infty; 
		}
	}
	Q[0].dist = 0;
		
	return 0;
}
