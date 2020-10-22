/*Its a generalization of problem 31*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t coin_partitions(int16_t);

int main(void){
	int64_t *partitions, max = 100000, mod = 1000000, n, k, sign, index;

	partitions = (int64_t*)calloc(max, sizeof(int64_t));
		if(partitions == NULL){printf("Err: NoMem\n"); return 1;}
	
	partitions[0] = 1;
	partitions[1] = 1;

	for(n = 2; n < max; n++){

		sign = 1;

		for(k = 1; (3 * k * k - k) / 2 <= n; k++){

			index = (3 * k * k - k) / 2;
			partitions[n] += sign * partitions[n - index];

			index += k;
			if(index > n)
				break;
			
			partitions[n] += sign * partitions[n - index]; 

			partitions[n] = (mod + (partitions[n] % mod)) % mod;

			sign *= -1;
		}

		if(partitions[n] == 0)
			break;

		/*printf("%ld -> %ld\n", n, partitions[n]);*/
	}

	printf("%ld\n", n);

	free(partitions);

	return 0;
}

uint64_t coin_partitions(int16_t target){
	int16_t i, j;
	uint64_t *ways, partitions;

	ways = (uint64_t*)calloc(target + 1, sizeof(uint64_t));
	ways[0] = 1;
	
	for(i = 1; i < target; i++)
		for(j = i; j <= target; j++)
			ways[j] = ways[j] + ways[j-i];
	
	partitions = ways[target] + 1;

	free(ways);

	return partitions;
}
