#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int *list, i, a, b, c, N = 150000, count;

	list = (int*)calloc(N + 1, sizeof(int));

	for(a = 3; a < N/3; a++){
		for(b = a + 1; b < N - a; b++){
			c = sqrt(a*a + b*b);
			if(c*c == a*a + b*b && a+b+c <= N)
				list[a+b+c]++;
		}
	}

	count = 0;
	for(i = 0; i <= N; i++)
		if(list[i] == 1)
			count++;
	
	printf("%d\n", count);

	free(list);

	return 0;
}
