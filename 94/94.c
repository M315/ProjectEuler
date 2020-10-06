#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long sum_triangles(void);

int main(void){
		
	printf("%lld\n", sum_triangles());

	return 0;
}

long long sum_triangles(void){
	long int a, b, N = 1000000000;
	double A;
	long long sqA, sum = 0;

	for(a = 3; a <= N / 3; a += 2){
		b = a - 1;
		A = (a * a) - ((b * b) / 4); 
		sqA = (long long)sqrt((double) A);

		if(A == sqA * sqA)
			sum += a*2 + b;
		
		b = a + 1;
		A = (a * a) - ((b * b) / 4); 
		sqA = (long long)sqrt((double) A);

		if(A == sqA * sqA)
			sum += a*2 + b;
	}

	return sum;
}
