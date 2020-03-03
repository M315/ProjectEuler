/*Use 2 vectors with 1000 components where we put every digit of the number
 *that we are using (+ an auxiliar), and we define the aritmetic of the +
 *for this vetors*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *n1, *n2, *aux, i, c=2;
	
	n1=(int*)calloc(1.e3, sizeof(int));
		if(n1==NULL){ printf("No mem\n"); return -1;}
	n2=(int*)calloc(1.e3, sizeof(int));
		if(n2==NULL){ printf("No mem\n"); return -1;}
	
	n1[0]=1;
	n2[0]=1;
	
	while(n2[999]==0){
		aux=(int*)calloc(1.e3, sizeof(int));
			if(aux==NULL){ printf("No mem\n"); return -1;}
		
		for(i=0; i<1.e3; i++){
			aux[i]= aux[i]+n1[i]+n2[i];
			if(aux[i]>9){
				aux[i+1]++;
				aux[i]= aux[i]%10;
			}
		}	
		
		c++;
		
		for(i=0; i<1.e3; i++)
			n1[i]=n2[i];
		for(i=0; i<1.e3; i++)
			n2[i]=aux[i];
		
		free(aux);
	}
	
	printf("%d\n", c);
	
	free(n1);
	free(n2);
	
	return 0;
}
