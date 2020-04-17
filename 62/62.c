/*
 * Project Euler 62
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
	uint64_t dig_cub;
	uint8_t len;
	uint16_t rep;
}cubes;

uint64_t d_cube(uint32_t);

int main(void){
	uint32_t k, len_list, i, start = 4642U, end = 10000U;
	uint64_t cub;
	cubes *list;
	
	len_list = 0U;
	list = (cubes*)malloc(len_list*sizeof(cubes));
	if(list == NULL){printf("Err: NoMem\n"); return 1;}

	for(k=start; k<=end; k++){
		cub = d_cube(k);
		
		for(i=0; i<len_list; i++){
			if(cub == list[i].dig_cub){
				list[i].len++;

				if(list[i].len == 5){
					k = list[i].rep;
					cub = k;
					cub *= k;
					cub *= k;
					printf("%lu, %d\n", cub, k);
					return 0;
				}
				break;
			}
		}

		if(i == len_list){
			len_list++;
			list = (cubes*)realloc(list, len_list*sizeof(cubes));
			if(list == NULL){printf("Err: NoMem\n"); return 1;}
			
			list[i].dig_cub = cub;
			list[i].len = 1;
			list[i].rep = k;
		}
	}
	
	free(list);

	return 0;
}

uint64_t d_cube(uint32_t num){
	int16_t *dig, i;
	uint64_t cube, dcube = 0, p = 1;
	
	cube = num;
	cube *= num;
	cube *= num;

	dig = (int16_t*)calloc(10, sizeof(int16_t));
	if(dig == NULL){printf("Err: NoMem\n"); return -1;}
	
	while(cube > 0){
		i = cube%10;
		dig[i]++;
		cube /= 10;
	}

	for(i=9; i>=0; i--){
		dcube += dig[i]*p;
		p *= 10;
	}

	free(dig);

	return dcube;
}
