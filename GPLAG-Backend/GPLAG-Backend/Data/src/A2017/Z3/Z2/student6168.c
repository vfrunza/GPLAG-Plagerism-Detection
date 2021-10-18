#include <stdio.h>
#include <math.h>
#define BREL 1000
void zaokruzi1(float niz[], int duzina)
{
	int i;
	float zaokruzen; 				/*Vrijednost koju dodjeljujemo clanu niza jer je u pitanju void funkcija pa sama ne vraca nista*/

	for(i=0; i<duzina; i++) {
		niz[i]=10*niz[i];
		zaokruzen = round(niz[i]);
		niz[i]=zaokruzen/10; 		/*Zaokruzujemo broj na jednu decimalu*/
	}
}

void preslozi(float niz[], int br, int k)
{
	zaokruzi1(niz, br);
	int i, j, cifrabroja, suma, temp;
	int kraj=br; /*Postoji mogucnost padanja u inf.loop pa osiguravamo da se to ne desi pravljenjem nove varijable 'kraj' jednake br
	(broj elemenata) i tu varijablu koristimo u petlji uz j */
	float temp2;

	for(i=0; i<br; i++) {
		temp=niz[i]*10;
		temp=(int)(temp);
		if (temp<0)
			temp=-1*temp; /*Nakon pravljenja cijelog broja od broja iz niza(tipa float) pretvaramo negativne brojeve niza u pozitivne radi
	dobijanja tacne sume cifara jer nas zanimaju samo cifre broja, a ne kompletan broj i pri tome ne modifikujemo niz jer koristimo 'temp'*/
		suma=0;
		while(temp!=0) {
			cifrabroja=temp%10;
			suma=suma+cifrabroja;
			temp=temp/10; /*Sabiranje svih cifara broja u jednu sumu*/
		}
		/*Petlja provjerava da li je suma cifara posmatranog broja manja od zadatog k. Ukoliko jeste, taj broj treba prebaciti na kraj, a sve
		ostale pomaketi za jedno mjesto lijevo. Na taj nacin osiguravamo da redoslijed brojeva ostane nepromijenjen, a koristenjem varijable
		temp2 memorisemo posmatrani broj i na kraju ga prebacujemo na zadnje mjesto. Brojevi sa sumom >k preskacemo jer trebaju ostati tu gdje
		jesu.*/
		if (suma<k) {
			temp2=niz[i];
			for(j=i; j<kraj-1; j++)
				niz[j]=niz[j+1];

			niz[kraj-1]=temp2;

	/*Ako je doslo do pomjeranja kad je uslov suma<k bio zadovoljen, vracamo 'i' za jedan jer mi zelimo da u sljedecem prolasku kroz petlju
	ponovo posmatramo clan s istim indeksom jer sada taj indeks zauzima drugi broj. br-- koristimo jer nema potrebe da ponovo posmatramo broj
	koji je vec jednom bio prebacen jer bismo tako konstantno kruzili kroz niz*/

			i--;
			br--;

		}
	}
}

int main() /*TEST*/
{
	float niz[BREL];
	int i, n, p;
	printf("Unesite p: ");
	scanf("%d", &p);
	printf("Unesite n: ");
	scanf("%d", &n);
	printf("Unesite niz: ");
	for(i=0; i<n; i++)
		scanf("%f", &niz[i]);
	preslozi(niz, n, p);
	for (i=0; i<n; i++)
		printf("%g ", niz[i]);
	return 0;
}
