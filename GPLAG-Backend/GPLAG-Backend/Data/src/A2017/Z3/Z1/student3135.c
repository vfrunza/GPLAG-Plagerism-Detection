#include <stdio.h>

int dva_od_tri(int* niz1,int vel1,int* niz2, int vel2, int* niz3, int vel3)
{
	int i,j,k,brojac=0,vel11,vel12,vel13,isti=0,brojac_=0;
	int niz_1[1000]= {0},niz_2[1000]= {0},niz_3[1000]= {0};

	/*U pomocne nizove postavljamo vrijednosti datih nizova ne ponavljajuci iste vrijednosti.
	Postupak ponavljamo za sve tri data niza */
	/*Prvi pomocni niz*/
	k=0;
	for(i=0; i<vel1; i++) {
		brojac=0;
		for(j=0; j<i; j++) {
			if(niz1[j]==niz1[i]) {
				brojac++;
				break;
			}
		}
		if(brojac==0) {
			niz_1[k]=niz1[i];
			k++;
		}
	}
	vel11=k;
	k=0;

	/*Drugi pomocni niz*/
	for(i=0; i<vel2; i++) {
		brojac=0;
		for(j=0; j<i; j++) {
			if(niz2[j]==niz2[i]) {
				brojac++;
				break;
			}
		}
		if(brojac==0) {
			niz_2[k]=niz2[i];
			k++;
		}
	}
	vel12=k;
	k=0;

	/*Treci pomocni niz*/
	for(i=0; i<vel3; i++) {
		brojac=0;
		for(j=0; j<i; j++) {
			if(niz3[j]==niz3[i]) {
				brojac++;
				break;
			}
		}
		if(brojac==0) {
			niz_3[k]=niz3[i];
			k++;

		}
	}
	vel13=k;

	for(i=0; i<vel11; i++) {
		for(j=0; j<vel12; j++) {
			/*Poredimo istu vrijednost u prvom i drugom nizu da li je prisutna u trecem, ako nije brojac uvecamo za 1*/
			isti=0;
			if(niz_1[i]==niz_2[j]) {
				for(k=0; k<vel13; k++) {
					if((niz_1[i]==niz_3[k]) ||(niz_2[j]==niz_3[k])) {
						isti=1;
						break;
					}
				}
				if(isti==0)
					brojac_++;

			}
		}
	}
	for(i=0; i<vel11; i++) {
		for(j=0; j<vel13; j++) {
			isti=0;
			/*Sada poredimo istu vrijednost u prvom i trecem nizu i ako nije prisutna u drugom uvecamo za 1 brojac*/
			if(niz_1[i]==niz_3[j]) {
				for(k=0; k<vel12; k++) {
					if((niz_1[i]==niz_2[k])||(niz_3[j]==niz_2[k])) {
						isti=1;
						break;
					}
				}
				if(isti==0)
					brojac_++;
			}
		}
	}
	for(i=0; i<vel12; i++) {
		for(j=0; j<vel13; j++) {
			isti=0;
			/*Ponavljamo postupak za posljednji moguci slucaj gdje ispitujemo da li je ona vrijednost
			koja je jednaka u drugom i trecem nizu prisutna u prvom nizu , ako nije brojac uvecamo za 1*/
			if(niz_2[i]==niz_3[j]) {
				for(k=0; k<vel11; k++) {
					if(niz_1[k]==niz_2[i]||niz_3[j]==niz_1[k]) {
						isti=1;
						break;
					}
				}
				if(isti==0)
					brojac_++;
			}
		}
	}

	return brojac_;
}
int main()
{
	int niz1[10]= {1,1,3,5},niz2[10]= {11,1,3},niz3[10]= {5,6,4};
	printf("%d",dva_od_tri(niz1,4,niz2,3,niz3,3));
	return 0;
}