#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* function to calculate sum of digits of a number */
int _sumaCifara(float num) {
	int sum = 0;
	long temp = (long) (num*10);
	while(temp != 0) {
		sum += (int) (temp%10);
		temp = temp/10;
	}
	return abs(sum);
}

/* function to round numbers to 1 decimal place */
void zaokruzi1(float* arr, int length) {
	float* niz = arr;
	while(niz < arr + length) {
		*niz = round(*niz*10)/10;
		niz++;
	}
}

/* function to swap numbers */
void preslozi(float* arr, int length, int k) {
	float* niz = arr;
	float temp;
	int i, j, l, _exist = 1;
	
	/* call round function */
	zaokruzi1(arr, length);
	
	/* poslozi niz */
	for(i = 0; i < length-1; i++) {
		if(_sumaCifara(*(niz+i)) < k) {
			/* find first element that has greater digit sum */
			for(j = i+1; j < length; j++) {
				
				if(_sumaCifara(*(niz+j)) >= k) { 
					/* interpolate array (shift right 1 place and add element before */
					temp = *(niz+j);
					for(l = j; l > i; l--) 
						*(niz+l)=*(niz+l-1);
					*(niz+i) = temp;
					break;
				}
				else if(j == length - 1) 
					_exist = 0;
			
			}
			/* save time, don't repeat if there's no element with digit sum >= k */
			if(!_exist)
				break;
		}
	}
}

int main() {
	return 0;
}