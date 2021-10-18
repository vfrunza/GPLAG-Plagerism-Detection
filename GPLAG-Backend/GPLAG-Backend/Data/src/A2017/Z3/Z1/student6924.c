#include <stdio.h>
#define BROJ_EL 100

int dva_od_tri(int niz1[], int duzina1, int niz2[], int duzina2, int niz3[], int duzina3)
{
	int i, j, x, y=0, t=0;

	for(i=0; i<duzina1; i++) {
		x=0;
		t=0;

		for(j=i-1; j>=0; j--) {
			if(niz1[i]==niz1[j]) t=1;
		}

		if(t==0) {
			j=0;

			while(j<duzina2) {
				if(niz1[i]==niz2[j]) {
					x++;
					break;
				}
				j++;
			}

			j=0;
			while(j<duzina3) {
				if(niz1[i]==niz3[j]) {
					x++;
					break;
				}
				j++;
			}

			if(x==1) y++;
		}
	}

	for(i=0; i<duzina2; i++) {
		t=0;
		x=0;
		j=0;

		for(j=i-1; j>=0; j--) {
			if(niz2[i]==niz2[j]) t=1;
		}
		if(t==1) continue;
		j=0;

		while(j<duzina1) {
			if(niz2[i]==niz1[j]) {
				t=1;
				break;
			}
			j++;
		}

		if(t==0) {
			j=0;
			while(j<duzina3) {
				if(niz2[i]==niz3[j]) {
					t=1;
					break;
				}
				j++;
			}

			if(t==1) y++;
		}
	}

	return y;
}

int main()
{
	int niz1[BROJ_EL], niz2[BROJ_EL], niz3[BROJ_EL], duzina1=0, duzina2=0, duzina3=0, i;

	printf("Unesite niz1: ");
	for(i=0; i<BROJ_EL; i++) {
		scanf("%d", &niz1[i]);
		if(niz1[i]==-1) break;
		duzina1++;
	}

	printf("Unesite niz1: ");
	for(i=0; i<BROJ_EL; i++) {
		scanf("%d", &niz2[i]);
		if(niz2[i]==-1) break;
		duzina2++;
	}

	printf("Unesite niz1: ");
	for(i=0; i<BROJ_EL; i++) {
		scanf("%d", &niz3[i]);
		if(niz3[i]==-1) break;
		duzina3++;
	}

	printf("Broj clanova koji se vracaju u dva od tri niza je: %d", dva_od_tri(niz1,duzina1,niz2,duzina2,niz3,duzina3));

	return 0;

}
