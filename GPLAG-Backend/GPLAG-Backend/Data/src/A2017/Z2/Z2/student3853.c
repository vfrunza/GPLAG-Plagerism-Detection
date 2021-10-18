#include <stdio.h>

int main() {
	int n, niz[100]={0}, i, niz1[1000]={0}, c;
	do {
		printf ("Unesite velicinu niza: ");
		scanf ("%d", &n);
		
 	} while (n<0 || n>100);
	

	printf ("Unesite clanove niza: ");
	for (i=0; i<n; i++) {
		scanf ("%d", &niz[i]);
		if (niz[i]<0) {
				printf ("Pogresan unos!");
				scanf ("%d", &niz[i]);
				i--;
		}
	    while (niz[i]!=0) {
			c=niz[i]%10;
			niz1[c]++;
			niz[i]/=10;
		}
	
		
	}
	
printf ("Finalni niz glasi:\n");
for (i=0; i<1000; i++)
{
	if(niz1[i]>0)
	printf("%d %d ", i, niz1[i]);
}
	return 0;
}
