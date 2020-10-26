#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"

int main(void){
	int sum = 0;
	char s[50];
	sudoku S;
	FILE *pf;

	pf = fopen("sudoku.txt", "r");
		if(pf ==NULL){printf("Err: No File\n"); return 1;}
	
	S = init_sudoku(9);

	while(fgets(s, 50, pf) != NULL){
		read_sudoku(&S, pf);

		S = sudoku_solver(S);

		sum += 100 * S.grid[0][0];
		sum += 10 * S.grid[0][1];
		sum += S.grid[0][2];
	}

	printf("%d\n", sum);

	free_sudoku(&S);
	fclose(pf);

	return 0;
}


