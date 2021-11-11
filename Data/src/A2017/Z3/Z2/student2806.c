#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int vel){
	int i;
	for (i = 0; i < vel; i++) {
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10.;
	}
}

int suma_cifara (float a){
	int cifra=0, suma=0;
	int broj=fabs(a*10);
	while(broj!=0){
		cifra=broj%10;
		suma+=cifra;
		broj/=10;
	}
	return suma;
}

void preslozi (float niz[], int vel, int k){
	int i, j, br=0;
	float temp;
	zaokruzi1(niz, vel);
	for(i=0; i<vel; i++){
		if(suma_cifara(niz[i])<k){
			for(j=i; j<vel-1; j++){
				temp=niz[j];
				niz[j]=niz[j+1];
				niz[j+1]=temp;
			}
			i--;
		}
		br++;
		if (br==vel) break;
	}
}


int main() {
	/*float niz[]={13.1, 15.749999, 15.75, 9.222,78.1};
	int i;
	zaokruzi1(niz, 5);
	printf("Nakon zaokruzivanja niz glasi:\n");
	for (i = 0; i < 5; i++) {
		printf("%g ", niz[i]);
	}
	
	
	
	printf("\nSuma cifara: %d", suma_cifara(15.6));
    preslozi(niz, 5, 14);
    printf("\nNiz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);*/
        
    int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	return 0;
}
