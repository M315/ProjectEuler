/*
 * ProjectEuler 67
 * 
 * Not dijkstra :S, dynamic programing insted
 */

#include <stdio.h>
#include <stdlib.h>

int shitty_Dijktra(int***, int);
int cmpfun(const void*, const void*);

int main(void){
	int ***a, n = 100;
	int i, j, max;
	FILE *pf;
	
	/*Load the triangle from the file*/
	pf = fopen("triangle.txt", "r");
		if(pf==NULL){printf("Err: No File\n"); return 1;}
	
	a= (int***)malloc(n*sizeof(int**));
		if(a==NULL){printf("No mem\n"); return 2;}
	for(i=0; i<n; i++){
		a[i]= (int**)malloc((i+1)*sizeof(int*));
			if(a[i]==NULL){printf("No mem\n"); return 2;}
		
		for(j=0; j<=i; j++){
			a[i][j]= (int*)calloc(4, sizeof(int));
				if(a[i][j]==NULL){printf("No mem\n"); return 3;}
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++)
			fscanf(pf, "%d", &a[i][j][0]);
	}
	
	fclose(pf);
	
	if(shitty_Dijktra(a, n) == 1){
		max = 0;
		for(i=0; i<n; i++)
			if(max < a[n-1][i][1])
				max = a[n-1][i][1];
	}
	
	printf("result: %d\n", max);
	
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++)
			free(a[i][j]);
		free(a[i]);
	}
	free(a);
	
	return 0;
}

int cmpfun(const void *a, const void *b){
	return (*(*((int**)a)) - (*(*((int**)b))));
}

int shitty_Dijktra(int ***a, int n){
	int **Q, len_Q, *u;
	int i, j, k, alt;
	
	for(i=1; i<n; i++)
		for(j=0; j<=i; j++){
			/*initialize dist to -1, as we want the longest path*/
			a[i][j][1] = -1;
			
			/*initialize the prev to (-1,-1) as it dosent exists)*/
			a[i][j][2] = -1;
			a[i][j][3] = -1;
		}
	a[0][0][1] = a[0][0][0];
	
	/*Create Q*/
	len_Q = 1;
	Q = (int**)malloc(len_Q*sizeof(int*));
		if(Q==NULL){printf("No mem\n"); return -1;}
	Q[0] = (int*)malloc(3*sizeof(int));
		if(Q[i]==NULL){printf("No mem\n"); return -1;}
	/*initialize the first node*/
	Q[0][0] = a[0][0][0];
	Q[0][1] = 0;
	Q[0][2] = 0;
	
	for(i=1; i<n; i++){
		for(j=0; j<=i; j++){
			len_Q++;
			Q = (int**)realloc(Q, len_Q*sizeof(int*));
				if(Q==NULL){printf("No mem\n"); return -1;}
			
			Q[len_Q-1] = (int*)calloc(3, sizeof(int));
				if(Q[i]==NULL){printf("No mem\n"); return -1;}
			Q[len_Q-1][1] = i;
			Q[len_Q-1][2] = j;
		}
	}
	
	u = (int*)calloc(3, sizeof(int*));
		if(u==NULL){printf("No mem\n"); return -1;}
	
	while(len_Q){
		/*Sort the Q to have the element with lergest distance at the end*/
		if(len_Q>1)
			qsort(Q, len_Q, sizeof(int*), cmpfun);
		
		/*Take the first lement of the queue*/
		u[0] = Q[len_Q-1][0];
		u[1] = Q[len_Q-1][1];
		u[2] = Q[len_Q-1][2];
		
		/*Remove the element*/
		len_Q--;
		free(Q[len_Q]);
		
		/*The neighbours of every element are (i+1,j) and (i+1,j+1)*/
		if(u[1] < n-1){
			for(j=u[2]; j<=u[2]+1 && j<=u[1]+1; j++){
				
				/*chekc if the neighbour is in Q*/
				for(k=0; k<len_Q; k++)
					if(Q[k][1] == (u[1]+1) && Q[k][2] == j){
						break;
					}
				
				if(k < len_Q){
					alt = u[0] + a[u[1]+1][j][0];
					if(alt > Q[k][0]){
						Q[k][0] = alt;
						
						a[u[1]+1][j][1] = alt;
						
						/*perv*/
						a[u[1]+1][j][2] = u[1];
						a[u[1]+1][j][3] = u[2];
					}
				}
			}
		}
	}
	
	free(u);
	
	return 1;
}

/*
 1  function Dijkstra(Graph, source):
 2
 3      create vertex set Q
 4
 5      for each vertex v in Graph:             
 6          dist[v] ← INFINITY                  
 7          prev[v] ← UNDEFINED                 
 8          add v to Q                      
10      dist[source] ← 0                        
11      
12      while Q is not empty:
13          u ← vertex in Q with min dist[u]    
14                                              
15          remove u from Q 
16          
17          for each neighbor v of u:           // only v that are still in Q
18              alt ← dist[u] + length(u, v)
19              if alt < dist[v]:               
20                  dist[v] ← alt 
21                  prev[v] ← u 
22
23      return dist[], prev[]
*/
