#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);

int main(void){
  int i, j;
  long long int n=10, mod=998244353, sol;

  sol= n%mod;

  for(i=2; i<=n; i++){
    for(j=2; j<i; j++){
      sol= (sol+(gcd(i,j)%mod))%mod;
    }
    sol= (sol+(i%mod))%mod;
  }

  printf("%lld\n", sol);

  return 0;
}

int gcd(int a, int b){
	int temp;
  while (b != 0){
		temp = a % b;
		a = b;
    b = temp;
  }
  return a;
}
