/*
 * ProjectEuler 59
 */
 
#include <stdio.h>
#include <stdlib.h>

int* XOR_decryptor(int*, int, int*, int);

int main(void){
	int *encr, *decr, key[3]={97,97,97}, n;
	int i, aux, ctrl, count;
	unsigned long long int sum;
	char coma;
	FILE *pf;
	
	/*read the data*/
	pf = fopen("p059_cipher.txt", "r");
		if(pf==NULL){printf("Err: NoFile\n"); return -1;}
	
	encr = (int*)malloc(sizeof(int));
		if(encr==NULL){printf("Err: NoMem\n"); return -2;}
	
	n = 1;
	fscanf(pf, "%d", &encr[0]);
	while(fscanf(pf, "%c%d", &coma, &aux)!=EOF){
		n++;
		encr = (int*)realloc(encr, n*sizeof(int));
			if(encr==NULL){printf("Err: NoMem\n"); return -2;}
		
		encr[n-1] = aux;
	}
	
	fclose(pf);
	
	while(1){
		decr = XOR_decryptor(encr, n, key, 3);
			if(decr==NULL){printf("Err: XOR fun\n"); return -3;}
		
		/*Check if all the values are "english characters"*/
		ctrl = 1;
		for(i=0; i<n; i++){
			if(decr[i]>=32 && decr[i]<=122){
				ctrl = 1;
			}else{
				ctrl = 0;
				break;
			}
		}
		
		if(ctrl){
			count++;
			if(count==5)
				break;
		}
		
		/*Compute the next key*/
		if(key[2]<122){
			key[2]++;
		}else{
			key[2] = 97;
			
			if(key[1]<122){
				key[1]++;
			}else{
				key[1] = 97;
				
				if(key[0]<122){
					key[0]++;
				}else{
					printf("End reached\n");
					break;
				}
			}
		}
		
		free(decr);
	}
	
	sum = 0;
	for(i=0; i<n; i++){
		printf("%c", (char)decr[i]);
		sum += decr[i];
	}
	printf("\n\n%llu \n\n", sum);
	
	free(encr);
	free(decr);
	
	return 0;
}

int* XOR_decryptor(int *text, int text_len, int *key, int key_len){
	int *dec;
	int i, k;
	
	dec = (int*)malloc(text_len*sizeof(int));
		if(dec==NULL){printf("Err: NoMem\n"); return NULL;}
	
	k = 0;
	for(i=0; i<text_len; i++){
		dec[i] = text[i]^key[k];
		k = (k+1)%key_len;
	}
	
	return dec;
}
