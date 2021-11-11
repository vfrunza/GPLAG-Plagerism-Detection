#include <stdio.h>
#include <math.h>

/* cca. 5h okopavanja, 1 neprospavana noc i telefonski razgovor sa Bill Gatesom u trajanju od 3h 
su usli u proces izrade narednog zadatka.

 	Posveceno vlastitom papagaju,
 	
 	- S ljubavlju, Benjamin */

int main() {
	int niz[100], niz2[1000], brojaci[10], C[1000];
	int i, j=0, eksp, k, l, cifra, n, n2=0, a;
	
	for (i=0; i<10; i++)
	brojaci[i]=1;
	
	do { 
	    printf ("Unesite velicinu niza: ");
	    scanf ("%d", &n); }
    while (n<1 || n>100);
	
	printf ("Unesite clanove niza: ");
	for (i=0; i<n; i++) {
	scanf ("%d", &niz[i]);
	if (niz[i]<0) i--; }
	
	
	/* formiranje niza neprekidnih cifara */
	for (i=0; i<n; i++) {
		
	if (niz[i]==0) {  /* ako je broj = 0 */
		niz2[j]=0;
		j++; n2++; }
		
	else {
		a=niz[i];
		l=0;
	do {
		a/=10;
		l++;
		} while (a>0);
	l-=1;
	a=niz[i];
	do {
		eksp=pow(10,l);
		cifra=a/eksp;
		niz2[j]=cifra;
		j++; n2++;
		a-=cifra*eksp;
		l--; }
	while (l>=0);
		}
	}
	

	/* formiranje finalnog niza */
	j=0;
	l=0;
	
	for (i=0; i<n2; i++) {
		if (j+1>n2) break;
		C[l]=niz2[j];
		if (j+1!=n2) {
			while (niz2[j]==niz2[j+1]) {
			brojaci[niz2[i]]++;
			j++;
			if (j+1==n2) break;
		}
		}
		C[l+1]=brojaci[niz2[i]];
		for (k=0; k<10; k++)  /* resetovanje cifara brojaca */
		brojaci[k]=1;
		j++;
		l+=2;
	}

	printf ("Finalni niz glasi:\n");
	for (i=0; i<l; i++)
	if (i==l-1) printf ("%d", C[i]);
	else printf ("%d ", C[i]);
	
	
	return 0;
}