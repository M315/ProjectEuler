#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void*, const void*);

int main(void){
	int n, i, nh1[5], nh2[5], w=0;
	double p1, p2;
	char h[30];
	FILE *pf;
	
	pf= fopen("poker.txt", "r");
		if(pf==NULL){printf("No file\n"); return -1;}
	
	for(n=0; n<1000; n++){
		for(i=0; i<30; i++)
			h[i]= fgetc(pf);
		
		for(i=0; i<5; i++){
			switch(h[0+3*i]){
				case '2':
					nh1[i]=2; break;
				case '3': 
					nh1[i]=3; break;
				case '4':
					nh1[i]=4; break;
				case '5':
					nh1[i]=5; break;
				case '6':
					nh1[i]=6; break;
				case '7':
					nh1[i]=7; break;
				case '8':
					nh1[i]=8; break;
				case '9':
					nh1[i]=9; break;
				case 'T':
					nh1[i]=10; break;
				case 'J':
					nh1[i]=11; break;
				case 'Q':
					nh1[i]=12; break;
				case 'K':
					nh1[i]=13; break;
				case 'A':
					nh1[i]=14; break;
			}
		}
		qsort(nh1, 5, sizeof(int), cmpfunc);
		/*for(i=0; i<5; i++)
			printf("%d ", nh1[i]);
		printf("\n");*/
		
		for(i=0; i<5; i++){
			switch(h[15+3*i]){
				case '2':
					nh2[i]=2; break;
				case '3': 
					nh2[i]=3; break;
				case '4':
					nh2[i]=4; break;
				case '5':
					nh2[i]=5; break;
				case '6':
					nh2[i]=6; break;
				case '7': 
					nh2[i]=7; break;
				case '8':
					nh2[i]=8; break;
				case '9':
					nh2[i]=9; break;
				case 'T':
					nh2[i]=10; break;
				case 'J':
					nh2[i]=11; break;
				case 'Q':
					nh2[i]=12; break;
				case 'K':
					nh2[i]=13; break;
				case 'A':
					nh2[i]=14; break;
			}
		}
		qsort(nh2, 5, sizeof(int), cmpfunc);
		/*for(i=0; i<5; i++)
			printf("%d ", nh2[i]);
		printf("\n\n");*/
		
		if(h[1]==h[4] && h[1]==h[7] && h[1]==h[10] && h[1]==h[13]){
			if(nh1[0]==nh1[1]-1 && nh1[0]==nh1[2]-2 && nh1[0]==nh1[3]-3 && nh1[0]==nh1[4]-4){
				p1=8*15+nh1[4];
			}else{
				p1=5*15+nh1[4];
			}	
		}else{
			if(nh1[0]==nh1[1]-1 && nh1[0]==nh1[2]-2 && nh1[0]==nh1[3]-3 && nh1[0]==nh1[4]-4){
				p1=4*15+nh1[4];
			}else{
				if((nh1[0]==nh1[1] && nh1[0]==nh1[2] && nh1[0]==nh1[3]) || (nh1[1]==nh1[2] && nh1[1]==nh1[3] && nh1[1]==nh1[4])){
					p1=7*15+nh1[2];
				}else{
					if((nh1[0]==nh1[1] && nh1[0]==nh1[2] && nh1[3]==nh1[4]) || (nh1[0]==nh1[1] && nh1[2]==nh1[3] && nh1[2]==nh1[4])){
						p1=6*15+nh1[2];
					}else{
						if((nh1[0]==nh1[1] && nh1[0]==nh1[2]) || (nh1[1]==nh1[2] && nh1[1]==nh1[3]) || (nh1[2]==nh1[3] && nh1[2]==nh1[4])){
							p1= 3*15+nh1[2];
						}else{
							if(nh1[0]==nh1[1] && nh1[2]==nh1[3]){
								p1=2*15+nh1[3]+((1e-2)*nh1[1])+((1.e-4)*nh1[4]);
							}else{
								if(nh1[0]==nh1[1] && nh1[3]==nh1[4]){
									p1=2*15+nh1[3]+((1e-2)*nh1[1])+((1.e-4)*nh1[2]);
								}else{
									if(nh1[1]==nh1[2] && nh1[3]==nh1[4]){
										p1=2*15+nh1[3]+((1e-2)*nh1[1])+((1.e-4)*nh1[0]);
									}else{
										if(nh1[0]==nh1[1]){
											p1= 15+nh1[0]+((1e-2)*nh1[4])+((1.e-4)*nh1[3])+((1e-6)*nh1[2]);
										}else{
											if(nh1[1]==nh1[2]){
												p1= 15+nh1[1]+((1e-2)*nh1[4])+((1.e-4)*nh1[3])+((1e-6)*nh1[0]);
											}else{
												if(nh1[2]==nh1[3]){
													p1= 15+nh1[2]+((1e-2)*nh1[4])+((1.e-4)*nh1[1])+((1e-6)*nh1[0]);
												}else{
													if(nh1[3]==nh1[4]){
														p1= 15+nh1[3]+((1e-2)*nh1[2])+((1.e-4)*nh1[1])+((1e-6)*nh1[0]);
													}else{
														p1= nh1[4]+((1e-2)*nh1[3])+((1.e-4)*nh1[2])+((1e-6)*nh1[1])+((1e-8)*nh1[0]);
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
			}
		}
		/*printf("\n*%g*\n\n", p1);*/
		
		if(h[16]==h[19] && h[16]==h[22] && h[16]==h[25] && h[16]==h[28]){
			if(nh2[0]==nh2[1]-1 && nh2[0]==nh2[2]-2 && nh2[0]==nh2[3]-3 && nh2[0]==nh2[4]-4){
				p2=8*15+nh2[4];
			}else{
				p2=5*15+nh2[4];
			}	
		}else{
			if(nh2[0]==nh2[1]-1 && nh2[0]==nh2[2]-2 && nh2[0]==nh2[3]-3 && nh2[0]==nh2[4]-4){
				p2=4*15+nh2[4];
			}else{
				if((nh2[0]==nh2[1] && nh2[0]==nh2[2] && nh2[0]==nh2[3]) || (nh2[1]==nh2[2] && nh2[1]==nh2[3] && nh2[1]==nh2[4])){
					p2=7*15+nh2[2];
				}else{
					if((nh2[0]==nh2[1] && nh2[0]==nh2[2] && nh2[3]==nh2[4]) || (nh2[0]==nh2[1] && nh2[2]==nh2[3] && nh2[2]==nh2[4])){
						p2=6*15+nh2[2];
					}else{
						if((nh2[0]==nh2[1] && nh2[0]==nh2[2]) || (nh2[1]==nh2[2] && nh2[1]==nh2[3]) || (nh2[2]==nh2[3] && nh2[2]==nh2[4])){
							p2= 3*15+nh2[2];
						}else{
							if(nh2[0]==nh2[1] && nh2[2]==nh2[3]){
								p2=2*15+nh2[3]+((1e-2)*nh2[1])+((1.e-4)*nh2[4]);
							}else{
								if(nh2[0]==nh2[1] && nh2[3]==nh2[4]){
									p2=2*15+nh2[3]+((1e-2)*nh2[1])+((1.e-4)*nh2[2]);
								}else{
									if(nh2[1]==nh2[2] && nh2[3]==nh2[4]){
										p2=2*15+nh2[3]+((1e-2)*nh2[1])+((1.e-4)*nh2[0]);
									}else{
										if(nh2[0]==nh2[1]){
											p2= 15+nh2[0]+((1e-2)*nh2[4])+((1.e-4)*nh2[3])+((1e-6)*nh2[2]);
										}else{
											if(nh2[1]==nh2[2]){
												p2= 15+nh2[1]+((1e-2)*nh2[4])+((1.e-4)*nh2[3])+((1e-6)*nh2[0]);
											}else{
												if(nh2[2]==nh2[3]){
													p2= 15+nh2[2]+((1e-2)*nh2[4])+((1.e-4)*nh2[1])+((1e-6)*nh2[0]);
												}else{
													if(nh2[3]==nh2[4]){
														p2= 15+nh2[3]+((1e-2)*nh2[2])+((1.e-4)*nh2[1])+((1e-6)*nh2[0]);
													}else{
														p2= nh2[4]+((1e-2)*nh2[3])+((1.e-4)*nh2[2])+((1e-6)*nh2[1])+((1e-8)*nh2[0]);
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
			}
		}
		/*printf("\n*%g*\n\n", p2);*/
	
		if(p1>p2)
			w++;
		
	}
	
	fclose(pf);
	
	printf("\nw=%d\n", w);
	
	return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
