#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int primechek(int);
int digitpremutatitionchek(int, int);

int main(void){
	int p;
	
	for(p=1001; p<3339; p=p+2){
		if(primechek(p)==1){
			if(primechek(p+3330)==1 && digitpremutatitionchek(p,p+3330)==1){
				if(primechek(p+6660)==1 && digitpremutatitionchek(p,p+6660)==1){
					printf("%d\n", p);
				}
			}
		}
	}
	return 0;
}

int primechek(int a){
	int n;
	if(a%2==0)
		return 0;
	for(n=3; n<=sqrt(a); n=n+2)
		if(a%n==0)
			return 0;
	return 1;
}

int digitpremutatitionchek(int a, int ak){
	int v[4], vk[4], i, j;
	for(i=0; i<4; i++){
		v[i]= a%10;
		a= a/10;
		vk[i]= ak%10;
		ak= ak/10;
	}
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(v[i]==vk[j]){
				vk[j]=-1;
				j=4;
			}
		}
	}
	if((vk[0]+vk[1]+vk[2]+vk[3])==-4){
		return 1;
	}
	return 0;
}
	
