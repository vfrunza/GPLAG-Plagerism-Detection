#include <stdio.h>

int main()
{
	int vel,i,j,bcfr,pomocni,niz1[100],niz2[1000],pomocniniz[1000];
	int index=0;
	int br=0;

	do {
		printf("Unesite velicinu niza: ");
		scanf("%d",&vel);
	} while (vel<1 || vel>100);

	printf ("Unesite clanove niza: ");
	for(i=0; i<vel; i++) {
		scanf ("%d",&niz1[i]);
		if(niz1[i]<0) {
			i--;
		}
	}

	for(i=0; i<vel; i++) {
		pomocni=niz1[i];
		bcfr=0;
		if(niz1[i]==0)
			bcfr=1;

		else {
			while(pomocni!=0) {
				pomocni/=10;
				bcfr++;
			}

		}

		index+=bcfr;
		for(j=0; j<bcfr; j++) {
			pomocniniz[index-1]=niz1[i]%10;
			niz1[i]/=10;
			index--;
		}
		index=index+bcfr;
	}
	bcfr=index;
	index=0;
	for(i=0; i<bcfr; i++) {
		niz2[index]=pomocniniz[i];
		index++;

		br=1;
		while(i<bcfr-1 &&pomocniniz[i]==pomocniniz[i+1]) {
			br++;
			i++;
		}
		niz2[index]=br;
		index++;
	}

	printf("Finalni niz glasi: \n");
	for(i=0; i<index; i++) {
		printf("%d ",niz2[i]);
	}
	return 0;
}
