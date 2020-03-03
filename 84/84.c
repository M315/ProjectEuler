/*With Comunity chest (CC) I make it really random at the early times that u fall in
 *but in cahnce (CH) just ordered the options initialy, thats cause with egouht
 *iterations it dosent afect too much the result (could also do taht with CC).
 *to get a better aproximation we must improve the randomize of the dice cause
 *its not true random and dont have enought uniformity.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
	int m[40], p=0, d1, d2, d, i, cc[16], ccc=0, j=0, cc0=1, cc10=1, ch[16], h=0, ec;
	
	srand((unsigned) time(NULL));
	
	for(i=0; i<40; i++)
		m[i]=0;
	
	for(i=0; i<16; i++)
		ch[i]= i;
	
	for(i=0; i<(1.e8); i++){
		d1= (rand()%4)+1;
		d2= (rand()%4)+1;
		
		if(d1==d2){
			d++;
		}else{
			d=0;
		}
		
		p= (p+d1+d2)%40;
		
		if(p==30 || d==3){ p=10;}
		
		if(p==2 || p==17 || p==33){
			if(ccc<16){
				if(cc0>0 || cc10>0){
					if(cc0==0){
						if((16-ccc)>1){
							do{
								cc[ccc]= rand()%(16-ccc);
							}while(cc[ccc]==0);
							if(cc[ccc]==1){
								p= 10;
								cc10--;
							}
						}else{
							p= 10;
							cc[ccc]= 1;
							cc10--;
						}
					}
					if(cc10==0){
						do{
							cc[ccc]= rand()%(16-ccc);
						}while(cc[ccc]==10);
						if(cc[ccc]==0){
							p= 0;
							cc0--;
						}
					}
					if(cc0>0 && cc10>0){
						cc[ccc]= rand()%(16-ccc);
						if(cc[ccc]==0){
							p= 0;
							cc0--;
						}
						if(cc[ccc]==1){
							p= 10;
							cc10--;
						}
					}
				}else{
					cc[ccc]=16;
				}
				ccc++;
			}else{
				if(cc[j]==0 || cc[j]==1)
					p= cc[j]*10;
				j= (j+1)%16;
			}
		}
		
		if(p==7 || p==22 || p==36){
			ec= 0;
			
			switch(ch[h]){
				case 0:
					p= 0; break;
				case 1:
					p= 10; break;
				case 2:
					p= 11; break;
				case 3: 
					p= 24; break;
				case 4:
					p= 39; break;
				case 5:
					p= 5; break;
				case 6:
					ec= 1; break;
				case 7:
					ec= 1; break;
				case 8:
					ec= 2; break;
				case 9:
					p= p-3; break;
			}
			
			if(ec==1){
				do{
					p= (p+1)%40;
				}while(p!=5 && p!= 15 && p!=25 && p!=35);
			}
			if(ec==2){
				do{
					p= (p+1)%40;
				}while(p!=12 && p!=28);
			}
			
			h= (h+1)%16;
		}
		
		m[p]++;
		
	}
	
	for(i=0; i<40; i++)
		printf("%d: %g\n", i, (double)m[i]*100./(1.e8));
		
	
	return 0;
}
