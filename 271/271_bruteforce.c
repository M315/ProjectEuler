/* To avoid to much calculations we want to know for every p prime factor
 * of n, wich i's can create a possible solution for i^3 = 1 mod p*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m);
uint64_t pow_mod(uint64_t a, uint64_t b, uint64_t m);

int main(){
	uint64_t i, k, primes[13] = {3,5,7,11,13,17,19,23,29,31,37,41,43};
	
	for(k=0; k<13; k++){
		printf("\n For %lu:", primes[k]);
		for(i=1; i<primes[k]; i++){
			if(pow_mod(i, 3, primes[k])==1){
				printf(" %lu, ", i);
			}
		}
	}
	
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
