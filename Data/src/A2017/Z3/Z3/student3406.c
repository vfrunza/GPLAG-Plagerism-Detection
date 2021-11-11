#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *brojevi,int duzina1,int cifre[],int duzina2)
{
	int obrnut_niz_cifara[20],niz_cifara[20],zavrsni_niz[20],z=0,k,i,j,s,r,suma=0,znak=0;
	if (duzina2==0 || duzina1==0)
		return 0;
	for (i=0; i<duzina2; i++) {
		if (cifre[i]<0 || cifre[i]>9)
			return 0;
		for (j=i+1; j<duzina2; j++) {
			if (cifre[j]==cifre[i])
				return 0;
		}
	}

	for (i=0; i<duzina1; i++) {
		if (brojevi[i]<0) {
			brojevi[i]=-brojevi[i];
			znak=1;
		}
		j=0;
		while (brojevi[i]>0) {
			obrnut_niz_cifara[j]=brojevi[i]%10;
			brojevi[i]=brojevi[i]/10;
			j++;
		}
		k=0;
		for (j=j-1; j>=0; j--) {
			niz_cifara[k]=obrnut_niz_cifara[j];
			k++;
		}
		for (s=0; s<k; s++) {
			for (j=0; j<duzina2; j++) {
				if (niz_cifara[s]==cifre[j]) {
					for (r=s; r<k-1; r++)
						niz_cifara[r]=niz_cifara[r+1];
					k--;
					s--;
					break;
				}
			}
		}
		r=k-1;
		for (j=0; j<k; j++) {
			suma+=niz_cifara[j]*pow(10,r);
			r--;
		}
		if (znak)
			zavrsni_niz[z]=-suma;
		else
			zavrsni_niz[z]=suma;
		z++;
		znak=0;
		suma=0;
	}
	for (i=0; i<z; i++)
		(*brojevi++)=zavrsni_niz[i];
	return 1;
}

int main()
{
	int brojevi[100],cifre[100],duzina1,duzina2,i;
	printf ("Unesi broj elemenata prvog niza: ");
	scanf ("%d", &duzina1);
	printf ("Unesi elemente prvog niza: ");
	for (i=0; i<duzina1; i++) {
		scanf ("%d", &brojevi[i]);
	}
	printf ("Unesi broj elemenata drugog niza: ");
	scanf ("%d", &duzina2);
	printf ("Unesi elemente drugog niza: ");
	for (i=0; i<duzina2; i++) {
		scanf ("%d", &cifre[i]);
	}
	printf ("%d\n",izbaci_cifre(brojevi,duzina1,cifre,duzina2));
	return 0;
}