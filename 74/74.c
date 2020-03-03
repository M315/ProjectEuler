/*El programa monta el cycle de la suma de factorials de cada digit d'un nombre
 *per tots el nombres fins a 1.e6, comprovant si el cylce te longitud 60 (la maxima
 *longitud per aquest cycles amb numbre inicial <=1.e6).
 *Crec que es important no calcular el factorial amb una funcio i ferho amb un switch
 *o un vector ja que amb nomes 9 posibles resultats estalbies molts calculs*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int i, j, n, sn, aux, f[10]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}, cy[61], control, count=0;
		
	for(n=3; n<=1000000; n++){
		cy[0]= n;
		for(i=1; i<61; i++)
			cy[i]=0;
		
		aux=n;
		
		j=1;
		
		do{
			sn=0;
			
			while(aux!=0){
				
				sn= sn+ f[aux%10];
				
				/*switch(f){
					case 0:
						sn= sn+1; break;
					case 1: 
						sn= sn+1; break;
					case 2:
						sn= sn+2; break;
					case 3:
						sn= sn+6; break;
					case 4:
						sn= sn+24; break;
					case 5:
						sn= sn+120; break;
					case 6:
						sn= sn+720; break;
					case 7:
						sn= sn+5040; break;
					case 8:
						sn= sn+40320; break;
					case 9:
						sn= sn+362880; break;
				}*/
				aux= aux/10;
			}
			
			cy[j]= sn;
			
			control=0;
			for(i=0; i<j; i++)
				if(sn==cy[i])
					control=1;
			
			aux= sn;			
			j++;
			
		}while(control==0 && j<61);
		
		if(j==61){
			count++;
			/*printf("\n");
			for(i=0; i<j-1; i++)
				printf("%d-> ", cy[i]);
			printf("(-> %d)\n", cy[j-1]);*/
		}
	}
	
	printf("\n*%d*\n\n", count);

	return 0;
}
