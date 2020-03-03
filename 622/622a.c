#include <stdio.h>
#include <stdlib.h>

int main(void){
	unsigned long long int n, a, aux, **o;
	int c, sum[25], i, co=0, j=0;
	
	for(i=0; i<25; i++)
		sum[i]=0;
	
	o= (unsigned long long int **)malloc(11*sizeof(unsigned long long int *));
		if(o==NULL){printf("No mem\n"); exit(-1);}
	for(i=0; i<11; i++){
		o[i]= (unsigned long long int *)calloc(30, sizeof(unsigned long long int));
			if(o[i]==NULL){printf("No mem\n"); exit(-1);}
	}
	
	printf("*%d*	", j);
	for(n=1; n<1.e6; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=-1;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<61 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==60){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<1.e6; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=-1;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<31 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==30){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<1.e6; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=-1;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<21 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==20){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<5*1.e5; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=-1;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<16 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==15){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<5*1.e4; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=1;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<13 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==12){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<5*1.e4; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=-1;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<61 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==11){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==10){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<1.e3; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=-1;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<7 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==6){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<1.e3; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=0;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<6 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==5){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<1.e3; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=0;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<5 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==4){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<1.e2; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=0;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<4 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==3){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	printf("*%d*	", j);
	for(n=1; n<1.e2; n=n+2){
		
		for(i=0; i<co; i++){
			if((n%o[j][i])==0){
				n=n+2;
				i=0;
			}
		}
		
		/*Calculem l'ordre de 2 modul n-1*/
		a=(n+1)/2;
		c=1;
		
		while(c<3 && a!=1){
			if(a%2==1){
				a= (a+n)/2;
			}else{
				a= a/2;
			}
			c++;
		}
		
		if(c==2){
			o[j][co]= n;
			co++;
			
			aux= n+1;
			for(i=24; i>=0; i--){
				sum[i]= sum[i]+aux%10;
				if(sum[i]>9){
					sum[i]= sum[i]%10;
					sum[i-1]++;
				}
				aux= aux/10;
			}
			printf("%lld ", n);
		}
		
		if(co==30){
			printf("***%lld***", n);
			break;
		}
	}
	printf(" %d\n", co);
	
	j++;
	co=0;
	
	
	for(i=0; i<11; i++)
		free(o[i]);
	free(o);
	
	for(i=0; i<25; i++)
		printf("%d", sum[i]);
	printf("\n");
	
	return 0;
}
