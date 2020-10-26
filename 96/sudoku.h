typedef struct sudoku{
	int n;
	int **grid;
} sudoku;

typedef struct pos{
	int i;
	int j;
} pos;


sudoku init_sudoku(int);
void read_sudoku(sudoku*, FILE*);
void free_sudoku(sudoku*);
void print_sudoku(sudoku);
bool* get_valid(sudoku, pos);
sudoku set_number(sudoku, pos, int);
pos* get_empty(sudoku, int*);
sudoku sudoku_solver(sudoku);
