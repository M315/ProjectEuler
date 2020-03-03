#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun(int*);

int main(void){
	int i, j, **sol, *aux, c, s0, s1, s2, k0, k1, k2;
	
	sol= (int **)malloc(3*sizeof(int*));
		if(sol==NULL){printf("no mem\n"); exit(-1);}
	for(i=0; i<3; i++){
		sol[i]= (int *)calloc(4, sizeof(int));
			if(sol[i]==NULL){printf("No mem\n"); exit(-1);}
	}
	aux= (int *)calloc(3, sizeof(int));
		if(aux==NULL){printf("no mem\n"); exit(-1);}
	
	for(sol[0][0]=1000; sol[0][0]<9999; sol[0][0]++){
		fun(sol[0]);
		
		s0= (sol[0][1]+sol[0][2]+sol[0][3]);
		for(k0=0; k0<s0; k0++){
			c=0;
			for(i=1; i<4; i++){
				if((c<k0) && (sol[0][i]!=0)){
					sol[0][i]=0;
					c++;
				}else{
					if((c==k0) && (sol[0][i]!=0)){
						c++;
					}else{
						sol[0][i]=0;
					}
				}
			}
			
			sol[1][0]= 100*(sol[0][0]%100);
			
			if((sol[1][0]/100)>=(sol[0][0]/100)){
				if((sol[1][0]/100)==(sol[0][0]/100)){ sol[1][0]= sol[0][0]+1;}
				
				for(sol[1][0]=sol[1][0]; sol[1][0]<(100*((sol[0][0]%100)+1)); sol[1][0]++){
					fun(sol[1]);
					
					s1= (sol[1][1]+sol[1][2]+sol[1][3]);
					for(k1=0; k1<s1; k1++){
						c=0;
						for(i=1; i<4; i++){
							if((c<k1) && (sol[1][i]!=0)){
								sol[1][i]=0;
								c++;
							}else{
								if((c==k1) && (sol[1][i]!=0)){
									c++;
								}else{
									sol[1][i]=0;
								}
							}
						}
					
						for(i=0; i<3; i++) aux[i]=0;
						
						for(i=0; i<2; i++)
							for(j=0; j<3; j++)
								if(sol[i][j+1]==1)
									aux[j]=1;
											
						if((aux[0]+aux[1]+aux[2])>1){
							sol[2][0]= 100*(sol[1][0]%100);
							
							if((sol[2][0]/100)>=(sol[1][0]/100)){
								if((sol[2][0]/100)==(sol[1][0]/100)){ sol[2][0]= sol[1][0]+1;}
								
								for(sol[2][0]=sol[2][0]; sol[2][0]<(100*((sol[1][0]%100)+1)); sol[2][0]++){
									fun(sol[2]);
									
									s2= (sol[2][1]+sol[2][2]+sol[2][3]);
									for(k2=0; k2<s2; k2++){
										c=0;
										for(i=1; i<4; i++){
											if((c<k2) && (sol[2][i]!=0)){
												sol[2][i]=0;
												c++;
											}else{
												if((c==k2) && (sol[2][i]!=0)){
												c++;
												}else{
													sol[2][i]=0;
												}
											}
										}
									
										for(i=0; i<3; i++) aux[i]=0;
						
										for(i=0; i<3; i++)
											for(j=0; j<3; j++)
												if(sol[i][j+1]==1)
													aux[j]=1;
										
										if((aux[0]+aux[1]+aux[2])>2){
											for(i=0; i<3; i++)
												printf("%d %d %d %d\n", sol[i][0], sol[i][1], sol[i][2], sol[i][3]);
																							
											return 1;
										}
										fun(sol[2]);
									}
									
									for(i=1; i<7; i++)
										sol[2][i]=0;					
								}
							}
							
						}
						fun(sol[1]);
					}
						
					for(i=1; i<7; i++)
						sol[1][i]=0;					
				}
			}
			
			fun(sol[0]);		
		}
		
		for(i=1; i<7; i++)
				sol[0][i]=0;			
	}	

	return 0;
}

void fun(int *n){
	int aux;
	
	aux= (-1+(int)sqrt(1+8*n[0]))/2;
	if(n[0]==(aux*(aux+1)/2)){
		n[1]=1;
	}
	
	if(n[0]==(((int)sqrt(n[0]))*((int)sqrt(n[0])))){
		n[2]=1;
	}
	
	aux= (1+(int)sqrt(1+24*n[0]))/6;
	if(n[0]==(aux*(3*aux-1)/2)){
		n[3]=1;
	}
	
	return;
}
