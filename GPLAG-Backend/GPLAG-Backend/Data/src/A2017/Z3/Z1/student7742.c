#include <stdio.h>

int dva_od_tri(int *p1, int n1, int *p2, int n2, int *p3, int n3)
{
	int pom1[100], pom2[100], pom3[100];
	int i,j,k,l,brojac1=0,brojac2=0,brojac3=0,dodaj=1,logicko,brojfunkcije;
	for(i=0; i<n1; i++) {
		dodaj=1;
		for(l=0; l<brojac1; l++) {
			if(pom1[l]==*(p1+i)) dodaj=0;
		}
		if(dodaj) {
			pom1[brojac1]=*(p1+i);
			brojac1++;
		}
	}
	for(i=0; i<n2; i++) {
		dodaj=1;
		for(l=0; l<brojac2; l++) {
			if(pom2[l]==*(p2+i)) dodaj=0;
		}
		if(dodaj) {
			pom2[brojac2]=*(p2+i);
			brojac2++;
		}
	}
	for(i=0; i<n3; i++) {
		dodaj=1;
		for(l=0; l<brojac3; l++) {
			if(pom3[l]==*(p3+i)) dodaj=0;
		}
		if(dodaj) {
			pom3[brojac3]=*(p3+i);
			brojac3++;
		}
	}
	for(i=0; i<brojac1; i++) {
		for(j=0; j<brojac2; j++) {
			logicko=0;
			if(pom1[i]==pom2[j]) { /*prvi i drugi*/
				logicko=1;
				for(k=0; k<brojac3; k++) { /*nema u 3.*/
					if(pom3[k]==pom1[i] || pom3[k]==pom2[j]) {
						logicko=0;
						break;
					}
				}
			}
			if(logicko) brojfunkcije++;
		}
		for(k=0; k<brojac3; k++) {
			logicko=0;
			if(pom1[i]==pom3[k]) {
				logicko=1;
				for(j=0; j<brojac2; j++) {
					if(pom2[j]==pom1[i] || pom2[j]==pom3[k]) {
						logicko=0;
						break;
					}
				}
			}
			if(logicko) brojfunkcije++;
		}
	}
	for(j=0; j<brojac2; j++) {
		for(k=0; k<brojac3; k++) {
			logicko=0;
			if(pom2[j]==pom3[k]) {
				logicko=1;
				for(i=0; i<brojac1; i++) {
					if(pom3[k]==pom1[i] || pom1[i]==pom2[j]) {
						logicko=0;
						break;
					}
				}
			}
			if(logicko) brojfunkcije++;
		}
	}
	return brojfunkcije;
}
int main()
{
	int niz1[]= {1, 2, 3, 5};
	int niz2[]= {1, 2, 4, 6, 7};
	int niz3[]= {1, 3, 4, 8, 9, 10};
	int rez=dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
	printf("%d", rez);
	return 0;
}
