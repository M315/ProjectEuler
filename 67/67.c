/*
 * ProjectEuler 67
 * 
 * Dijktra EZ
 */

#include <stdio.h>
#include <stdlib.h>

void shitty_Dijktra(int***, int);

int main(void){
	int ***a, n = 100;
	int i, j;
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
			a[i][j]= (int*)calloc(4*sizeof(int));
				if(a[i][j]==NULL){printf("No mem\n"); return 3;}
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++)
			fscanf(pf, "%d", &a[i][j][0]);
	}
	
	fclose(pf);
	
	shitty_Dijktra(a, n);
	
	for(i=0; i<100; i++)
		free(a[i]);
	free(a);
	
	return 0;
}

int shitty_Dijktra(int ***a, int n){
	int **Q, len_Q, *u;
	int i, j;
	
	for(i=1; i<n; i++)
		for(j=0; j<=i; j++){
			/*initialize dist to -1, as we want the longest path*/
			a[1] = -1;
			
			/*initialize the prev to (-1,-1) as it dosent exists)*/
			a[2] = -1;
			a[3] = -1;
		}
	a[0][0][1] = a[0][0][0];
	
	len_Q = 2;
	Q = (int**)malloc(len_Q*len_Q*sizeof(int*));
		if(Q==NULL){printf("No mem\n"); return -1;}
	for(i=0; i<2; i++){
		Q[i] = (int**)malloc(2*len_Q*sizeof(int*));
			if(Q[i]==NULL){printf("No mem\n"); return -1;}
		Q[1-i][0] = a[1][i][0];
		Q[1-i][1] = a[1][i][1];
	}
	
	u = (int*)calloc(2, len_Q*sizeof(int));
		if(u==NULL){printf("No mem\n"); return -1;}
	
	while(Q){
		/*Take the first lement of the queue*/
		u[0] = Q[len_Q-1][0];
		u[1] = Q[len_Q-1][1];
		
		len_Q--;
		Q = (int**)realloc(Q, len_Q*sizeof(int));
			if(Q==NULL){printf("No mem\n"); return -2;}
		
		for(i=u[1]; i<=u[1]-1; i++0{
			
	}
	
	free(u);
	for(i=0; i<n; i++)
		free(Q[i]);
	free(Q);
}

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
