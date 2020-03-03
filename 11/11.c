#include <stdio.h>
#include <stdlib.h>

int main(void){
	int g[20][20], i, j;
	unsigned long long int pmax=0, p;
	FILE *pf;
	
	pf= fopen("taula.txt", "r");
		if(pf==NULL){printf("No File\n"); return -1;}
	
	for(i=0; i<20; i++)
		for(j=0; j<20; j++)
			fscanf(pf, "%d", &g[i][j]);
		
	fclose(pf);
	
	for(i=0; i<17; i++){
		for(j=0; j<17; j++){
			p= g[i][j]*g[i][j+1]*g[i][j+2]*g[i][j+3];
			if(p>pmax){
				pmax=p;
			}
			
			p= g[i][j]*g[i+1][j]*g[i+2][j]*g[i+3][j];
			if(p>pmax){
				pmax=p;
			}
			
			p= g[i][j]*g[i+1][j+1]*g[i+2][j+2]*g[i+3][j+3];
			if(p>pmax){
				pmax=p;
			}
		}
	}
	
	for(i=0; i<17; i++){
		for(j=4; j<20; j++){
			p= g[i][j]*g[i+1][j-1]*g[i+2][j-2]*g[i+3][j-3];
			if(p>pmax){
				pmax=p;
			}
		}
	}
	
	for(i=0; i<17; i++){
		for(j=17; j<20; j++){
			p= g[i][j]*g[i+1][j]*g[i+2][j]*g[i+3][j];
			if(p>pmax){
				pmax=p;
			}
		}
	}
	
	for(i=17; i<20; i++){
		for(j=0; j<17; j++){
			p= g[i][j]*g[i][j+1]*g[i][j+2]*g[i][j+3];
			if(p>pmax){
				pmax=p;
			}
		}
	}
	
	printf("%lld\n", pmax);	
	
	return 0;
}
