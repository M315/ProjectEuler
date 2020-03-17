/*
 * ProjectEuler 79
 */ 

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int **chars, n_chars = 0;
	int **before, **after;
	int aux, i, j, k;
	FILE *pf;
	
	
	/*Read the shit from the txt*/
	pf = fopen("keylog.txt", "r");
		if(pf==NULL){printf("Err: No File\n"); return 1;}
	
	chars = (int**)malloc(n_chars*sizeof(int*));
	
	while(fscanf(pf, "%d", &aux) != EOF){
		n_chars++;
		
		chars = (int**)realloc(chars, n_chars*sizeof(int*));
			if(chars==NULL){printf("Err: NoMem\n"); return 2;}
		chars[n_chars-1] = (int*)malloc(3*sizeof(int));
			if(chars[n_chars-1]==NULL){printf("Err: NoMem\n"); return 2;}
		
		for(i=2; i>=0; i--){
			chars[n_chars-1][i] = aux%10;
			aux = aux/10;
		}
	}
	
	fclose(pf);
	
	before = (int**)malloc(10*sizeof(int*));
	for(k=0; k<10; k++){
		before[k] = (int*)calloc(10, sizeof(int));
		if(before[k] == NULL){printf("Err: NoMem\n"); return 3;}
	}
	
	after = (int**)malloc(10*sizeof(int*));
	for(k=0; k<10; k++){
		after[k] = (int*)calloc(10, sizeof(int));
		if(after[k] == NULL){printf("Err: NoMem\n"); return 3;}
	}
	
	for(k=0; k<10; k++){
		
		for(i=0; i<n_chars; i++){
			for(j=0; j<3; j++){
				if(chars[i][j] == k){
					if(j==2){
						before[k][chars[i][j-1]]++;
					}
					if(j==1){
						before[k][chars[i][j-1]]++;
						
						after[k][chars[i][j+1]]++;
					}
					if(j==0){
						after[k][chars[i][j+1]]++;
					}
				}
			}
		}
	}
	
	for(k=0; k<10; k++){
		printf("The numbers before %d:", k);
		for(i=0; i<10; i++)
			if(before[k][i])
				printf(" %d", i);
		printf("\n");
	}
	
	for(k=0; k<10; k++){		
		printf("The numbers after %d:", k);
		for(i=0; i<10; i++)
			if(after[k][i])
				printf(" %d", i);
		printf("\n");
	}
	
	printf("\nAs the 4 and 5 don't apear in any key we can exclude them.\n");
	printf("Then we look that the 7 never has any number before it and 3\n");
	printf("just have the 7, so we put 73... using this resoning we get\n");
	printf("the answer of 73162890.\n");
	
	for(i=0; i<n_chars; i++)
		free(chars[i]);
	free(chars);
	
	for(i=0; i<10; i++)
		free(before[i]);
	free(before);
	
	for(i=0; i<10; i++)
		free(after[i]);
	free(after);
		
	return 0;
}
