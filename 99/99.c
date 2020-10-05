/* =====================================================================================
 *	Ezercise 99 ProjectEuler
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct base_exp{
	long base;
	long exp;
} base_exp;

int main(void){
	base_exp new;
	int line = 0, n = 0;
	double max;
	FILE *pf;

	pf = fopen("base_exp.txt", "r");
	if(pf == NULL){printf("Err: No File\n"); return 1;}

	max = 0.;
	
	while(fscanf(pf, "%ld,%ld", &new.base, &new.exp) > 0){
		n++;

		if((double)new.exp * log((double)new.base) > max){
			max = (double)new.exp * log((double)new.base);
			line = n;
		}
	}

	printf("%d\n", line);

	fclose(pf);

	return 0;
}
