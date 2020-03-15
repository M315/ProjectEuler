/*
 * ProjectEuler 67
 * 
 * Dijktra EZ
 */

#include <stdio.h>
#include <stdlib.h>

/*Llista de nodes adjacents a un node*/
struct AdjListNode{
	int dest;
	struct AdjListNode* next;
}

/*Llista de nodes*/
struct AdjList{
	struct AdjListNode *head;
}

struct Graph{
	int V;						/*nombre de nodes del Graph*/
	struct AdjList *array;		/*llista de nodes del Graph*/
}


int main(void){
	int **a, n = 100;
	int i, j;
	FILE *pf;
	
	/*Load the triangle from the file*/
	pf = fopen("triangle.txt", "r");
		if(pf==NULL){printf("Err: No File\n"); return 1;}
	
	a= (int**)malloc(n*sizeof(int*));
		if(a==NULL){printf("No mem\n"); return 2;}
	for(i=0; i<n; i++){
		a[i]= (int*)malloc((i+1)*sizeof(int));
			if(a[i]==NULL){printf("No mem\n"); return 2;}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++)
			fscanf(pf, "%d", &a[i][j]);
	}
	
	fclose(pf);
	
	for(i=0; i<100; i++)
		free(a[i]);
	free(a);
	
	return 0;
}

