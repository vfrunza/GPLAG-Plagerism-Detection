#include <stdio.h>

int dva_od_tri(int niz1, int n1, int niz2, int n2, int niz3, int n3)
{
	int brojaci[101]= {1}, i, j, k;
	for(i=0; i<n1; i++) {

		for(j=0; j<n2; i++) {

			for(k=0; k<n3; i++){

				if(niz1[i]==niz2[j] || niz1[i]==niz3[k]) brojaci[niz1[i]]++;
				else if(niz2[j]==niz3[k]) brojaci[niz2[j]]++;
			}
		}
	}
}

int main()
{
	int niz1[100], niz2[100], niz3[100], n1, n2, n3, i, rez;

	for(i=0; i<100; i++) {
		scanf("%d ", &niz1[i]);
		if(niz1[i]==0) break;
	}
	n1=i;
	for(i=0; i<100; i++) {
		scanf("%d ", &niz2[i]);
		if(niz2[i]==0) break;
	}
	n2=i;
	for(i=0; i<100; i++) {
		scanf("%d ", &niz3[i]);
		if(niz3[i]==0) break;
	}
	n3=i;

	rez=dva_od_tri(int niz1, int n1, int niz2, int n2, int niz3, int n3);
	printf("%d", rez);
	return 0;
}
