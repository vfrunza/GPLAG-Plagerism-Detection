#include <stdio.h>
#include <math.h>
int izbaci_cifre(int niz1[], int velicina1, int niz2[], int velicina2) {
	int i, j, dekadniKoeficijent, cifraBroja, temp1, temp2;
	// Provjeravanje da li je niz cifara legitiman za funkciju (vraca 0 ako nije) //
	for (i=0; i<velicina2; i++) {
		if (niz2[i]<0 || niz2[i]>9)
			return 0;
		for (j=i+1; j<velicina2; j++) {
			if (niz2[i]==niz2[j])
				return 0;
		}
	}
	
	for (i=0; i<velicina1; i++) {
		for (j=0; j<velicina2; j++) {
			dekadniKoeficijent=1;
			temp2=0; // Temporalna varijabla na koju se dodaju cifre koje trebaju da ostanu u nizu //
			if (niz1[i]>=0)
				temp1=niz1[i]; // Temporalna varijabla koja preuzima prvobitni broj i koja se koristi u petlji za provjeranje //
			else
				temp1=-1*niz1[i]; // U slucaju da je broj negativan, ovaj if/else pretvara broj u pozitivan da bi se mogle uzimati cifre, na kraju pretvaranja se opet vrati u negativan broj //
			while (temp1!=0) {
				// Uzima cifru po cifru iz broja, u slucaju da se cifra broja ne nalazi u nizu cifara, vraca cifru nazad u broj, uzimajuci u obzir na kojem mjestu ce se cifra nalaziti u novom broju (zbog toga se koristi dekadni koeficijent) //
				cifraBroja=temp1%10; 
				temp1/=10; 
				if (cifraBroja!=niz2[j]) {
					temp2+=cifraBroja*dekadniKoeficijent;
					dekadniKoeficijent*=10;
				}
			}
			// Temporalna varijabla koja je preuzimala novu vrijednost broja vracamo u niz, s tim da ako je broj bio negativan na pocetku, osiguravamo da ostane negativan //
			if (niz1[i]>=0)
				niz1[i]=temp2;
			else
				niz1[i]=-1*temp2;
		}
	}
	return 1;
}
int main() {
	int niz1[20], velicina1, niz2[20], velicina2, i, rezultat;
	printf("Unesite velicinu prvog niza: ");
	scanf("%d", &velicina1);
	printf("Unesite prvi niz: ");
	for (i=0; i<velicina1; i++)
		scanf("%d", &niz1[i]);
	printf("Unesite velicinu drugog niza: ");
	scanf("%d", &velicina2);
	printf("Unesite drugi niz: ");
	for (i=0; i<velicina2; i++)
		scanf("%d", &niz2[i]);

	rezultat=izbaci_cifre(niz1, velicina1, niz2, velicina2);
	printf("Novi niz izgleda: \n");
	for (i=0; i<velicina1; i++)
		printf("%d ", niz1[i]);
	printf("\nFunkcija vraca broj %d", rezultat);
	return 0;
}
