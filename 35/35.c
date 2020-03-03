/*The problem with this method comes when generate the numbers,
 * it is not trivial to do it without repeating cycles.
 * 
 * The best way to solve the problem its to generate a list of
 * primes to 1M and then discar those wich content an even number or a five,
 * and then make a new list with those whose all rotations are prime, and in
 * case a number its already in the list dont put it.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primecheck(int);
int rotacio(int, int);

int main(){
	int cp=13, dp[6]={0,0,0,1,1,1}, p, rp, rn, mdnn=3, i, j;

	while(dp[2]<9){
		p= 100000*dp[0]+10000*dp[1]+1000*dp[2]+100*dp[3]+10*dp[4]+dp[5];
		printf("%d ", p);
		rp= p;
		if(primecheck(rp)==1){
			rn=0;
			do{
			rp= rotacio(rp, mdnn);
			rn++;
			/*printf("~%d\n", rp);*/
			}while(primecheck(rp)==1 && rn<mdnn);
			if(rn==mdnn){	cp+=mdnn; printf("*%d*\n", p);}
		}
		
		for(i=5; i>=0; i--)
			if(dp[i]!=9) break;
			
		/*printf("++%d\n", i);*/
		
		if(dp[i]!=0){
			dp[i]= dp[i]+2;
		}else{
			dp[i]=1;
			mdnn++;
			printf("////%d\n", p);
		}
		for(j=i+1; j<=5; j++)
			dp[j]= dp[i];
	}

	printf("\n%d\n\n	%d\n\n", cp, p);

	return 0;
}

int primecheck(int a){
	int n;
	if(a%2==0)
		return 0;
	for(n=3; n<=sqrt(a); n=n+2)
		if(a%n==0)
			return 0;
	return 1;
}

int rotacio(int n, int m){
	/*Rota els m digits de n*/
	int i, f=1, d[m], r=0;
	for(i=m-1; i>=0; i--){
		d[i]= n%10;
		n= n/10;
	}
	for(i=0; i<m-1; i++){
		r= r+f*d[m-2-i];
		f= f*10;
	}
	return r+f*d[m-1];
}	
	
