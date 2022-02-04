#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double*, double*);
void gradient_f(double*, double*, double*);
int hessian_f(double**, double*, double*);

int gauss(int, double**, double*, double);
int resoltrisup(int, double**, double*, double);

int main(void){
	int n = 6, MAX = 100000, i, k;
	double *x, *cy, *grad, **hes, tol = 1.e-12, step = 0.025;
	
	x = (double*)malloc(8*sizeof(double));
	if(x==NULL){printf("Err:NoMem\n"); return 1;}
	
	/*initialize the points of x in the diagonal*/
	x[0] = 0.;
	x[7] = (100. / sqrt(2.));

    for(i = 1; i < 7; i++)
        x[i] = x[7] / 2. - 25. + (double)(i - 1) * 10.;

    /* Compute the squared differences of y*/
	cy = (double*)malloc(7*sizeof(double));
	if(cy==NULL){printf("Err:NoMem\n"); return 1;}

    for(i = 0; i < 7; i++) {
        cy[i] = (x[i] - x[i + 1]) * (x[i] - x[i + 1]);
    }

    for(k = 0; k < MAX; k++) {
        grad = (double*)malloc(6 * sizeof(double));
            if(grad == NULL){ printf("Err: No mem. In 'grad'\n"); return 1;}

        hes = (double**)malloc(6 * sizeof(double*));
            if(hes == NULL){ printf("Err: No mem. In 'grad'\n"); return 1;}
        
        for(i = 0; i < 6; i++) {
            hes[i] = (double*)calloc(6, sizeof(double));
                if(hes[i] == NULL){ printf("Err: No mem. In 'hes'\n"); return 1;}
        }
	    

        gradient_f(grad, x, cy);
        hessian_f(hes, x, cy);
        
        /*
        for(i = 0; i < 6; i++) {
            printf("%e\n", grad[i]);
        }
        */
        
        gauss(n, hes, grad, tol);
        resoltrisup(n, hes, grad, tol);

        for(i = 1; i < 7; i++){
            x[i] += step * grad[i - 1];
        }

	    /*printf("%.12f\n", f(x, cy));*/
	    /*printf("%d\t%d\n\n", ga, res);*/

        free(grad);
        for(i = 0; i < 6; i++)
            free(hes[i]);
        free(hes);
    }
	
    printf("%.10f\n\n", f(x, cy));

	free(x);
    free(cy);

    return 0;
}

/*Function that computes the time between A and B
* f(x_1,...,x_6)*/
double f(double *x, double *cy){
	int i;
	double time = 0., speed[7] = {10., 9., 8., 7., 6., 5., 10.};
	
	for(i = 0; i < 7; i++) {
        time += sqrt(cy[i] + ((x[i + 1] - x[i]) * (x[i + 1] - x[i]))) / speed[i];
    }
	
	return time;
}

/* Compute the gradient of f */
void gradient_f(double *grad, double *x, double *cy) {
    int i;
    double speed[7] = {10., 9., 8., 7., 6., 5., 10.};

    for(i = 0; i < 6; i++) {
        grad[i] = (x[i + 1] - x[i])         / (speed[i]         * sqrt(cy[i]        + ((x[i + 1] - x[i]) * (x[i + 1] - x[i]))));
        grad[i] -= (x[i + 2] - x[i + 1])    / (speed[i + 1]     * sqrt(cy[i + 1]    + ((x[i + 2] - x[i + 1]) * (x[i + 2] - x[i + 1]))));
        grad[i] *= -1.;
    }
}

int hessian_f(double **hes, double *x, double *cy) {
    int i;
    double *a, speed[7] = {10., 9., 8., 7., 6., 5., 10.};

    a = (double*)malloc(7 * sizeof(double));
        if(a == NULL){ printf("Err: No mem. In 'hes'\n"); return 1;}

    /*Compute A_i*/
    for(i = 0; i < 7; i++) {
        a[i] = cy[i] + ((x[i + 1] - x[i]) * (x[i + 1] - x[i]));
        a[i] = cy[i] / (speed[i] * sqrt(a[i] * a[i] * a[i]));
    }

    hes[0][0] = a[0] + a[1];
    for(i = 1; i < 6; i++) {
        hes[i][i] = a[i] + a[i + 1];
        hes[i][i - 1] = a[i];
        hes[i - 1][i] = a[i];
    }

    free(a);

    return 0;
}

int gauss(int n, double **a, double *b, double tol){
	int k, i, j;
	double m;
	for(k=0; k<(n-1); k++){
		if(fabs(a[k][k])<tol){
			return k+1;
		}
		for(i=(k+1); i<n; i++){
			m= (a[i][k])/(a[k][k]);
			for(j=k+1; j<n; j++){
				a[i][j]= a[i][j]-(m*(a[k][j]));
			}
			b[i]= b[i]-(m*b[k]);
			a[i][k]= m;
		}
	}
	return 0;
}

int resoltrisup(int n, double **A, double *b, double tol){
	int i, j;
	double aux;
	if(fabs(A[n-1][n-1])<tol)
		return 1;
	b[n-1]= b[n-1]/A[n-1][n-1];
	for(i=n-2;i>=0;i--){
		if(fabs(A[i][i])<tol)
			return n-i;
		aux= 0.;
		for(j=i+1;j<n;j++){
			aux+= A[i][j]*b[j];
		}
		b[i]= b[i]- aux;
		b[i]= b[i]/A[i][i];
	}
	return 0;
}

