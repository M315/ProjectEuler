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
	node *Q, u;
	int i, j, len;

	len = n*n;
	Q = (node*)malloc(len*sizeof(node));
	if(Q == NULL){printf("Err: NoMem\n"); return 0;}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			Q[n*i+j].i = i;
			Q[n*i+j].j = j;
			Q[n*i+j].dist = infty; 
		}
	}
	Q[0].dist = 0;
	
	while(len > 0){
		u = Q[0];
		/*Q = &Q[1];
		
		len--;
		Q = (node*)realloc(Q, len*sizeof(node));*/

		printf("u = %d, %d, %ld\n", u.i, u.j, u.dist);
		printf("Q[0] = %d, %d, %ld\n", Q[0].i, Q[0].j, Q[0].dist);

		free(Q);
		return 1;
	}
		
	return 0;
}
