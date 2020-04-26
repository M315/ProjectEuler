/*
 * Project Euler 72
 * https://en.wikipedia.org/wiki/Coprime_integers#Generating_all_coprime_pairs
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	long int m;
	long int n;
	node* parent;
} node;

unsigned long long lenght_coprime_tree(long int);

int main(void){
	long int end = 8;
	
	printf("%llu\n", length_coprime_tree(end));

	return 0;
}

unsigned long long lenght_coprime_tree(long int max){
	unsigned long long int count = 0U, len;
	node *tree;

	/*First we generate and count the even-odd nodes*/
	len = 1U;
	tree = (node*)malloc(len*sizeof(node));
	tree[0].m = 2;
	tree[0].n = 1;
	tree[0].parent = NULL;
	
	count++;


	
	
	return count;
}
