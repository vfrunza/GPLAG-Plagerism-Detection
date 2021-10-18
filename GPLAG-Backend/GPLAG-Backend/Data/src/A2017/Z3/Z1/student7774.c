#include <stdio.h>
#define max_el 100000
int postoji_u_nizu(int* niz, int duzina, int broj)
{
	int i;
	for(i=0; i<duzina; i++) {
		if(broj==niz[i]) return 1;
	}
	return 0;
}

int izbaci_iste(int *niz, int duzina)
{
	int i,j,k;
	for(i=0; i<duzina-1; i++) {
		for(j=i+1; j<duzina; j++)
			if(niz[i]==niz[j]) {
				for(k=j; k<duzina-1; k++)
					niz[k]=niz[k+1];
				duzina--;
				j--;
			}
	}
	return duzina;
}

int dva_od_tri(int* niz1, int duzina1, int* niz2, int duzina2, int* niz3, int duzina3)
{
	int i, br=0, broj, br_pom1=duzina1, br_pom2=duzina2, br_pom3=duzina3;
	int pomocni_niz1[max_el], pomocni_niz2[max_el], pomocni_niz3[max_el];

	/*Kopiranje elemenata u pomocne nizove*/
	for(i=0; i<br_pom1; i++)
		pomocni_niz1[i]=niz1[i];
	for(i=0; i<br_pom2; i++)
		pomocni_niz2[i]=niz2[i];
	for(i=0; i<br_pom3; i++)
		pomocni_niz3[i]=niz3[i];

	br_pom1=izbaci_iste(pomocni_niz1,br_pom1);
	br_pom2=izbaci_iste(pomocni_niz2,br_pom2);
	br_pom3=izbaci_iste(pomocni_niz3,br_pom3);

	for(i=0; i<br_pom1; i++) {
		broj=pomocni_niz1[i];
		if((postoji_u_nizu(pomocni_niz2,br_pom2,broj)==1) && (postoji_u_nizu(pomocni_niz3,br_pom3, broj)==0)) br++;
		if((postoji_u_nizu(pomocni_niz2,br_pom2,broj)==0) && (postoji_u_nizu(pomocni_niz3,br_pom3,broj)==1)) br++;
	}
	for(i=0; i<br_pom2; i++) {
		broj=pomocni_niz2[i];
		if((postoji_u_nizu(pomocni_niz1,br_pom1,broj)==0) &&(postoji_u_nizu(pomocni_niz3,br_pom3,broj)==1)) br++;
	}
	return br;
}
int main()
{
	int niz1[max_el], niz2[max_el], niz3[max_el];
	int br1=0,br2=0,br3=0,i, br_dva_od_tri=0;
	printf("Unesite prvi niz: ");
	for(i=0; i<max_el; i++) {
		scanf("%d", &niz1[i]);
		if(niz1[i]==-1) break;
		br1++;
	}
	printf("Unesite drugi niz: ");
	for(i=0; i<max_el; i++) {
		scanf("%d", &niz2[i]);
		if(niz2[i]==-1) break;
		br2++;
	}
	printf("Unesite treci niz: ");
	for(i=0; i<max_el; i++) {
		scanf("%d", &niz3[i]);
		if(niz3[i]==-1) break;
		br3++;
	}
	br_dva_od_tri=dva_od_tri(niz1,br1,niz2,br2,niz3,br3);
	printf("Broj ponavljanja elementa u dva od tri niza je %d.", br_dva_od_tri);
	return 0;
}
