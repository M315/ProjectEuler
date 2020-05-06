/*
 * Project Euler 73
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	long int m;
	long int n;
} node;

unsigned long long length_coprime_tree(long int);

int main(void){
	long int end = 12000;

	printf("%llu\n", length_coprime_tree(end));

	return 0;
}

unsigned long long length_coprime_tree(long int max){
	unsigned long long int count = 0U;
	long long int len;
	node *to_visit, curr, new;
	
	len = 2;
	to_visit = (node*)malloc(len*sizeof(node));
	/*Generate and count the even-odd nodes*/
	to_visit[0].m = 2;
	to_visit[0].n = 1;
	/*Generate and count the odd-odd nodes*/
	to_visit[1].m = 3;
	to_visit[1].n = 1;

	/*do a dfs apporach to generate the tree*/
	while(len > 0){
		/*take the last item of the list, and delete it form the list*/
		curr.m = to_visit[len-1].m;
		curr.n = to_visit[len-1].n;
		len--;
		to_visit = (node*)realloc(to_visit, len*sizeof(node));

		if((double)curr.n/(double)curr.m < 1./2. &&
		(double)curr.n/(double)curr.m > 1./3.)
			count++;
		
		/*Branch 1*/
		new.m = 2*curr.m - curr.n;
		new.n = curr.m;

		if(new.m <= max){
			len++;
			to_visit = (node*)realloc(to_visit, len*sizeof(node));
			to_visit[len-1].m = new.m;
			to_visit[len-1].n = new.n;

			/*printf("(%ld, %ld), %lld\n", to_visit[len-1].m, to_visit[len-1].n,
			len);*/
		}
		
		/*Branch 2*/
		new.m = 2*curr.m + curr.n;
		new.n = curr.m;

		if(new.m <= max){
			len++;
			to_visit = (node*)realloc(to_visit, len*sizeof(node));
			to_visit[len-1].m = new.m;
			to_visit[len-1].n = new.n;

			/*printf("(%ld, %ld), %lld\n", to_visit[len-1].m, to_visit[len-1].n,
			len);*/
		}

		/*Branch 3*/
		new.m = curr.m + 2*curr.n;
		new.n = curr.n;

		if(new.m <= max){
			len++;
			to_visit = (node*)realloc(to_visit, len*sizeof(node));
			to_visit[len-1].m = new.m;
			to_visit[len-1].n = new.n;

			/*printf("(%ld, %ld), %lld\n", to_visit[len-1].m, to_visit[len-1].n,
			len);*/
		}
	}
	
	return count;
}
