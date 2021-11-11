#include <stdio.h>

int dva_od_tri (int niz1[], int n1, int niz2[], int n2, int niz3[], int n3)
{
	int broj12=0, broj23=0, broj13=0, broj=0, brojevi=0;
	int i=0,j=0,k=0;

	for (i=0; i<n1; i++) {
		for (j=i+1; j<n1; j++) {
			if (niz1[i]==niz1[j]) {
				niz1[i]=niz1[n1-1];
				j--;
				n1--;
			}
		}
	}

	for (i=0; i<n2; i++) {
		for (j=i+1; j<n2; j++) {
			if (niz2[i]==niz2[j]) {
				niz2[i]=niz2[n2-1];
				j--;
				n2--;
			}
		}
	}

	for (i=0; i<n3; i++) {
		for (j=i+1; j<n3; j++) {
			if (niz3[i]==niz3[j]) {
				niz3[i]=niz3[n3-1];
				j--;
				n3--;
			}
		}
	}

	for (i=0; i<n1; i++) {
		for (j=0; j<n2; j++) {
			if (niz1[i]==niz2[j]) {
				broj12++;
			}
		}
	}

	for (i=0; i<n2; i++) {
		for (j=0; j<n3; j++) {
			if (niz2[i]==niz3[j]) {
				broj23++;
			}
		}
	}

	for (i=0; i<n1; i++) {
		for (j=0; j<n3; j++) {
			if (niz1[i]==niz3[j]) {
				broj13++;
			}
		}
	}

	for (i=0; i<n1; i++) {
		for (j=0; j<n2; j++) {
			for (k=0; k<n3; k++) {
				if (niz1[i]==niz2[j] && niz1[i]==niz3[k]) {
					brojevi++;
				}
			}
		}
	}

	broj=(broj12+broj23+broj13)-(brojevi*3);

	return broj;
}

int main()
{
	int niz1[100], niz2[100], niz3[100];
	int n1, n2, n3, i;

	printf ("\nUnesite velicinu prvog niza: ");
	scanf ("%d", &n1);
	printf ("\nUnesite velicinu drugog niza: ");
	scanf ("%d", &n2);
	printf ("\nUnesite velicinu treceg niza: ");
	scanf ("%d", &n3);

	printf ("\nUnesite elemente prvog niza: ");
	for (i=0; i<n1; i++) {
		scanf ("%d", &niz1[i]);
	}

	printf ("\nUnesite elemente drugog niza: ");
	for (i=0; i<n2; i++) {
		scanf ("%d", &niz2[i]);
	}

	printf ("\nUnesite elemente treceg niza: ");
	for (i=0; i<n3; i++) {
		scanf ("%d", &niz3[i]);
	}

	printf ("\n%d", dva_od_tri(niz1,n1,niz2,n2,niz3,n3));
	return 0;
}
