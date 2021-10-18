#include <stdio.h>
#include <math.h>

int izbaci_cifre (int niz1[], int velicina1, int niz2 [], int velicina2)
{
	int i, j;
	int pomocni_niz_1[100], pomocni_niz_2[100];
	int pamti_minus = 0, brojac_stepena = 0, cifra = 0, suma = 0;

	for(i = 0; i < velicina2; i++) {
		if (niz2[i] < 0 || niz2[i] > 9)
			return 0;
	}

	for (i = 0; i < velicina2; i++) {
		for (j = i + 1; j < velicina2; j++)
			if(niz2[i] == niz2[j])
				return 0;
	}

	for (i = 0; i < velicina1; i++) {
		pomocni_niz_1[i] = niz1[i];
	}

	for (i = 0; i < velicina2; i++) {
		pomocni_niz_2[i] = niz2[i];
	}

	for (i = 0; i < velicina1; i++) {
		for (j = 0; j < velicina2; j++) {

			if (pomocni_niz_1[i] < 0) {
				pamti_minus = 1;
				pomocni_niz_1[i] = -pomocni_niz_1[i];
			}

			while(pomocni_niz_1[i] != 0) {
				cifra = pomocni_niz_1[i] % 10;
				if (cifra == pomocni_niz_2[j]) {
					cifra = 0;
					pomocni_niz_1[i] /= 10;
					continue;
				}
				suma += cifra * pow (10, brojac_stepena);
				pomocni_niz_1[i] /= 10;
				brojac_stepena++;

			}

			if(pamti_minus == 1) suma = -suma;

			brojac_stepena = 0;
			pamti_minus = 0;
			pomocni_niz_1[i] = suma;
			suma = 0;
		}

		niz1[i] = pomocni_niz_1[i];

	}
	return 1;

}

int main()
{

	printf("Zadatak ne trazi koristenje main funkcije.");
	return 0;
}
