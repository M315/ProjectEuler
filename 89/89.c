/*
 * project euler 89
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int roman_to_num(char*, int*);
int num_to_roman(int, char*);

int main(void){
	int num, n_char_old, n_char_new, cum_dif = 0;
	char roman[30];
	FILE *pf;

	pf = fopen("roman.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}

	while(fscanf(pf, "%s\n", roman) > 0){
		n_char_old = roman_to_num(roman, &num);

		n_char_new = num_to_roman(num, roman);

		cum_dif += n_char_old - n_char_new;
	}

	printf("%d\n", cum_dif);

	fclose(pf);

	return 0;
}

int roman_to_num(char *r, int *n){
	int i, ctrl, len = 0;

	while((int)r[len] != 0)
		len++;
	
	*n = 0;
	for(i = 0; i < len - 1; i++){
		
		/*Subtractions*/
		ctrl = 1;
		if(r[i] == 'I' && r[i+1] == 'V'){
			*n += 4;
			i++;
			ctrl = 0;
		}

		if(r[i] == 'I' && r[i+1] == 'X'){
			*n += 9;
			i++;
			ctrl = 0;
		}
		
		if(r[i] == 'X' && r[i+1] == 'L'){
			*n += 40;
			i++;
			ctrl = 0;
		}
		
		if(r[i] == 'X' && r[i+1] == 'C'){
			*n += 90;
			i++;
			ctrl = 0;
		}
		
		if(r[i] == 'C' && r[i+1] == 'D'){
			*n += 400;
			i++;
			ctrl = 0;
		}
			
		if(r[i] == 'C' && r[i+1] == 'M'){
			*n += 900;
			i++;
			ctrl = 0;
		}

		/*If there was no subtraction the sum the value*/
		if(ctrl)
			switch(r[i]){
				case 'I':
					*n += 1;
					break;
				case 'V':
					*n += 5;
					break;
				case 'X':
					*n += 10;
					break;
				case 'L':
					*n += 50;
					break;
				case 'C':
					*n += 100;
					break;
				case 'D':
					*n += 500;
					break;
				case 'M':
					*n += 1000;
					break;
			}
	}

	/*If the last letter was not a subtraction add it now*/
	if(i < len)
		switch(r[i]){
				case 'I':
					*n += 1;
					break;
				case 'V':
					*n += 5;
					break;
				case 'X':
					*n += 10;
					break;
				case 'L':
					*n += 50;
					break;
				case 'C':
					*n += 100;
					break;
				case 'D':
					*n += 500;
					break;
				case 'M':
					*n += 1000;
					break;
			}
	
	return len;
}

int num_to_roman(int n, char *r){
	int i, c = 0, d, len = 0;
	char new[30];

	while(n != 0 && c < 4){
		d = n % 10;

		switch(d){
			case 1:
				if(c == 0){
					new[len] = 'I';
					len += 1;
				}

				if(c == 1){
					new[len] = 'X';
					len += 1;
				}

				if(c == 2){
					new[len] = 'C';
					len += 1;
				}

				if(c == 3){
					new[len] = 'M';
					len += 1;
				}
				
				break;

			case 2:
				if(c == 0){
					for(i = len; i < len + 2; i++)
						new[i] = 'I';
					len += 2;
				}
				
				if(c == 1){
					for(i = len; i < len + 2; i++)
						new[i] = 'X';
					len += 2;
				}
				
				if(c == 2){
					for(i = len; i < len + 2; i++)
						new[i] = 'C';
					len += 2;
				}
				
				if(c == 3){
					for(i = len; i < len + 2; i++)
						new[i] = 'M';
					len += 2;
				}
				
				break;

			case 3:
				if(c == 0){
					for(i = len; i < len + 3; i++)
						new[i] = 'I';
					len += 3;
				}
				
				if(c == 1){
					for(i = len; i < len + 3; i++)
						new[i] = 'X';
					len += 3;
				}
				
				if(c == 2){
					for(i = len; i < len + 3; i++)
						new[i] = 'C';
					len += 3;
				}
				
				if(c == 3){
					for(i = len; i < len + 3; i++)
						new[i] = 'M';
					len += 3;
				}
				
				break;

			case 4:
				if(c == 0){
					new[len] = 'V';
					new[len + 1] = 'I';
					len += 2;
				}

				if(c == 1){
					new[len] = 'L';
					new[len + 1] = 'X';
					len += 2;
				}

				if(c == 2){
					new[len] = 'D';
					new[len + 1] = 'C';
					len += 2;
				}

				if(c == 3){
					for(i = len; i < len + 4; i++)
						new[i] = 'M';
					len += 4;
				}
				
				break;

			case 5:
				if(c == 0){
					new[len] = 'V';
					len += 1;
				}

				if(c == 1){
					new[len] = 'L';
					len += 1;
				}

				if(c == 2){
					new[len] = 'D';
					len += 1;
				}

				if(c == 3){
					for(i = len; i < len + 5; i++)
						new[i] = 'M';
					len += 5;
				}
				
				break;

			case 6:
				if(c == 0){
					new[len] = 'I';
					new[len + 1] = 'V';
					len += 2;
				}

				if(c == 1){
					new[len] = 'X';
					new[len + 1] = 'L';
					len += 2;
				}

				if(c == 2){
					new[len] = 'C';
					new[len + 1] = 'D';
					len += 2;
				}

				if(c == 3){
					for(i = len; i < len + 6; i++)
						new[i] = 'M';
					len += 6;
				}
				
				break;

			case 7:
				if(c == 0){
					new[len] = 'I';
					new[len + 1] = 'I';
					new[len + 2] = 'V';
					len += 3;
				}

				if(c == 1){
					new[len] = 'X';
					new[len + 1] = 'X';
					new[len + 2] = 'L';
					len += 3;
				}

				if(c == 2){
					new[len] = 'C';
					new[len + 1] = 'C';
					new[len + 2] = 'D';
					len += 3;
				}

				if(c == 3){
					for(i = len; i < len + 7; i++)
						new[i] = 'M';
					len += 7;
				}
				
				break;

			case 8:
				if(c == 0){
					new[len] = 'I';
					new[len + 1] = 'I';
					new[len + 2] = 'I';
					new[len + 3] = 'V';
					len += 4;
				}

				if(c == 1){
					new[len] = 'X';
					new[len + 1] = 'X';
					new[len + 2] = 'X';
					new[len + 3] = 'L';
					len += 4;
				}

				if(c == 2){
					new[len] = 'C';
					new[len + 1] = 'C';
					new[len + 2] = 'C';
					new[len + 3] = 'D';
					len += 4;
				}

				if(c == 3){
					for(i = len; i < len + 8; i++)
						new[i] = 'M';
					len += 8;
				}
				
				break;

			case 9:
				if(c == 0){
					new[len] = 'X';
					new[len + 1] = 'I';
					len += 2;
				}

				if(c == 1){
					new[len] = 'C';
					new[len + 1] = 'X';
					len += 2;
				}

				if(c == 2){
					new[len] = 'M';
					new[len + 1] = 'C';
					len += 2;
				}

				if(c == 3){
					for(i = len; i < len + 9; i++)
						new[i] = 'M';
					len += 9;
				}
				
				break;
		}
		
		n /= 10;
		c++;
	}

	/*write the new roman nuber in r*/
	for(i = len - 1; i >= 0; i--)
		r[len - 1 - i] = new[i];
	r[len] = '\0';

	return len;
}
