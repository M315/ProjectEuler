/*
 * project euler 38
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nextPermutation(int array[], int length);
int substring_divisibilty(int digits[]);

int main(void){
	int i;
	int num[10] = {0,1,2,3,4,5,6,7,8,9};
	unsigned long long int sum, aux, mult;
	
	sum = 0;
	while(nextPermutation(num, 10)){
		if(substring_divisibilty(num) == 1){
			aux = 0;
			mult = 1;
			for(i=9; i>=0; i--){
				aux += num[i]*mult;
				mult = mult*10;
			}
			sum += aux;
		}
	}
	
	printf("%llu\n", sum);
	
	return 0;
}

int nextPermutation( int array[], int length ){
    int i, j, temp;

    /* starting from the end of the array, find the first number (call it 'x')
    * that is followed by a larger number*/
    for ( i = length - 2; i >= 0; i-- )
        if ( array[i] < array[i+1] )
            break;

    /* if no such number was found (all the number are in reverse order)
    * then there are no more permutations*/
    if ( i < 0 )
        return 0;

    /* starting from the end of the array, find the first number (call it 'y')
    * that is larger than 'x', and swap 'x' and 'y'*/
    for ( j = length - 1; j > i; j-- )
        if ( array[j] > array[i] ){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            break;
        }

    /* 'y' is now where 'x' was, and all of the numbers to the right of 'y'
	* are in descending order, swap them so that they are in ascending order*/
    for ( i++, j = length - 1; j > i; i++, j-- ){
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    return 1;
}

int substring_divisibilty(int digits[]){
	int i;
	unsigned int aux, mult;
	
	/*Check if d2d3d4 is divisible by 2*/
	aux = 0;
	mult = 1;
	for(i=3; i>=1; i--){
		aux += digits[i]*mult;
		mult = mult*10;
	}
	if(aux%2 != 0)
		return 2;
	
	/*Check if d2d3d4 is divisible by 3*/
	aux = 0;
	mult = 1;
	for(i=4; i>=2; i--){
		aux += digits[i]*mult;
		mult = mult*10;
	}
	if(aux%3 != 0)
		return 3;
	
	/*Check if d2d3d4 is divisible by 5*/
	aux = 0;
	mult = 1;
	for(i=5; i>=3; i--){
		aux += digits[i]*mult;
		mult = mult*10;
	}
	if(aux%5 != 0)
		return 5;
	
	/*Check if d2d3d4 is divisible by 7*/
	aux = 0;
	mult = 1;
	for(i=6; i>=4; i--){
		aux += digits[i]*mult;
		mult = mult*10;
	}
	if(aux%7 != 0)
		return 7;
	
	/*Check if d2d3d4 is divisible by 7*/
	aux = 0;
	mult = 1;
	for(i=7; i>=5; i--){
		aux += digits[i]*mult;
		mult = mult*10;
	}
	if(aux%11 != 0)
		return 11;
	
	/*Check if d2d3d4 is divisible by 7*/
	aux = 0;
	mult = 1;
	for(i=8; i>=6; i--){
		aux += digits[i]*mult;
		mult = mult*10;
	}
	if(aux%13 != 0)
		return 13;
	
	/*Check if d2d3d4 is divisible by 17*/
	aux = 0;
	mult = 1;
	for(i=9; i>=7; i--){
		aux += digits[i]*mult;
		mult = mult*10;
	}
	if(aux%17 != 0)
		return 17;
	
	/*if the number gets this far it satisfies the propertie*/
	return 1;
}
