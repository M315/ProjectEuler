#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int, int);

int main(void){
	int *list, m, n, N = 1500000, limit, count, a, b, c, p;

	list = (int*)calloc(N + 1, sizeof(int));

	limit = (int)sqrt(N/2);
	count = 0;
	for(m = 2; m <= limit ; m++){
		for(n = 1; n < m; n++){
			if((m + n) % 2 == 1 && gcd(m, n) == 1){
				a = m*m - n*n;
				b = 2*m*n;
				c = m*m + n*n;
				
				p = a + b + c;
				while(p < N){
					list[p]++;
					if(list[p] == 1)
						count++;
					if(list[p] == 2)
						count--;
					p += a + b + c;
				}
			}
		}
	}

	printf("%d\n", count);

	free(list);

	return 0;
}

int gcd(int a, int b){
	int t;

	while(b != 0){
		t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}
