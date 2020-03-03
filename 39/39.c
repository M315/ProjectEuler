/*
 * project euler 39
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
	int p, a, b, c, count, max_p, max_count;
	clock_t ti, tf;
	
	ti = clock();
	
	max_p = 0;
	max_count = 0;
	for(p=3; p<=1000; p++){
		count = 0;
		for(a=1; a<=p-2; a++){
			for(b=a; b<=p-2; b++){
				c = p - a - b;
				
				if(c*c == (a*a + b*b))
					count++;
			}
		}
		if(count > max_count){
			max_count = count;
			max_p = p;
		}
	}
	
	tf = clock();
	
	printf("%d %d - %g\n", max_p, max_count, ((double)tf - (double)ti)/CLOCKS_PER_SEC);
	
	return 0;
}
