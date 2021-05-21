/* =====================================================================================
 *	Exercise 735 ProjectEuler
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main(void){
	unsigned long long int twos, fives, sum = 0, curr, curr_f = 1;

	for(fives = 0; fives <= 3 && curr_f <= MAX; fives++){
		printf("\nFives = %llu:\n\n", fives);
		curr = curr_f;
		for(twos = 0; twos <= 4 && curr <= MAX; twos++){
			sum += curr;
			printf("%llu\t\t%llu\n", curr, sum);
			curr *= 2U;
		}
		
		curr_f *= 5U;
	}

	printf("\n#%llu\n", sum);

	return 0;
}
