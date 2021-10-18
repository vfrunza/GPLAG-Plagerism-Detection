#include <stdio.h>
#include <math.h>
void zaokruzi1 (float* niz, int a)
{
	int i;
	for(i=0; i<a; i++){
		niz[i]=round(niz[i]*10)/10;
	}
}
void preslozi (float niz[1000], int n, int k)
{
	int suma=0, brojac=0, brojac2=0, i, a;
	float niz2[1000];
	zaokruzi1(niz, n);
	for(i=0; i<n; i++){
		a=niz[i]*10;
		while(a>0){
			suma=suma+a%10;
			a=a/10;
		}
		if(suma<k)
			brojac++;
		if(suma>k){
			niz2[i-brojac]=niz[i];
			brojac2++;
		}
	}
	for(i=0; i<n; i++){
		if(fabs(niz[i]-niz2[i])<0.01)
			niz2[i+brojac2]=niz[i];
	}
	for(i=0; i<n; i++){
		niz[i]=niz2[i];
	}
	
}

int main(){
	

	return 0;
}
