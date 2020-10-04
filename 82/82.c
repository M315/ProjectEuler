#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define infty 922337203685477580

typedef struct q_node{
	int i;
	int j;
	bool used;
} q_node;

typedef struct m_node{
	int val;
	unsigned long dist;
	bool used;
} m_node;

unsigned long min_dist(void);
unsigned long left_col_Dijkstra(m_node**, int, int);

int main(void){
		
	printf("%lu\n", min_dist());

	return 0;
}

/*Using dijkstra to compute only the length from the top-left to the right-bottom*/
unsigned long min_dist(void){
	m_node **matrix; 
	int n = 80, i, j;
	unsigned long MIN, D;
	FILE *pf;

	/* Read the data from file and store it in matrix */
	pf = fopen("matrix.txt", "r");
	if(pf == NULL){printf("Err: No file\n"); return 1;}

	matrix = (m_node**)malloc(n*sizeof(m_node*));
	for(i = 0; i < n; i++)
		matrix[i] = (m_node*)malloc(n*sizeof(m_node));

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			fscanf(pf, "%d,", &matrix[i][j].val);
	
	fclose(pf);

	for(i = 0; i < n; i++){
		D = left_col_Dijkstra(matrix, n, i);
		if(D < MIN)
			MIN = D;
	}

	for(i = 0; i < 0; i++)
		free(matrix[i]);
	free(matrix);

	return MIN;
}

unsigned long left_col_Dijkstra(m_node **matrix, int n, int N){
	int i, j, alt, len, count = 0;
	q_node *Q, u;
	unsigned long min;

	/* Initilize Q*/
	len = n*n;
	Q = (q_node*)malloc(len * sizeof(q_node));
	if(Q == NULL){printf("Err: NoMem\n"); return 0;}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			/* Set dist to inf and used to false */
			matrix[i][j].dist = infty; 
			matrix[i][j].used = false;
			
			/* Add node to de q */
			Q[n*i+j].i = i;
			Q[n*i+j].j = j;
		}
	}
	matrix[N][0].dist = matrix[N][0].val;
	
	/* To simplify we use a variable count to track the number of used elements of Q
	 * so we don't need to resize it every time */
	while(count < len){
		/* Take the item in Q with min dist */
		min = infty;
		for(i = 0; i < len; i++){
			if(!matrix[Q[i].i][Q[i].j].used && matrix[Q[i].i][Q[i].j].dist < min){
				u = Q[i];
				min = matrix[Q[i].i][Q[i].j].dist;
			}
		}
		matrix[u.i][u.j].used = true;
		count++;

/* 		printf("(%d, %d)\n", u.i, u.j);
 */

		/* In this case u can only have two neighbours the right, up and down node*/
		if(u.i > 0) {
			alt = matrix[u.i][u.j].dist + matrix[u.i - 1][u.j].val;
			if (!matrix[u.i - 1][u.j].used && matrix[u.i - 1][u.j].dist > alt) {
				matrix[u.i - 1][u.j].dist = alt;
			}
		}
		if(u.i < n - 1) {
			alt = matrix[u.i][u.j].dist + matrix[u.i + 1][u.j].val;
			if (!matrix[u.i + 1][u.j].used && matrix[u.i + 1][u.j].dist > alt) {
				matrix[u.i + 1][u.j].dist = alt;
			}
		}
		if(u.j < n - 1) {
			alt = matrix[u.i][u.j].dist + matrix[u.i][u.j + 1].val;
			if (!matrix[u.i][u.j + 1].used && matrix[u.i][u.j + 1].dist > alt) {
				matrix[u.i][u.j + 1].dist = alt;
			}
		}
	}

	min  = infty;
	for(i = 0; i < n; i++){
		if(matrix[i][n - 1].dist < min)
			min = matrix[i][n - 1].dist;
	}

/* 	for(i = 0; i < n; i++){
 * 		for(j = 0; j < n; j++)
 * 			printf("%lu ", matrix[i][j].dist);
 * 		printf("\n");
 * 	}
 */

	free(Q);

	return min; 
}
