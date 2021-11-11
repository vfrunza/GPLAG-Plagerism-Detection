#include <stdio.h>
#include <math.h>


void zaokruzi1(float *niz, int vel){
	int i=0,broj;
	for(i=0; i<vel; i++){
		broj = round(niz[i]*10);
		niz[i]= broj/10.;
	}
}

int sumaCif(float broj){
	int prvi,rez;
	broj=fabs(broj);
	prvi=(int)broj;
	rez=0;
	while(prvi!=0){
		rez+=prvi%10;
		prvi/=10;
	}
	rez+=(int)((broj-(int)(broj) + 0.05) * 10);
	return rez;
}

void naPocetak(float niz[], int k){
	float broj = niz[k];
	int j;
	for(j=k; j>0; j--)
		niz[j] = niz[j-1];
	niz[0]=broj;
}

void preslozi(float niz[], int vel, int k){
	int i=0,s=0;
	zaokruzi1(niz,vel);
	
	for(i=vel-1; i>=s; i--){
		if(sumaCif(niz[i])>=k){
			naPocetak(niz,i);
			s++;
			i++;
		}
	}
}
int main() {
	int i;
	float niz[] = { 3.2, -4.301, -123.1999, 1.1, 0.9 };
	preslozi(niz, 5, 8);
	printf("Niz glasi: ");
	for (i=0; i<5; i++)
	    printf("%g ", niz[i]);
	
	return 0;

}
