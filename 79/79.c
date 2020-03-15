/*
 * ProjectEuler 79
 */ 

#include <stdio.h>
#include <stdlib.h>

int chars_inPass(int*, int, int*);
void nextPass(int*);

int main(void){
	int **chars, n_chars = 0;
	int *pass, n_pass;
	int aux, i, j;
	int *c, k;
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
	
	c = (int*)calloc(10, sizeof(int));
	for(i=0; i<n_chars; i++)
		for(j=0; j<3; j++)
			for(k=0; k<10; k++)
				if(chars[i][j] == k)
					c[k]++;
	
	for(k=0; k<10; k++)
		printf("%d->%d\n", k, c[k]);
	free(c);
					
	/*Starting with 10236789 look for the password*/
	
	for(i=0; i<n_chars; i++)
		free(chars[i]);
	free(chars);
		
	return 0;
}

/*Returns 1 if all the chars form chars are in pass in order, 0 insted*/
int chars_inPass(int *pass, int n_pass, int *chars){
	int i, check;
	
	check = 0;
	for(i=0; i<n_pass; i++){
		if(pass[i] == chars[check]){
			check++;
			if(check == 3)
				return 1;
		}
	}
	
	return 0;
}
