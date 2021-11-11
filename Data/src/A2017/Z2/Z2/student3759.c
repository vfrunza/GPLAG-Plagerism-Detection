#include <stdio.h>

int main() {
/*	printf("Zadaća 2, Zadatak 2"); */
int niz[100];
int noviniz[1000];
int i;
int n, cifra, temp, j=0, k, brojac=1;
do {
printf ("Unesite velicinu niza: ");
scanf ("%d", &n);
}
while (n<0 || n>100); 

printf ("Unesite clanove niza: ");
for (i=0; i<n; i++) {
	scanf ("%d", &niz[i]);
	if (niz[i]<0)
		i--;
}

for (i=0; i<n/2; i++) {
	temp=niz[i];
	niz[i]=niz[n-1-i];
	niz[n-1-i]=temp;
}
/*for(i=0; i<n; i++)
	printf ("%d", niz[i]); */

for (i=0; i<n; i++) {
	do {
		cifra=niz[i]%10;
		noviniz[j]=cifra;
		niz[i]=niz[i]/10;
		j++;
	}
	while (niz[i]!=0);
}
/*for(i=0; i<j; i++)
	printf ("%d ", noviniz[i]); */

for (i=0; i<j/2; i++) {
	temp=noviniz[i];
	noviniz[i]=noviniz[j-1-i];
	noviniz[j-1-i]=temp;
}
/*for(i=0; i<j; i++)
	printf ("%d", noviniz[i]); */
printf ("Finalni niz glasi:\n");
for (i=0; i<j; i++) {
	for (k=i; k<j-1; k++) {
		if (noviniz[i]!=noviniz[k+1]) {
			printf ("%d %d ", noviniz[i], brojac);
			break;
		}
		if (noviniz[i]==noviniz[k+1]) {
			brojac++;
			i++;
			if (k==j-2)
				printf ("%d %d ", noviniz[i], brojac);
			
			
		}
	}
	brojac=1;
	if (i==j-1 && noviniz[i]!=noviniz[i-1] ) {
		printf ("%d %d ", noviniz[i], brojac);
	}
} 


	return 0;
}
