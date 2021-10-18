#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int vel){
	int i;
	for(i = 0; i < vel; i++){
		niz[i] = round(niz[i] * 10) / 10;	
	}
}

int SumaCifara(float r){
	int cijeli, suma = 0;
	/*Suma cifara*/
	r = fabs(r);
	cijeli = r*10;
	
	while(cijeli > 0){
		suma += cijeli%10;
		cijeli /= 10;
	}
	
	return suma;
}

void preslozi(float *niz, int vel, int k){
	zaokruzi1(niz, vel);
	
	int suma;
	int i = 0, j, c;
	double temp;
	
	/*Kroz niz*/
	for(c = 0; c < vel; c++){
		
		suma = SumaCifara(niz[i]);
		
		if(suma < k){
			temp = niz[i];
			
			for(j = i; j < vel-1; j++){
				niz[j] = niz[j+1];
			}
			
			niz[vel-1] = temp;
			i--;
		}

		i++;
	}
}

int main() {
	printf("%d", SumaCifara(-123.2));
	
	return 0;
}
