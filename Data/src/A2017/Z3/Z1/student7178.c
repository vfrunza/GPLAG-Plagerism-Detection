#include <stdio.h>

int dva_od_tri(int *niz1, int n1, int *niz2, int n2, int *niz3, int n3)
{
	int i, j, k, brojac=0, pomocni_brojac=0, p;
	/*Prvo provjerimo za clanove prvog niza*/
	i=0;
	while(i<n1) {
		pomocni_brojac=0;
		p=niz1[i];
		/*Provjera  ima li  jednak clan niza1 clanu niz1[i] ispred njega*/
		for(j=i-1; j>=0; j--) {
			if(niz1[i]==niz1[j])
				break;
		}

		if(j==-1) {
			/*Ovom petljom cemo uporediti iti clan niza1 sa clanovima niza2, prvi put kada naidje na isti pomocni brojac se uveca, a petlja se prekida.*/
			for(j=0; j<n2; j++) {
				if (niz2[j]==p) {
					pomocni_brojac++;
					break;
				}
			}
			/*Ovom petljom cemo uporediti iti clan niza1 sa clanovima niza3, prvi put kada naidje na isti, pomocni brojac se uveca, a petlja se prekida.*/
			for(j=0; j<n3; j++) {
				if(niz3[j]==p) {
					pomocni_brojac++;
					break;
				}
			}

			/*Ako se brojac samo jednom uvecao, to znaci da se iti clan niza1 nalazi samo u jednom od preostala dva niza te ce se brojac uvecati.*/
			if(pomocni_brojac==1)
				brojac++;
		}
		i++;
	}

	/*Analogno za drugi niz*/
	i=0;
	while(i<n2) {
		pomocni_brojac=0;
		p=niz2[i];

		for(j=i-1; j>=0; j--) {
			if(niz2[i]==niz2[j])
				break;
		}

		if(j==-1) {
			/*Pomocni brojac se povecava samo ako se iti clan niza2 nalazi u nizu3, ali ne i nizu1*/
			for(j=0; j<n3; j++) {
				if(niz3[j]==p) {
					for(k=0; k<n1; k++) {
						if(*(niz1+k)==p)
							break;
					}
					if(k==n1) pomocni_brojac++;
					break;
				}
			}

			if(pomocni_brojac==1)
				brojac++;
		}
		i++;
	}


	return brojac;
}

int main()
{

	return 0;
}