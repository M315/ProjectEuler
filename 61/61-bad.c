/*El programa troba un conjunt de nombres que compleixen l'enunciat pero els ordena
 * com a trigangular->quadrat->pentagonal->hexagonal->heptagonal->octogonal*/

#include <stdio.h>
#include <math.h>

int main(void){
	int i, j, sol[6]={0,0,0,0,0,0}, aux, sum=0;
	
	for(i=45; i<142; i++){
		sol[0]= (i*(i+1))/2;
		sol[1]= 100*(sol[0]%100);
		
		printf("%d\n", sol[0]);
		
		if(sol[1]>999)		
		do{
			if(sol[1]==(((int)sqrt(sol[1]))*((int)sqrt(sol[1])))){
				
				printf("\t%d\n", sol[1]);
				
				sol[2]= 100*(sol[1]%100);
				
				if(sol[2]>999)
					do{
						aux= (1+(int)sqrt(1+24*sol[2]))/6;
						if(sol[2]==(aux*(3*aux-1)/2)){
							
							printf("\t\t%d\n", sol[2]);
							
							sol[3]= 100*(sol[2]%100);
							
							if(sol[3]>999)
								do{
									aux=(1+(int)sqrt(1+8*sol[3]))/4;
									if(sol[3]==(aux*(2*aux-1))){
										
										printf("\t\t\t%d\n", sol[3]);
										
										sol[4]= 100*(sol[3]%100);
										
										if(sol[4]>999)
											do{
												aux= (3+(int)sqrt(9+40*sol[4]))/10;
												if(sol[4]==(aux*(5*aux-3)/2)){
													
													printf("\t\t\t\t%d\n", sol[4]);
													
													sol[5]= 100*(sol[4]%100);
													
													if(sol[5]>999)
														do{
															aux= (2+(int)sqrt(4+12*sol[5]))/6;
															if(sol[5]==(aux*(3*aux-2))){
																
																printf("\t\t\t\t\t%d\n", sol[5]);
																
																for(j=0; j<6; j++){
																	sum= sum+sol[j];
																	printf("%d\n", sol[j]);
																}
																printf("\n*%d*\n", sum);
																
																return 1;
															}
															
															sol[5]++;
														}while((sol[5]/100)==(sol[4]%100));
												}
												
												sol[4]++;
											}while((sol[4]/100)==(sol[3]%100));
									}
									
									sol[3]++;
								}while((sol[3]/100)==(sol[2]%100));
							
						}
						
						sol[2]++;
					}while((sol[2]/100)==(sol[1]%100));
			}
			
			sol[1]++;			
		}while((sol[1]/100)==(sol[0]%100));
	}
	
	printf("hello\n");
	

	return 0;
}
