#include <stdio.h>
#define br_elemenata 100

int dva_od_tri(int prvi_niz[], int drugi_niz[], int treci_niz[])
{

}

int main()
{
	int prvi_niz[br_elemenata],drugi_niz[br_elemenata],treci_niz[br_elemenata];
	int n=0, broj1=1, broj2=1, broj3=1;

	while(broj1 != -1) {
		scanf("%d",&broj1);
		if(broj1 != -1) {
			prvi_niz[n]=broj1;
			n++;
		}
	}
	n = 0;

	while(broj2 != -1) {
		scanf("%d", &broj2);
		if (broj2 != -1) {
	drugi_niz[n] = broj2;
			n++;
		}
	}
	n = 0;

	while (broj3 !=-1) {
		scanf("%d",&broj3);
		if (broj3 != -1) {
			treci_niz[n] = broj3;
			n++;
		}
	}

	

	printf ("%d", broj);
	return 0;
}