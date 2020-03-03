#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int i, j, k, l;
	double **g, p, maxp=0;
	
	g= (double **)malloc(20*sizeof(double *));
		if(g==NULL){ printf("No hi ha memoria\n"); exit(1);}
	for(i=0; i<20; i++){
		g[i]=(double *)calloc(20, sizeof(double));
			if(g[i]==NULL){ printf("No hi ha memoria\n"); exit(1);}
	}
	
	printf("0.0\n");
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			scanf("%le", &g[i][j]);
			printf("%g ", g[i][j]);
		}
		printf("\n");
	}
	printf("0.1 ");
	
	printf("1.0 ");
	for(i=0; i<20; i++){
		for(j=0; j<17; j++){
			p= (g[i][j]*g[i][j+1]*g[i][j+2]*g[i][j+3]);
			if(p>maxp)
				maxp= p;
		}
	}
	printf("1.1 ");
	
	printf("2.0 ");	
	for(j=0; j<20; j++){
		for(i=0; i<17; j++){
			p= (g[i][j]*g[i+1][j]*g[i+2][j]*g[i+3][j]);
			if(p>maxp)
				maxp= p;
		}
	}
	printf("2.1 ");
	
	printf("3.0 ");	
	for(k=0; k<16; k++){
		for(l=0; l<(k+1); l++){
			p= g[16-k+l][l]*g[16-k+l+1][l+1]*g[16-k+l+2][l+2]*g[16-k+l+3][l+3];
			if(p>maxp)
				maxp= p;
			p= g[l][16-k+l]*g[l+1][16-k+l+1]*g[l+2][16-k+l+2]*g[l+3][16-k+l+3];
			if(p>maxp)
				maxp= p;
		}
	}
	printf("3.1 ");
	
	printf("4.0 ");
	for(k=0; k<17; k++){
		p= (g[k][k]*g[k+1][k+1]*g[k+2][k+2]*g[k+3][k+3]);
		if(p>maxp)
				maxp= p;
	}
	printf("4.1\n");
		
	printf("%g\n", maxp);	
	
	return 0;
}
