#include <stdio.h>
#include <math.h>
#define BR_EL 100

/*Funkcija zaokruzuje svaki clan na jednu decimalu*/
void zaokruzi1(float niz[], int vel)
{
	int i;
	for(i = 0; i < vel; i++)
		niz[i] = round(niz[i]*10)/10;
}

/*Funkcija racuna sumu cifara broja*/
int suma_cifara_broja(float broj)
{
	int temp, suma = 0;
	/*potrebno je da je broj poyitivan, da bi se suma pravilno izracunala*/
	if (broj<0)
		temp=-broj;
	else
		temp=broj;
	do {
		suma = suma + temp % 10;
		temp =  temp / 10;
	} while(temp > 0);
	return suma;
}

void preslozi(float niz[], int vel, int k)
{
	int i, j,l;
	float temp;
	zaokruzi1(niz,vel);

	/*Za svaki clan niz-a*/
	for(i = 0; i < vel; i++) {
		/*racunamo sumu funkcijom i poredimo je sa zadatim brojem k*/
		if(suma_cifara_broja(niz[i]*10) < k) {
			/*u slucaju da je suma manja, pomjeramo odgovarajuci
			broj na kraj niza, tako odrzavamo redosljed brojeva*/
			for(l = i+1; l < vel; l++) {
				if(suma_cifara_broja(niz[l] * 10) >= k) {
					for(j = l; j > i; j--) {
						temp = niz[j-1];
						niz[j-1] = niz[j];
						niz[j] = temp;

					}

					break;
				}

			}
		}
	}
}
int main()
{
	float niz[BR_EL];
	int i, vel, k;
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	printf("Unesite clanove niza: ");
	for(i = 0; i < vel; i++)
		scanf("%f",&niz[i]);
	zaokruzi1(niz,vel);
	printf("Zaokruzeni niz je: ");
	for(i = 0; i < vel; i++)
		printf("%g ",niz[i]);
	printf("\nUnesite broj k: ");
	scanf("%d",&k);
	preslozi(niz, vel, k);
	printf("Nakon poziva funkcije preslozi niz glasi: ");
	for(i = 0; i < vel; i++)
		printf("%g ",niz[i]);
	return 0;
}
