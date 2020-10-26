/*
 * 
 * This sudoku functions are done for a n x n sudoku where n is a square.
 *
 */

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

typedef struct sudoku{
	int n;
	int **grid;
} sudoku;

typedef struct pos{
	int i;
	int j;
} pos;

sudoku init_sudoku(int n){
	sudoku S;
	int i;

	/*Set the dimension*/
	S.n = n;

	/*Alloc memory*/
	S.grid = (int**)malloc(n * sizeof(int*));

	for(i = 0; i < n; i++)
		S.grid[i] = (int*)calloc(n, sizeof(int));

	return S;
}

void read_sudoku(sudoku *S, FILE *pf){
	int i, j;
	char aux;

	/*Read sudoku from File*/	
	for(i = 0; i < S->n; i++){
		for(j = 0; j < S->n; j++){
			fscanf(pf, "%c", &aux);
			S->grid[i][j] = (int)aux - 48;
		}
		fscanf(pf, "%c", &aux);
	}
}

void free_sudoku(sudoku *S){
	int i;

	for(i = 0; i < S->n; i++)
		free(S->grid[i]);
	free(S->grid);

	S->n = 0;
}

/* This only prints properly 9x9 sudoku*/
void print_sudoku(sudoku S){
	int i, j;

	printf("+-------+-------+-------+\n");
	for(i = 0; i < S.n; i++){
		if(i == 3 || i == 6)
			printf("+-------+-------+-------+\n");

		printf("| ");

		for(j = 0; j < S.n; j++){
			if(S.grid[i][j] == 0){
				printf("  ");
			}else{
				printf("%d ", S.grid[i][j]);
			}

			if(j == 2 || j == 5)
				printf("| ");
		}

		printf("|\n");
	}

	printf("+-------+-------+-------+\n");
}

/* Returns the valid numbers for an empty possition*/
bool* get_valid(sudoku S, pos p){
	int i, j; 
	pos block;
	bool *valid;

	if(S.grid[p.i][p.j] != 0)
		return NULL;
	
	valid = (bool*)malloc((S.n + 1) * sizeof(bool));
		if(valid == NULL){printf("Err: No Mem\n"); return NULL;}
	for(i = 0; i <= S.n; i++)
		valid[i] = true;
	
	for(i = 0; i < S.n; i++){
		/*Check the values in the column and label them as seen (0) in valid*/
		valid[S.grid[i][p.j]] = false;

		/*Check the values in the row and label them as seen (0) in valid*/
		valid[S.grid[p.i][i]] = false;
	}

	block.i = (p.i / 3) * 3;
	block.j = (p.j / 3) * 3;

	for(i = block.i; i < block.i + 3; i++)
		for(j = block.j; j < block.j + 3; j++)
			valid[S.grid[i][j]] = false;
	
	return valid;
}

/* Make a copy of the sodoku and sets a number to a given postion if it's not valid returns a "free" sudoku */
sudoku set_number(sudoku S, pos p, int n){
	int i, j;
	bool *valid;
	sudoku ret;

	valid = get_valid(S, p);

	ret = init_sudoku(S.n);
	for(i = 0; i < S.n; i++)
		for(j = 0; j < S.n; j++)
			ret.grid[i][j] = S.grid[i][j];

	if(valid[n]){
		ret.grid[p.i][p.j] = n;
	}else{
		free_sudoku(&ret);

		printf("Invalid number\n");
	}

	free(valid);

	return ret;
}

/* Returns a list with the empty possitions on the sudoku */
pos* get_empty(sudoku S, int* length){
	pos *empty;
	int i, j, count = 0;

	empty = (pos*)malloc(count * sizeof(pos));

	for(i = 0; i < S.n; i++)
		for(j = 0; j < S.n; j++)
			if(S.grid[i][j] == 0){
				count++;

				empty = (pos*)realloc(empty, count * sizeof(pos));
					if(empty == NULL){printf("Err: No Mem\n"); return NULL;}

				empty[count - 1].i = i;
				empty[count - 1].j = j;
			}
	
	*length = count;

	return empty;
}

sudoku sudoku_solver(sudoku S){
	int n_empty, i;
	bool *valid, ctrl = true;
	pos *empty;
	sudoku ret;

	empty = get_empty(S, &n_empty);
	
	if(n_empty == 0)
		return S;

	valid = get_valid(S, empty[0]);

	for(i = 1; i <= S.n; i++){
		if(valid[i]){
			if(ctrl)
				ctrl = false;

			ret = set_number(S, empty[0], i);

			ret = sudoku_solver(ret);

			if(ret.n != 0){
				free(valid);
				free(empty);

				return ret;
			}
		}
	}

	/* If no valid number return a "free" sudoku*/
	if(ctrl)
		ret = init_sudoku(0);

	free(valid);
	free(empty);

	return ret;
}
