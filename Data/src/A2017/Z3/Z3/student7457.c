#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int izbaci_cifre(int brojevi[], int sizeb, int cifre[], int sizec)
{
	int i, k, j;
	int c=0, ostatak=0, temp=0, fakt=0, br=0;

	for (i=0; i<sizec; i++) {
		/* uslov za poredjenje nizove i izbacivanje cifara (brojevi ne mogu biti manji od nula i veci od devet i ne smiju se ponavljat) */
		if (cifre[i]<0 || cifre[i]>9)
			return 0;
		for (j=i+1; j<sizec; j++) {
			if (cifre[i]==cifre[j])
				return 0;
		}
	}

	for(i=0; i<sizeb; i++) {
		c=abs(brojevi[i]);
		br=brojevi[i];
		fakt=0;
		/* broj se rastavlja na cifre i poredi sa elementom niza cifara */
		while(c!=0) {
			ostatak=c%10;
			for(j=0; j<sizec; j++) {
				if(cifre[j]==ostatak) {
					if (fakt==0)
						br /= 10;
					else
						/* izbacivanje cifre iz broja koja se nalazi u nizu cifara */
						br = (br/((int)pow(10,fakt+1))) * ((int)pow(10,fakt)) + br%((int)pow(10,fakt));
					fakt--;
					break;
				}
			}
			c/=10;
			fakt++;
		}
		brojevi[i]=br;
	}
	return 1;
}

int main()
{
	int i, j, size1, size2, nizbrojeva[100], nizcifara[100], ret;
	scanf("%d", &size1);
	scanf("%d", &size2);
	for(i=0; i<size1; i++) {
		scanf("%d", &nizbrojeva[i]);
	}
	for(j=0; j<size2; j++) {
		scanf("%d", &nizcifara[j]);
	}
	ret=izbaci_cifre(nizbrojeva, size1, nizcifara, size2);
	printf("%d %d\n", nizbrojeva[0], nizbrojeva[1]);
	return 0;
}