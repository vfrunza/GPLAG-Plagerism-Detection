#include <stdio.h>

int dva_od_tri(int* niz1,int vel_niz1, int* niz2, int vel_niz2, int* niz3,int vel_niz3)
{

	int i,j,k,l,m,n;
	int broj_pon2=0,broj_pon3=0,broj;
	int brojac1=0,brojac2=0,brojac3=0;


	for(i=0; i<vel_niz1; i++) {
		brojac1=0;
		for(j=i; j<vel_niz1; j++) {
			if(niz1[i]==niz1[j])
				brojac1++;								/*Brojimo pri svakom prolazu za svaki clan koliko puta se ponavlja u odnosu na sljedbenike u nizu...*/
		}


		for(k=0; k<vel_niz2; k++) {
			brojac2=0;
			for(l=k; l<vel_niz2; l++) {
				if(niz2[k]==niz2[l])
					brojac2++;
			}

			for(m=0; m<vel_niz3; m++) {
				brojac3=0;
				for(n=m; n<vel_niz3; n++) {
					if(niz3[m]==niz3[n])
						brojac3++;
				}

				if(brojac1==1 && brojac2==1 && brojac3==1) {			/*...Poredimo one clanove koji se ne ponavljaju...*/
					if(niz1[i]==niz2[k] && niz2[k]==niz3[m]) {
						broj_pon3++;									/*...Broj clanova u sva tri niza...*/
					}
				}

			}
		}
	}

	for(i=0; i<vel_niz1; i++) {
		brojac1=0;
		for(j=i; j<vel_niz1; j++) {
			if(niz1[i]==niz1[j])
				brojac1++;
		}


		for(k=0; k<vel_niz2; k++) {
			brojac2=0;
			for(l=k; l<vel_niz2; l++) {
				if(niz2[k]==niz2[l])
					brojac2++;
			}

			if(brojac1==1 && brojac2==1) {
				if(niz1[i]==niz2[k]) {
					broj_pon2++;										/*...Broj clanova u prvom i drugom nizu...*/
				}
			}

		}
	}

	for(k=0; k<vel_niz2; k++) {
		brojac2=0;
		for(l=k; l<vel_niz2; l++) {
			if(niz2[k]==niz2[l])
				brojac2++;
		}

		for(m=0; m<vel_niz3; m++) {
			brojac3=0;
			for(n=m; n<vel_niz3; n++) {
				if(niz3[m]==niz3[n])
					brojac3++;
			}

			if(brojac2==1 && brojac3==1) {
				if(niz2[k]==niz3[m]) {
					broj_pon2++;									/*...Broj clanova u drugom i trecem nizu...*/
				}
			}
		}
	}



	for(m=0; m<vel_niz3; m++) {
		brojac3=0;
		for(n=m; n<vel_niz3; n++) {
			if(niz3[m]==niz3[n])
				brojac3++;
		}

		for(i=0; i<vel_niz1; i++) {
			brojac1=0;
			for(j=i; j<vel_niz1; j++) {
				if(niz1[i]==niz1[j])
					brojac1++;
			}

			if(brojac3==1 && brojac1==1) {
				if(niz3[m]==niz1[i]) {
					broj_pon2++;					/*...Broj clanova u trecem i prvom nizu...*/
				}
			}
		}
	}

	broj=broj_pon2-3*broj_pon3;


	return broj;


}

int main()
{


	return 0;
}
