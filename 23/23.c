#include <stdio.h>
#include <stdlib.h>

int abundant(int);

int main(void){
	int *a, *aux, *s, na=1, i, j;
	long long int sum=0;
	
	a=(int*)calloc(na, sizeof(int));
		if(a==NULL){printf("No mem\n"), exit(-1);}
	a[0]= 12;
	
	for(i=13; i<20162; i++){
		if(abundant(i)){
			
			aux=(int*)calloc(na, sizeof(int));
				if(aux==NULL){printf("No mem\n"), exit(-1);}
			for(j=0; j<na; j++)
				aux[j]= a[j];
			
			free(a);
			na++;
			
			a=(int*)calloc(na, sizeof(int));
				if(a==NULL){printf("No mem\n"), exit(-1);}
			
			for(j=0; j<na-1; j++)
				a[j]= aux[j];
			a[na-1]= i;
			
			free(aux);
		}
	}
	
	s=(int*)calloc(20163*2, sizeof(int));
		if(s==NULL){printf("No mem\n"), exit(-1);}
	
	/*Fem una llista de tots els nombres entre 1 i 20161(mirar abundant
	 *number in Wolfram) que son suma de dos nombres abundants*/
	for(i=0; i<na; i++)
		for(j=i; j<na; j++)
			s[a[i]+a[j]]= 1;
	
	free(a);
	
	for(i=1; i<20162; i++)
		if(s[i]==0)
			sum=sum+i;
	
	free(s);
	
	printf("%lld\n", sum);
	
	return 0;
}

int abundant(int n){
	int i, sum=1;
	
	for(i=2; i<=((n/2)+1); i++){
		if(n%i==0)
			sum= sum+i;
	}
	
	return (sum>n);
}
