#include <stdio.h>
#include <math.h>

int izbaci_broj(int broj, int x)
{ int pomocna = 0;
	int novi = 0;
	int k=1, c;
	if (broj<0)pomocna = 1;
	broj = fabs(broj);
	while(broj!=0){
		c = broj%10;
		if(c!=x){
			novi = novi + c*k;
			k *=10;
		}
		broj /=10;
	}
	if(pomocna == 1)novi = novi *(-1);
	return novi;
}

int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2){
	int j, i;
	for(j=0; j<vel2; j++){
		for(i=j+1; i<vel2; i++){
			if(niz2[j]==niz2[i])
			return 0;
		}
		if(niz2[j]<0 || niz2[j] >9)
		return 0;
	}
	
	for( i=0; i<vel1; i++){
		for(j=0; j<vel2; j++){
			niz1[i]=izbaci_broj(niz1[i], niz2[j]);
		}
	}
	return 1;
	
}


int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
