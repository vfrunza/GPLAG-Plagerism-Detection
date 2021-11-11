#include <stdio.h>
#include <math.h>

void zaokruzi1 (float* p, int n)    /*Funkcija u kojoj koristimo algoritam za zaokuzivanje svake vrijednosti niza na jednu decimalu. Ova funkcija ne treba da vraca nikakvu vrijednost, zbog toga je tipa void.*/
{
	int i;

	for(i=0; i<n; i++) {
		*(p+i)=round( (*(p+i))*10)/10;
	}
}

int suma_cifara (float x)   /*za svaku vrijendost koju dobije funkcija, njen cilj je da sabere sve cifre tog broja i vrati njihovu sumu u funkciju "preslozi".*/
{
	int suma=0, temp;

	x = fabs(x*10);
	temp=round(x);          /*U varijablu "temp" smjestamo zakoruzeno vrijednost varijalbe "x", prethodno pomozene sa 10. To radimo da ne bi izgubili ni jednu cifru broja kojeg 'nosi' "x".*/

	while(temp!=0) {
		suma+=temp%10;      /*Varijabli "suma" dodajemo ostatak pri djeljenju "temp" i 10. Da bi preslji na sljedecu cifru u sljedecem prolazu kroz petlju, "temp" moramo podijeliti sa 10.*/
		temp /= 10;
	}

	return suma;
}

void preslozi(float* p, int n, int k)
{
	int i, j;
	float temp;

	zaokruzi1(p, n);

	for(j=0; j<n; j++) {
		for(i=0; i<n-1-j; i++) {
			if(suma_cifara(p[i])<k && suma_cifara(p[i+1])>=k) {            
				/*Poredimo sume cifara brojeva koji predstavljaju clanove niza, prethodno zaokruzenihn na jednu decimalu sa cijelim brojem "k" kojeg je korisnik prethodno unio u "main" funkciji.*/
				/*Ukoliko je suma cifara clana niza manja od "k" i ukoliko je suma cifara sljedeceg clana veca ili jednaka broju "k", tada te dvije vrijednosi mijenjaju mjesta.*/
				temp=p[i];
				p[i]=p[i+1];
				p[i+1]=temp;
			}
		}
	}
}

int main()
{
	int i, n, k;
	float niz[100];

	printf("Unesite velicnu niza: ");
	scanf("%d", &n);

	printf("\nUnesite clanove niza: ");

	for(i=0; i<n; i++)
		scanf("%f", &niz[i]);

	zaokruzi1(niz, n);
	printf("Nakon zaokruzivanja niz treba glasiti: ");

	for(i=0; i<n; i++)
		printf("%g ", niz[i]);



	printf("Unesite broj k: ");
	scanf("%d", &k);

	preslozi(niz, n, k);

	printf("Nakon poziva funkcije preslozi pri cemu je k=%d niz treba glasiti: ", k);
	for(i=0; i<n; i++)
		printf("%f ", niz[i]);

	return 0;
}
