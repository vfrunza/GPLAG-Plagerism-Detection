#include <stdio.h>
#include <math.h>

float* zaokruzi1(float *pok, int v){
	int i,temp,cifra;
	float *trn;
	trn = pok;
	for(i = 0; i < v; i++){
		temp = (int)(fabs(*trn)*100);
		if(temp%10>=5) temp+=10;
		temp /= 10;
		cifra = temp%10;
		temp /= 10;
		if(*trn < 0){
			*trn = -1*(temp/1.0 + 0.1*cifra);
		}
		else{
			*trn = (temp/1.0 + 0.1*cifra);
		}
		trn++;
	}
	return pok;
}	

int suma(float m){
	float x=0;
	int suma = 0;
	int k;
	m = fabs(m);
	m = m * 10;
	k = (int) m;
	
	while(k != 0){
		x = k%10;
		suma += x;
		k = k / 10;
	}
	return suma;
}

void preslozi(float* pok, int v, int k){
	float temp;
	int i,j;
	float *poc;
	float *trn;
	pok = zaokruzi1(pok,v);
	for(i = 0; i < v + 1; i++){
		poc = pok;
		trn = poc + 1;
		for(j = 0; j < v - 1; j++){
			if(suma(*poc) < k){
				temp = *poc;
				*poc = *trn;
				*trn = temp;
			}
			poc++;
			trn++;
		}
	}
}

int main() {

	int i;
    float niz[] = { 3.2, -4.301, -123.1999, 1.1, 0.9 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++) printf("%g ", niz[i]);
	return 0;
}
