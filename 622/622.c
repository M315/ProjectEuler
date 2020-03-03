#include <stdio.h>
#include <stdlib.h>

int main(void){
	unsigned long long int n, *ord, maxo, oc, c, i, p, j, k;
	unsigned long long int sum=0;
	
	for(n=2; n<=200; n=n+2){
		
		ord=(unsigned long long int*)calloc((n-2), sizeof(unsigned long long int));
			if(ord==NULL){printf("No mem\n"); exit(-1);}
		
		j=0;
		maxo=0;
		
		for(i=20; i<n/2; i= i+2){
			/*Comprovem que no estigui a ord*/
			c=0;
			oc=0;
			for(k=0; k<(n-2); k++)
				if(i==(ord[k]))
					c++;
			
			if(c==0){				
				p= 2*i;
				ord[j]= p;
				j++;
				oc++;
				/*printf("%lld", p);*/
				
				while(p!=i && oc<=61){
					p= (2*p)%(n-1);
					ord[j]= p;
					j++;
					oc++;
					/*printf("->%lld", p);*/
				}
			}
			/*printf(" *%lld	%lld*\n", i, oc);*/
			
			if(oc>60){
				break;
			}else{
				if((oc!=1) && (oc!=2) && (oc!=3) && (oc!=4) && (oc!=5) && (oc!=6) && (oc!=10) && (oc!=12) && (oc!=15) && (oc!=20) && (oc!=30) && (oc!=60)){
					break;
				}
			}
			if(oc>maxo)
				maxo= oc;
			
			if(j>=((n-2)-60)){
				break;
			}
		}
		
		if(maxo==60){
			sum= sum+n;
			printf("%lld\n", n);
		}
		
		free(ord);
		
		if(n==1.e5)
			printf("%lld\n", n);
		if(n==1.e6)
			printf("%lld\n", n);
		if(n==1.e7)
			printf("%lld\n", n);
		if(n==1.e8)
			printf("%lld\n", n);
		if(n==1.e9)
			printf("%lld\n", n);
		if(n==1.e10)
			printf("%lld\n", n);
		if(n==1.e11)
			printf("%lld\n", n);
		if(n==1.e12)
			printf("%lld\n", n);
		if(n==1.e13)
			printf("%lld\n", n);
		if(n==1.e14)
			printf("%lld\n", n);
		if(n==1.e15)
			printf("%lld\n", n);
		if(n==1.e16)
			printf("%lld\n", n);
		if(n==1.e17)
			printf("%lld\n", n);
	}
	
	printf("%lld\n", sum);
	
	return 0;
}
