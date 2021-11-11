#include <stdio.h>
#include <math.h>

void zaokruzi1( float niz[], int velicina) {
	int i=0;
	while (i<velicina) {
		niz[i] = round(niz[i]*10)/10;
		i++;
	}
}

int DaLiJeManji(float pomocni, int poredbeni) {
	int suma=0, broj;
	broj= pomocni*10;
	while (broj!=0) {
		suma+=broj%10;
		broj=broj/10;
	}
	if(suma>=broj) return 1;
	else return 0;
}

void preslozi(float niz[], int vel, int k) {
	int i, j, temp=0, min;
	zaokruzi1(niz, vel);
	for (i=0; i<vel; i++) {
        min=i;
        for (j=i+1; j<vel; j++) {
            if (DaLiJeManji(niz[j], k))
                min = j;
        temp = niz[i];
        niz[i] = niz[min];
        niz[min] = temp;
    }

	}	
}




int main() {
	int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	return 0;
}
