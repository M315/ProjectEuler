#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int primechek(int);
int digitpremutatitionchek(int, int);

int main(void){
	int n=1, i, j, k;
	int *p, *aux;
	
	clock_t begin = clock();

	
	p= (int*)malloc(n*sizeof(int));
	if(p==NULL){printf("No mem\n"); exit(-1);}
	p[0]= 1009;
	
	/*Generem una llista amb tots els primers entre 1000 i 10000*/
	for(i=1011; i<9999; i=i+2){
		if(primechek(i)==1 && i!=1487){
			aux= (int*)malloc(n*sizeof(int));
			if(aux==NULL){printf("No mem\n"); exit(-1);}
			for(j=0; j<n; j++)
				aux[j]= p[j];
			
			n++;
			free(p);
			p= (int*)malloc(n*sizeof(int));
			if(p==NULL){printf("No mem\n"); exit(-1);}
			for(j=0; j<(n-1); j++)
				p[j]= aux[j];
			p[n-1]= i;
			free(aux);
		}
	}
	
	/*Iterem sobre la llista comprovant les condicions per trobar al terna*/
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(digitpremutatitionchek(p[i], p[j])==1){
				k= p[j]+(p[j]-p[i]);
				if(k<10000 && digitpremutatitionchek(p[i], k)==1 && primechek(k)==1){
					printf("%d%d%d\n", p[i], p[j], k);
					j=n;
					i=n;
				}
			}
		}
	}
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("%g s\n", time_spent);		
	
	return 0;
}

int primechek(int a){
	int n;
	if(a%2==0)
		return 0;
	for(n=3; n<=sqrt(a); n=n+2)
		if(a%n==0)
			return 0;
	return 1;
}

int digitpremutatitionchek(int a, int ak){
	int v[4], vk[4], i, j;
	for(i=0; i<4; i++){
		v[i]= a%10;
		a= a/10;
		vk[i]= ak%10;
		ak= ak/10;
	}
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(v[i]==vk[j]){
				vk[j]=-1;
				j=4;
			}
		}
	}
	if((vk[0]+vk[1]+vk[2]+vk[3])==-4){
		return 1;
	}
	return 0;
}
