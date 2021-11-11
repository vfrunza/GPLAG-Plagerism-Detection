#include <stdio.h>

int dva_od_tri(int niz1[], int velicina1, int niz2[], int velicina2, int niz3[], int velicina3)
{
	int i,j,k,pom1,pom2,pom3;
	int br,br1=0, br2=0, pomocni;

	for (i=0; i<velicina1; i++) {
		pom1=niz1[i];
		pomocni = 0;

		for (j=0; j<i; j++) {
			if (pom1==niz1[j])
				pomocni=1;
		}

		if (pomocni==1)
			continue;

		for (j=0; j<velicina2; j++) {
			pom2=niz2[j];
			if(pom1==pom2)  {
				pomocni=1;
				break;
			}
		}

		for (k=0; k<velicina3; k++) {
			pom3=niz3[k];
			if(pom1==pom3) {

				if(pomocni==1) {
					pomocni=0;
				} else {
					pomocni=1;
				}
				break;
			}
		}

		if(pomocni==1) {
			br1++;
		}
	}

	for(j=0; j<velicina2; j++) {
		pom2=niz2[j];
		pomocni = 0;

		for (i=0; i<j; i++) {
			if (pom2==niz2[i])
				pomocni=1;
		}

		if (pomocni==1)
			continue;

		for (k=0; k<velicina3; k++) {
			pom3=niz3[k];
			if(pom2==pom3)  {
				pomocni=1;
				break;
			}
		}

		for (i=0; i<velicina1; i++) {
			pom1=niz1[i];
			if(pom1==pom2) {

				pomocni = 0;
				break;
			}
		}

		if(pomocni==1) {
			br2++;
		}

	}

	br=br1+br2;
	return br;
}

int main()
{
	int i,a,b,c;
	int niz1[1000],niz2[1000],niz3[1000];

	printf("Dimenzije nizova: ");
	scanf("%d %d %d",&a,&b,&c);

	for(i=0; i<a; i++)scanf("%d",&niz1[i]);

	for(i=0; i<b; i++)scanf("%d",&niz2[i]);

	for(i=0; i<c; i++)scanf("%d",&niz3[i]);

	printf ("%d",dva_od_tri(niz1, a, niz2, b, niz3, c));

	return 0;
}
