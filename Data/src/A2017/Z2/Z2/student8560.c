#include <stdio.h>
int main()
{
	int niz[100],novi[1000],i,vel,velnova=0,broj,cifra,brponavljanja=1,c,j=0,konacni[1000],kraj=0;
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++) {
		scanf("%d",&niz[i]);
	}
	for(i=vel-1; i>=0; i--) { /* idem sa kraja niza i brojim koliko se puta ta cifra uzastopno ponavlja */
		broj=niz[i];
		cifra=broj%10;
		broj/=10;
		if(broj==0) {
			novi[j]=1; /* ukoliko je broj jednocifren */
			velnova++;
			j++;
			novi[j]=cifra;
			velnova++;
			j++;
		} else { /* nije jednocifren, rastavljam ga na cifre */
			while(broj!=0) {
				c=broj%10;
				while(cifra==c && broj!=0) { /* brojim ponavljanje istih cifara */
					brponavljanja++;
					broj/=10;
					if(broj!=0) c=broj%10;
				}
				if(broj==0) kraj=1; /* ukoliko dobijem da je broj 0, dosla sam do kraja broja */
				novi[j]=brponavljanja;
				velnova++;
				j++;
				novi[j]=cifra;
				velnova++;
				j++;
				brponavljanja=1;
				cifra=c;
				broj/=10;
			}
			if(kraj==0) { /* ako kraj nije 1, ostala je prva cifra broja */
				novi[j]=brponavljanja;
				j++;
				velnova++;
				novi[j]=cifra;
				j++;
				velnova++;
			} else kraj=0;
		}
	}
	for(i=0; i<velnova; i++) { /* posto sam krenula sa kraja unesenog niza, moram "obrnuti" novi niz */
		konacni[i]=novi[velnova-1-i];
	}

	printf("Finalni niz glasi:\n");
	for(i=0; i<(velnova-2); i+=2) { 
		if(konacni[i]==konacni[i+2]) { /* ukoliko su svaka druga dva elementa jednaka, ista cifra se uzastopno pojavljuje u dva broja */
			konacni[i+1]=konacni[i+1]+konacni[i+3]; /* sabiram pojavljivanja iste cifre */
			for(j=(i+2); j<(velnova-1); j++) konacni[j]=konacni[j+1]; /* zatim brisem drugu istu cifru i broj njenih ponavljanja */
			velnova--;
			for(j=(i+2); j<(velnova-1); j++) konacni[j]=konacni[j+1];
			velnova--;
			i-=2;
		}
	}
	for(i=0; i<velnova; i++) {
		printf("%d ",konacni[i]);
	}
	return 0;
}