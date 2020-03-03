#include <stdio.h>
#include <stdlib.h>

int main(void){
	int ways=0, p2, p5, p10, p20, p50, p100, p200;
	
	for(p200=200; p200>=0; p200-=200)
		for(p100=p200; p100>=0; p100-=100)
			for(p50=p100; p50>=0; p50-=50)
				for(p20=p50; p20>=0; p20-=20)
					for(p10=p20; p10>=0; p10-=10)
						for(p5=p10; p5>=0; p5-=5)
							for(p2=p5; p2>=0; p2-=2)
								ways++;
	
	printf("%d\n", ways);
	
	return 0;
}
