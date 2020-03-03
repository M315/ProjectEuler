#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun(int*);

int main(void){
	int i, j, **sol, *aux, c, s0, s1, s2, s3, s4, s5, k0, k1, k2, k3, k4, k5;
	
	sol= (int **)malloc(6*sizeof(int*));
		if(sol==NULL){printf("no mem\n"); exit(-1);}
	for(i=0; i<6; i++){
		sol[i]= (int *)calloc(7, sizeof(int));
			if(sol[i]==NULL){printf("No mem\n"); exit(-1);}
	}
	aux= (int *)calloc(6, sizeof(int));
		if(aux==NULL){printf("no mem\n"); exit(-1);}
	
	for(sol[0][0]=1000; sol[0][0]<9999; sol[0][0]++){
		fun(sol[0]);
		
		s0= (sol[0][1]+sol[0][2]+sol[0][3]+sol[0][4]+sol[0][5]+sol[0][6]);
		for(k0=0; k0<s0; k0++){
			c=0;
			for(i=1; i<7; i++){
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
					
					s1= (sol[1][1]+sol[1][2]+sol[1][3]+sol[1][4]+sol[1][5]+sol[1][6]);
					for(k1=0; k1<s1; k1++){
						c=0;
						for(i=1; i<7; i++){
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
					
						for(i=0; i<6; i++) aux[i]=0;
						
						for(i=0; i<2; i++)
							for(j=0; j<6; j++)
								if(sol[i][j+1]==1)
									aux[j]=1;
											
						if((aux[0]+aux[1]+aux[2]+aux[3]+aux[4]+aux[5])>1){
							sol[2][0]= 100*(sol[1][0]%100);
							
							if((sol[2][0]/100)>=(sol[1][0]/100)){
								if((sol[2][0]/100)==(sol[1][0]/100)){ sol[2][0]= sol[1][0]+1;}
								
								for(sol[2][0]=sol[2][0]; sol[2][0]<(100*((sol[1][0]%100)+1)); sol[2][0]++){
									fun(sol[2]);
									
									s2= (sol[2][1]+sol[2][2]+sol[2][3]+sol[2][4]+sol[2][5]+sol[2][6]);
									for(k2=0; k2<s2; k2++){
										c=0;
										for(i=1; i<7; i++){
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
									
										for(i=0; i<6; i++) aux[i]=0;
						
										for(i=0; i<3; i++)
											for(j=0; j<6; j++)
												if(sol[i][j+1]==1)
													aux[j]=1;
										
										if((aux[0]+aux[1]+aux[2]+aux[3]+aux[4]+aux[5])>2){
											sol[3][0]= 100*(sol[2][0]%100);
											
											if((sol[3][0]/100)>=(sol[2][0]/100)){
												if((sol[3][0]/100)==(sol[2][0]/100)){ sol[3][0]= sol[2][0]+1;}
												
												for(sol[3][0]=sol[3][0]; sol[3][0]<(100*((sol[2][0]%100)+1)); sol[3][0]++){
													fun(sol[3]);
													
													
													s3= (sol[3][1]+sol[3][2]+sol[3][3]+sol[3][4]+sol[3][5]+sol[3][6]);
													for(k3=0; k3<s3; k3++){
														c=0;
														for(i=1; i<7; i++){
															if((c<k3) && (sol[3][i]!=0)){
																sol[3][i]=0;
																c++;
															}else{
																if((c==k3) && (sol[3][i]!=0)){
																	c++;
																}else{
																	sol[3][i]=0;
																}
															}
														}
													
														for(i=0; i<6; i++) aux[i]=0;
								
														for(i=0; i<4; i++)
															for(j=0; j<6; j++)
																if(sol[i][j+1]==1)
																	aux[j]=1;
											
														if((aux[0]+aux[1]+aux[2]+aux[3]+aux[4]+aux[5])>3){
															sol[4][0]= 100*(sol[3][0]%100);
															
															if((sol[4][0]/100)>=(sol[3][0]/100)){
																if((sol[4][0]/100)==(sol[3][0]/100)){ sol[4][0]= sol[3][0]+1;}
														
																for(sol[4][0]=sol[4][0]; sol[4][0]<(100*((sol[3][0]%100)+1)); sol[4][0]++){
																	fun(sol[4]);
																	
																	s4= (sol[4][1]+sol[4][2]+sol[4][3]+sol[4][4]+sol[4][5]+sol[4][6]);
																	for(k4=0; k4<s4; k4++){
																		c=0;
																		for(i=1; i<7; i++){
																			if((c<k4) && (sol[4][i]!=0)){
																				sol[4][i]=0;
																				c++;
																			}else{
																				if((c==k4) && (sol[4][i]!=0)){
																				c++;
																				}else{
																					sol[4][i]=0;
																				}
																			}
																		}
																	
																		for(i=0; i<5; i++) aux[i]=0;
																		
																		for(i=0; i<6; i++)
																			for(j=0; j<6; j++)
																				if(sol[i][j+1]==1)
																					aux[j]=1;
															
																		if((aux[0]+aux[1]+aux[2]+aux[3]+aux[4]+aux[5])>4){
																			sol[5][0]= 100*(sol[4][0]%100);
																			
																			if((sol[5][0]/100)>=(sol[4][0]/100)){
																				if((sol[5][0]/100)==(sol[4][0]/100)){ sol[5][0]= sol[4][0]+1;}
																				
																				for(sol[5][0]=sol[5][0]; sol[5][0]<(100*((sol[4][0]%100)+1)); sol[5][0]++){
																					fun(sol[5]);
																					
																					s5= (sol[5][1]+sol[5][2]+sol[5][3]+sol[5][4]+sol[5][5]+sol[5][6]);
																					for(k5=0; k5<s5; k5++){
																						c=0;
																						for(i=1; i<7; i++){
																							if((c<k5) && (sol[5][i]!=0)){
																								sol[5][i]=0;
																								c++;
																							}else{
																								if((c==k5) && (sol[5][i]!=0)){
																									c++;
																								}else{
																									sol[5][i]=0;
																								}
																							}
																						}
																					
																						for(i=0; i<6; i++) aux[i]=0;
										
																							for(i=0; i<6; i++)
																								for(j=0; j<6; j++)
																									if(sol[i][j+1]==1)
																										aux[j]=1;
																						
																						if((aux[0]+aux[1]+aux[2]+aux[3]+aux[4]+aux[5])>5){
																							for(i=0; i<6; i++)
																								printf("%d %d %d %d %d %d %d\n", sol[i][0], sol[i][1], sol[i][2], sol[i][3], sol[i][4], sol[i][5], sol[i][6]);
																							
																							printf("\n*%d*\n\n", sol[0][0]+sol[1][0]+sol[2][0]+sol[3][0]+sol[4][0]+sol[5][0]);
																							
																							return 1;
																						}
																						fun(sol[5]);
																						
																					}
																					for(i=1; i<7; i++)
																						sol[5][i]=0;					
																				}
																			}
																		
																		}
																		fun(sol[4]);
																		
																	}
																	for(i=1; i<7; i++)
																		sol[4][i]=0;					
																}
															}
														
														}
														fun(sol[3]);
														
													}
													for(i=1; i<7; i++)
														sol[3][i]=0;					
												}
											}
											
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
	
	aux=(1+(int)sqrt(1+8*n[0]))/4;
	if(n[0]==(aux*(2*aux-1))){
		n[4]=1;
	}
	
	aux= (3+(int)sqrt(9+40*n[0]))/10;
	if(n[0]==(aux*(5*aux-3)/2)){
		n[5]=1;
	}
	
	aux= (2+(int)sqrt(4+12*n[0]))/6;
	if(n[0]==(aux*(3*aux-2))){
		n[6]=1;
	}
	
	return;
}
