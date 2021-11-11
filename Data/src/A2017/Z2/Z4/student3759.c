#include <stdio.h>
#define max 100
int main() {
/*	printf("Zadaća 2, Zadatak 4"); */
int m, n, iste, i, j;
int matricaA[max][max], matricaB[max][max], matricaC[max][max], brojaciA[1000]={0}, brojaciB[1000]={0}, brojaciC[1000]={0};
do {
	printf ("Unesite brojeve M i N: ");
	scanf ("%d %d", &m, &n);
}
while (m<0 || m>100 || n<0 || n>100);

printf ("Unesite clanove matrice A: ");
for (i=0; i<m; i++)
	for(j=0; j<n; j++) 
		scanf ("%d", &matricaA[i][j]);
printf ("Unesite clanove matrice B: ");
for (i=0; i<m; i++)
	for(j=0; j<n; j++) 
		scanf ("%d", &matricaB[i][j]);
printf ("Unesite clanove matrice C: ");
for (i=0; i<m; i++)
	for(j=0; j<n; j++) 
		scanf ("%d", &matricaC[i][j]);
		
for (i=0; i<m; i++)
	for (j=0; j<n; j++) {
		brojaciA[matricaA[i][j]]++;
		brojaciB[matricaB[i][j]]++;
		brojaciC[matricaC[i][j]]++;
	}
	
iste=1;
for (i=0; i<1000; i++)
	if (brojaciA[i]!=brojaciB[i] || brojaciA[i]!=brojaciC[i]) {
		iste=0;
		break;
	}

if (iste) 
	printf ("DA");
else
	printf ("NE");
	return 0;
}
