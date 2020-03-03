#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *sol, *n, i, j;
	char *c;
	FILE *pf;
	
	pf= fopen("num.txt", "r");
	 if(pf==NULL){printf("No file\n"); return -1;}
	
	sol=(int*)calloc(51, sizeof(int));
		if(sol==NULL){printf("No mem\n"); return -1;}
	
	for(i=0; i<100; i++){
		c=(char*)calloc(51, sizeof(char));
			if(c==NULL){printf("No mem\n"); return -1;}
		
		for(j=0; j<51; j++)
			c[j]= fgetc(pf);
		
		n=(int*)calloc(51, sizeof(int));
			if(n==NULL){printf("No mem\n"); return -1;}
		
		for(j=0; j<50; j++){
			switch(c[j]){
				case '1':
					n[j]=1; break;
				case '2':
					n[j]=2; break;
				case '3': 
					n[j]=3; break;
				case '4':
					n[j]=4; break;
				case '5':
					n[j]=5; break;
				case '6':
					n[j]=6; break;
				case '7':
					n[j]=7; break;
				case '8':
					n[j]=8; break;
				case '9':
					n[j]=9; break;
				case '0':
					n[j]=0; break;
			}
		}
		
		free(c);
		
		for(j=0; j<50; j++){
			sol[j]= sol[j]+n[49-j];
			if(sol[j]>9){
				sol[j+1]++;
				sol[j]= sol[j]%10;
			}
		}
		
		free(n);		
	}
	
	
	for(j=0; j<51; j++)
		printf("%d", sol[50-j]);
	printf("\n");
	
	free(pf);
	free(sol);
	
	return 0;
}
