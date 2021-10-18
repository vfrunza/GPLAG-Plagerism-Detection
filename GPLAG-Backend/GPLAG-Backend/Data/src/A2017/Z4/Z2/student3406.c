#include <stdio.h>

void unesi (char niz[],int velicina)
{
	char znak=getchar();
	if (znak=='\n')
		znak=getchar();
	int i=0;
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine (char *niz, int *duzine,int n)
{
	int brojac=0,test=0,ukupan_broj=0,broj_tacnih=0,*prvi=duzine;
	if(n==0)
		return 0;

	while (*niz!='\0') {
		test=0;
		brojac=0;
		while ((*niz>='A' && *niz<='Z') || (*niz>='a' && *niz<='z')) {
			brojac++;
			test=1;
			niz++;
		}
		if(test) {
			ukupan_broj++;
			if (*duzine==brojac) {
				broj_tacnih++;
				duzine++;
			}
		}
		if (test==0)
			niz++;
	}
	if(n!=ukupan_broj)
		return 0;
	if (ukupan_broj==broj_tacnih)
		return 1;
	return 0;
}

int main()
{
	char niz[100];
	int i,brojevi[100],n;
	printf ("Unesi recenicu: ");
	unesi(niz,100);
	printf ("Unesi broj rijeci: ");
	scanf ("%d", &n);
	printf ("Unesi duzine rijeci: ");
	for (i=0; i<n; i++) {
		scanf ("%d", &brojevi[i]);
	}
	printf ("%d", provjeri_duzine (niz,brojevi,n));

	return 0;
}
