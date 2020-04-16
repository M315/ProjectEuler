/*
 * 13082761331670030 = 2x3x5x7x11x13x17x19x23x29x31x37x41x43
 * so the numbers that cubed can be 1 module 13082761331670030
 * are those that are product of primes bigger than 43
 * 
 * https://hifuhf.wordpress.com/2010/07/25/project-euler-problem-271/
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m);
uint64_t pow_mod(uint64_t a, uint64_t b, uint64_t m);

int main(){
	uint64_t x, n, m, k, sum;
	
	n = 13082761331670030U;
	k = 2*3*5*11*17*23*29*41;
	m = 7*13*19*31*37*43;
	
	sum = 0U;
	for(x=1; x < m; x++){
		if(pow_mod(x*k+1, 3, m)==1){
			sum += x*k+1;
			printf("%lu\n", sum);
		}
	}
	
	printf("\n#%lu\n", sum);
	
	return 0;
}

uint64_t pow_mod(uint64_t a, uint64_t b, uint64_t m)
{
    uint64_t r = m==1?0:1;
    while (b > 0) {
        if (b & 1)
            r = mul_mod(r, a, m);
        b = b >> 1;
        a = mul_mod(a, a, m);
    }
    return r;
}

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m)
{
   uint64_t d = 0, mp2 = m >> 1;
   int i;
   if (a >= m) a %= m;
   if (b >= m) b %= m;
   for (i = 0; i < 64; ++i)
   {
       d = (d > mp2) ? (d << 1) - m : d << 1;
       if (a & 0x8000000000000000ULL)
           d += b;
       if (d >= m) d -= m;
       a <<= 1;
   }
   return d;
}
