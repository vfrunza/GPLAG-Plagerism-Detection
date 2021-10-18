#include <stdio.h>

int main()
{
	int nizA[100], nizB[100], nizC[100]= {0}, nizFinalni[100], n1, i=0, j=0, k=0, l, brojac1=0, brojac2=0;
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &n1);
	} while (n1<=0 || n1>100);

	printf("Unesite clanove niza: ");
	for (i=0; i<n1; i++) {
		scanf("%d", &nizA[i]);
		if (nizA[i]<0) {
			printf("Greska!");
			i--;
		}
	}
	for(i=0; i<n1; i++) {
		nizB[i]=nizA[i];
	}
	for (i=0; i<n1; i++) {
		do {
			brojac1++;
			nizB[i]/=10;
		} while (nizB[i]>0);
		j=0;
		do {
			nizC[brojac1-j-1]=nizA[i]%10;
			nizA[i]/=10;
			j++;
		} while (nizA[i]>0);
	}
	for (k=0; k<brojac1; k++) {
		nizFinalni[l]=nizC[k];
		l++;
		brojac2=1;
		while (nizC[k]==nizC[k+1]) {
			brojac2++;
			k++;
			if (k==brojac1-1) break;
		}
		nizFinalni[l]=brojac2;
		l++;
	}
	printf("Finalni niz glasi:\n");
	for (i=0; i<l; i++) {
		if (i==0) printf("%d", nizFinalni[i]);
		else printf(" %d", nizFinalni[i]);
	}
	return 0;
}