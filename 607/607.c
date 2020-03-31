#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double F(double*);
double gradientF(double*);
double grad_desc(double*);

int main(void){
	int i;
	double **x, duration;
	
	x = (double**)malloc(8*sizeof(double*));
	if(x==NULL){printf("Err:NoMem\n"); return 1;}
	for(i=0; i<8; i++){
		x[i] = (double*)malloc(2*sizeof(double));
		if(x==NULL){printf("Err:NoMem\n"); return 1;}
	}
	
	/*initialize the points to the diagonal*/
	x[0][0] = 0.;
	x[0][1] = 0.;
	
	x[1][0] = ((100./sqrt(2.))-50.)/2.;
	x[1][1] = ((100./sqrt(2.))-50.)/2.;
	for(i=2; i<7; i++){
		x[i][0] = 0.;
		x[i][1] = x[i-1][1]+10.;
	}
	
	x[7][0] = (100./sqrt(2.));
	x[7][0] = (100./sqrt(2.));
	
	delta = 1.e-3;
	diff = -1;
	
	printf("%d\n", grad_desc(x));

	free(x);
	
	return 0;
}

/*Function that computes the time between A and B
* F(x_1,...,x_6) = f_1(x_1)+f_2(x_1,x_2)+...
* where f_i is the time at each part of the route
* ie out of the mesh or in a section of it.*/
double F(double *x){
	int i;
	double time, speed[7] = {10., 9., 8., 7., 6., 5., 10.};
	
	time = 0.;
	for(i=0; i<7; i++)
		time += sqrt(((x[i][0]-x[i+1][0])*(x[i][0]-x[i+1][0]))+(x[i][1]-x[i+1][1])*(x[i][1]-x[i+1][1]))/speed[i];
	
	return time;
}

double gradientF(double *x){
	int i;
	double grad, speed[7] = {10., 9., 8., 7., 6., 5., 10.};
	
	grad = 0;
	for(i=0; i<7; i++)
		grad += (x[i+1][0]-x[i][0])/(sqrt(((x[i][0]-x[i+1][0])*(x[i][0]-x[i+1][0]))+(x[i][1]-x[i+1][1])*(x[i][1]-x[i+1][1]))*speed[i]);
	
	return grad;
}

/*Use the gradient descent method to compute the result*/
double grad_desc(double *x){
	int i;
	double F0, F1, *gF0, *gF1, *x1;
	
	
	return F1;
}
