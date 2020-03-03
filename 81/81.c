#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long int AS(int**, int**);
long int h(int, int, int**);
int compf(const void *p, const void *q);

int main(void){
	int **a, **path, n=80, i, j;
	long int min;
	FILE *pf;

	a= (int**)malloc(n*sizeof(int*));
		if(a==NULL){printf("No mem\n"); exit(-1);}
	for(i=0; i<n; i++){
		a[i]= (int*)malloc(n*sizeof(int));
			if(a[i]==NULL){printf("No mem\n"); exit(-1);}
	}

	path= (int**)malloc(159*sizeof(int*));
		if(path==NULL){printf("No mem\n"); exit(-1);}
	for(i=0; i<159; i++){
		path[i]= (int*)calloc(2, sizeof(int));
			if(path[i]==NULL){printf("No mem\n"); exit(-1);}
	}

	pf= fopen("a.txt", "r");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			fscanf(pf, "%d", &a[i][j]);
	fclose(pf);

	min= AS(a, path);
	printf("%ld\n\n", min);
	for(i=0; i<159; i++){
		printf("(%d,%d) ", path[i][0], path[i][1]);
	}

	for(i=0; i<n; i++){
		free(a[i]);
	}
	free(a);
	for(i=0; i<159; i++){
		free(path[i]);
	}
	free(path);

	return 0;
}

