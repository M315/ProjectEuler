/*Solucionem el problema gracies a https://www.mathblog.dk/project-euler-66-diophantine-equation/
 *i http://www.ams.org/notices/200202/fea-lenstra.pdf
 * la solucio pasa per calcular una arrel, la qual la calculem amb un metode de fraccions recurrent.
 * 
 * el resultat es 661, pero no surt ja que el long long no te prous digits per ferho, es pot solucionar
 * usant __int128, pero no se com printarlo...*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int result=0, D;
	long long pmax=0, limit, m, d, a, num, numm1, numm2, den, denm1, denm2;
	 
	for(D=2; D<1001; D++){
		
		limit = (int)sqrt(D);
		if (limit * limit != D){
			
			m = 0;
			d = 1;
			a = limit;
			
			numm1 = 1;
			num = a;
			
			denm1 = 0;
			den = 1;
			
			while(num*num - D*den*den != 1){
				m = d * a - m;
				d = (D - m * m) / d;
				a = (limit + m) / d;
		 
				numm2 = numm1;
				numm1 = num;
				denm2 = denm1;
				denm1 = den;
		 
				num = a*numm1 + numm2;
				den = a * denm1 + denm2;
			}
		 
			if (num > pmax) {
				pmax = num;
				result = D;
				printf("%d-> %lld, %lld\n", D, pmax, den);
			}
		}
	}
	
	printf("\n*%d*\n\n", result);
	
	return 0;	
}
