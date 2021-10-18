#include <stdio.h>


/* vraca zaokruzen broj na jednu decimalu*/
float zaokruzi_broj1(float broj)
{
	int znak=1;
	int pomocni = broj*100;
	if(broj<0) {
		znak=-1;
		pomocni*=-1;
	}
	pomocni+=5;
	pomocni/=10;
	return  znak*pomocni/10.;
}


void zaokruzi1(float niz[],int velicina)
{
	int i;
	for ( i = 0; i < velicina; i++) {
		niz[i] = zaokruzi_broj1(niz[i]);
	}
}

int suma_cifara_zaokruzenog1(float broj)
{
	int pomocni = broj*10;
	if(pomocni<0)pomocni*=-1;
	int suma_cifara=0;

	while(pomocni!=0) {
		suma_cifara+=pomocni%10;
		pomocni/=10;
	}
	return suma_cifara;
}

void preslozi(float niz[], int velicina, int k)
{
	int i,j;
	float temp;
	int broj_vecih_od_k=0;
	
	zaokruzi1(niz,velicina);
	for ( i = 0; i < velicina; i++) {
		if(suma_cifara_zaokruzenog1(niz[i]) >= k) {
			for (j = i; j>broj_vecih_od_k; j--) {
				temp = niz[j];
				niz[j]=niz[j-1];
				niz[j-1]=temp;
			}
			broj_vecih_od_k++;
		}
	}
}
int main()
{

	int i;
	float niz[]= {13.1,15.749999,15.75,9.222,78.1};

	preslozi(niz,5,14);
	
	for ( i = 0; i < 5; i++) {
		printf("%g ",niz[i]);
	}
	return 0;
}