long int AS(int **a, int **path){
	int i, j, nopen=1;
	int **used, ***origin;
	long int **open, **gscore, **fScore, tgscore, **aux;

	open= (long int**)malloc(nopen*sizeof(long int *));
		if(open==NULL){printf("No mem\n"); exit(-1);}
	for(i=0; i<80; i++){
		open[i]= (long int*)malloc(3*sizeof(long int));
			if(open[i]==NULL){printf("No mem\n"); exit(-1);}
	}
	open[0][0]= 0;
	open[0][1]= 0;

	origin= (int***)malloc(80*sizeof(int**));
		if(origin==NULL){printf("No mem\n"); exit(-1);}
	for(i=0; i<80; i++){
		origin[i]= (int**)malloc(80*sizeof(int*));
			if(origin[i]==NULL){printf("No mem\n"); exit(-1);}
			for(j=0; j<80; j++){
				origin[i][j]= (int*)calloc(2, sizeof(int));
					if(origin[i][j]==NULL){printf("No mem\n"); exit(-1);}
			}
	}

	used= (int**)malloc(80*sizeof(int*));
		if(used==NULL){printf("No mem\n"); exit(-1);}
	for(i=0; i<80; i++){
		used[i]= (int*)calloc(80, sizeof(int));
			if(used[i]==NULL){printf("No mem\n"); exit(-1);}
	}
	used[0][0]++;

	/*gScore is the cost to get to each node*/
	gscore= (long int**)malloc(80*sizeof(long int*));
		if(a==NULL){printf("No mem\n"); exit(-1);}
	for(i=0; i<80; i++){
		gscore[i]= (long int*)malloc((i+1)*sizeof(long int));
			if(gscore[i]==NULL){printf("No mem\n"); exit(-1);}
	}

	for(i=0; i<80; i++)
		for(j=0; j<80; j++)
			gscore[i][j]= LONG_MAX;
	gscore[0][0]= a[0][0];

	/*fScore is the cost to get to this node+ the expected cost to get to the goal*/
	fScore= (long int**)malloc(80*sizeof(long int*));
		if(a==NULL){printf("No mem\n"); exit(-1);}
	for(i=0; i<80; i++){
		fScore[i]= (long int*)malloc(80*sizeof(long int));
			if(fScore[i]==NULL){printf("No mem\n"); exit(-1);}
	}

	for(i=0; i<80; i++)
		for(j=0; j<80; j++)
			fScore[i][j]= LONG_MAX;
	fScore[0][0]= gscore[0][0]+h(0, 0, a);
	open[0][3]= fScore[0][0];

	while(nopen>0){
		qsort(open, nopen, sizeof(long int*), &compf);

		if(open[0][0]==79 && open[0][1]==79){
			tgscore= gscore[79][79];

			path[0][0]=79;
			path[0][1]=79;
			for(i=1; i<159; i++){
				path[i][0]= origin[path[i-1][0]][path[i-1][1]][0];
				path[i][1]= origin[path[i-1][0]][path[i-1][1]][1];
			}

			for(i=0; i<80; i++){
				free(used[i]);
				free(gscore[i]);
				free(fScore[i]);
			}
			free(used);
			free(gscore);
			free(fScore);

			return tgscore;
		}

		/*Find the right neighbor*/
		if((used[open[0][0]+1][open[0][1]])!=2 && open[0][0]<79){
			if((used[open[0][0]+1][open[0][1]])==0){
				(used[open[0][0]+1][open[0][1]])++;

				/*This is just to add an element to openset*/
				aux= (long int**)malloc(nopen*sizeof(long int *));
					if(open==NULL){printf("No mem\n"); exit(-1);}
				for(i=0; i<80; i++){
					aux[i]= (long int*)malloc(3*sizeof(long int));
						if(aux[i]==NULL){printf("No mem\n"); exit(-1);}
				}
				for(i=0; i<nopen; i++){
					for(j=0; j<3; j++){
						aux[i][j]= open[i][j];
					}
				}
				for(i=0; i<nopen; i++){
					free(open[i]);
				}
				free(open);
				open= (long int**)malloc((nopen+1)*sizeof(long int *));
					if(open==NULL){printf("No mem\n"); exit(-1);}
				for(i=0; i<80; i++){
					open[i]= (long int*)calloc(3, sizeof(long int));
						if(open[i]==NULL){printf("No mem\n"); exit(-1);}
				}
				for(i=0; i<nopen; i++){
					for(j=0; j<3; j++){
						open[i][j]= aux[i][j];
					}
				}
				open[nopen][0]= open[0][0]+1;
				open[nopen][1]= open[0][1];
				for(i=0; i<nopen; i++){
					free(aux[i]);
				}
				free(aux);
			}

			tgscore= gscore[open[0][0]][open[0][1]]+ a[open[0][0]+1][open[0][1]];
			if(tgscore<(gscore[open[0][0]+1][open[0][1]])){
				origin[open[0][0]+1][open[0][1]][0]= open[0][0];
				origin[open[0][0]+1][open[0][1]][1]= open[0][1];

				gscore[open[0][0]+1][open[0][1]]= tgscore;
				fScore[open[0][0]+1][open[0][1]]= tgscore+h(open[0][0]+1, open[0][1], a);
			}
		}

		if((used[open[0][0]][open[0][1]+1])!=2 && open[0][1]<79){
			if((used[open[0][0]][open[0][1]+1])==0){
				(used[open[0][0]][open[0][1]+1])++;

				/*This is just to add an element to openset*/
				aux= (long int**)malloc(nopen*sizeof(long int *));
					if(open==NULL){printf("No mem\n"); exit(-1);}
				for(i=0; i<80; i++){
					aux[i]= (long int*)malloc(3*sizeof(long int));
						if(aux[i]==NULL){printf("No mem\n"); exit(-1);}
				}
				for(i=0; i<nopen; i++){
					for(j=0; j<3; j++){
						aux[i][j]= open[i][j];
					}
				}
				for(i=0; i<nopen; i++){
					free(open[i]);
				}
				free(open);
				open= (long int**)malloc((nopen+1)*sizeof(long int *));
					if(open==NULL){printf("No mem\n"); exit(-1);}
				for(i=0; i<80; i++){
					open[i]= (long int*)calloc(3, sizeof(long int));
						if(open[i]==NULL){printf("No mem\n"); exit(-1);}
				}
				for(i=0; i<nopen; i++){
					for(j=0; j<3; j++){
						open[i][j]= aux[i][j];
					}
				}
				open[nopen][0]= open[0][0];
				open[nopen][1]= open[0][1]+1;
				for(i=0; i<nopen; i++){
					free(aux[i]);
				}
				free(aux);
			}

			tgscore= gscore[open[0][0]][open[0][1]]+ a[open[0][0]][open[0][1]+1];
			if(tgscore<(gscore[open[0][0]][open[0][1]+1])){
				origin[open[0][0]][open[0][1]+1][0]= open[0][0];
				origin[open[0][0]][open[0][1]+1][1]= open[0][1];

				gscore[open[0][0]][open[0][1]+1]= tgscore;
				fScore[open[0][0]][open[0][1]+1]= tgscore+h(open[0][0], open[0][1]+1, a);
			}
		}

		/*This is just to eliminate the first element of openset*/
		nopen--;
		aux= (long int**)malloc(nopen*sizeof(long int *));
			if(open==NULL){printf("No mem\n"); exit(-1);}
		for(i=0; i<80; i++){
			aux[i]= (long int*)malloc(3*sizeof(long int));
				if(aux[i]==NULL){printf("No mem\n"); exit(-1);}
		}
		for(i=0; i<nopen; i++){
			for(j=0; j<3; j++){
				aux[i][j]= open[i+1][j];
			}
		}
		for(i=0; i<=nopen; i++){
			free(open[i]);
		}
		free(open);
		open= (long int**)malloc(nopen*sizeof(long int *));
			if(open==NULL){printf("No mem\n"); exit(-1);}
		for(i=0; i<80; i++){
			open[i]= (long int*)malloc(3*sizeof(long int));
				if(open[i]==NULL){printf("No mem\n"); exit(-1);}
		}
		for(i=0; i<nopen; i++){
			for(j=0; j<3; j++){
				open[i][j]= aux[i][j];
			}
		}
		for(i=0; i<nopen; i++){
			free(aux[i]);
		}
		free(aux);

		(used[open[0][0]][open[0][1]])++;

		for(i=0; i<nopen; i++){
			open[i][3]= fScore[open[i][0]][open[i][1]];
		}
	}
	return -1;
}

long int h(int x, int y, int **a){
	long int s=0;

	while(x<79 || y<79){
		if(x>y){
			y++;
			s+=a[x][y];
		}else{
			x++;
			s+=a[x][y];
		}
	}
	return s;
}

int compf(const void *p, const void *q){
	long long int* x = *(long long int**)p;
	long long int* y = *(long long int**)q;

	if(x[3]<=y[3]){
		return -1;
	}else{
		return 1;
	}
	return 0;
}
