#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int sum=0, i, j, aux, div3;
	int d2[2], d3[3], d4[4], auxd[4];
	
	/*Com que els nombres de 4 digits, son els unics que multiplicador*multiplicant=producte utilitzen 9 digits diferents*
	 *llistem tots els possibles nombres de 4 xifres amb tots els digits diferents*/ 
	for(i=1234; i<9999; i++){
		aux=i;
		auxd[3]= aux%10;
		aux= aux/10;
		auxd[2]= aux%10;
		aux= aux/10;
		auxd[1]= aux%10;
		aux= aux/10;
		auxd[0]= aux%10;
		
		if(auxd[0]!=0 && auxd[1]!=0 && auxd[2]!=0 && auxd[3]!=0){
			if(auxd[0]!=auxd[1] && auxd[0]!=auxd[2] && auxd[0]!=auxd[3] && auxd[1]!=auxd[2]	&& auxd[1]!=auxd[3] && auxd[2]!=auxd[3]){
				
				/*Ara em de comprovar si es producte de un nombre de 1 digit (diferent de 1 obiament xd) i un de quatre que tinguin la resta de nombres del 1 al 9
				 *primer busquem un multiplicador de 2 digits diferents dels que tenim*/
				for(j=2; j<10; j++){
					if(j!=auxd[0] && j!=auxd[1] && j!=auxd[2] && j!=auxd[3] && i%j==0){
						aux=i/j;
						d4[3]= aux%10;
						aux= aux/10;
						d4[2]= aux%10;
						aux= aux/10;
						d4[1]= aux%10;
						aux= aux/10;
						d4[0]= aux%10;
						
						if(d4[0]!=auxd[0] && d4[0]!=auxd[1] && d4[0]!=auxd[2] && d4[0]!=auxd[3] && d4[0]!=j && d4[1]!=auxd[0] && d4[1]!=auxd[1] && d4[1]!=auxd[2] && d4[1]!=auxd[3] && d4[1]!=j && d4[2]!=auxd[0] && d4[2]!=auxd[1] && d4[2]!=auxd[2] && d4[2]!=auxd[3] && d4[2]!=j && d4[3]!=auxd[0] && d4[3]!=auxd[1] && d4[3]!=auxd[2] && d4[3]!=auxd[3] && d4[3]!=j && d4[0]!=d4[1] && d4[0]!=d4[2] && d4[0]!=d4[3] && d4[1]!=d4[2] && d4[1]!=d4[3] && d4[2]!=d4[3] && d4[0]!=0 && d4[1]!=0 && d4[2]!=0 && d4[3]!=0){
							sum=sum+i;
							aux=(1000*d4[0])+(100*d4[1])+(10*d4[2])+d4[3];
							printf("#%d*%d=%d\n", j, aux, i);
							j=10;
						}
					}
				}
				
				/*Ara em de comprovar si es producte de un nombre de dos digits i un de tres que tinguin la resta de nombres del 1 al 9
				 *primer busquem un multiplicador de 2 digits diferents dels que tenim*/
				for(j=12; j<99; j++){
					d2[1]=j%10;
					d2[0]=j/10;
					if(d2[0]!=0 && d2[1]!=0){
						if(d2[0]!=auxd[0] && d2[0]!=auxd[1] && d2[0]!=auxd[2] && d2[0]!=auxd[3] && d2[1]!=auxd[0] && d2[1]!=auxd[1] && d2[1]!=auxd[2] && d2[1]!=auxd[3] && d2[0]!=d2[1]){
							/*Ara mirem si es un candidat valid*/							
							if(i%j==0){
								/*Finalment mirem si el multiplicador resultant te els tres digits que ens falten*/
								div3=i/j;
								d3[2]=div3%10;
								div3=div3/10;
								d3[1]=div3%10;
								div3=div3/10;
								d3[0]=div3%10;
								if(d3[0]!=0 && d3[1]!=0 && d3[2]!=0){
									if(d3[0]!=auxd[0] && d3[0]!=auxd[1] && d3[0]!=auxd[2] && d3[0]!=auxd[3] && d3[0]!=d2[0] && d3[0]!=d2[1] && d3[1]!=auxd[0] && d3[1]!=auxd[1] && d3[1]!=auxd[2] && d3[1]!=auxd[3] && d3[1]!=d2[0] && d3[1]!=d2[1]){
										if(d3[0]!=d3[1] && (d3[0]+d3[1]+d3[2]+d2[0]+d2[1]+auxd[0]+auxd[1]+auxd[2]+auxd[3])==45){
											sum=sum+i;
											div3=(100*d3[0])+(10*d3[1])+d3[2];
											printf("#%d*%d=%d\n", j, div3, i);
											j=100;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("\n%d\n", sum);
	
	return 0;
}
