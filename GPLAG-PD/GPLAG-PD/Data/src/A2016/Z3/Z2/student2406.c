#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ubaci(int niz[], int velicina)
{
	int i,sum,j,razdvajanje;
	int tmp=velicina*2-2;
	for(i=velicina-1; i>=1; i--) {
		niz[tmp]=niz[i];
		tmp=tmp-2;
	}
	for(j=1; j<2*velicina; j+=2) {
		sum=0;
		razdvajanje=abs(niz[j-1]);
		while(razdvajanje>0) {
			sum=sum+razdvajanje%10;
			razdvajanje=razdvajanje/10;
		}
		niz[j]=sum;
	}
}

int izbaci(int niz[], int velicina)
{
	int f1, f2, sljed, i, k, j;
	for(i=0; i<velicina;++i) {
		f1=1;
		f2=1;
		for(j=0; j<abs(niz[i]);++j) {
			sljed=f1+f2;
			f1=f2;
			f2=sljed;
			if((niz[i])==f1||(niz[i])==f2||(niz[i])==sljed) {
				for(k=i;k<velicina-1;++k)
				niz[k]=niz[k+1];
				velicina--;
				i--;
				break;
			}	
		}
	}
	return velicina;
}

int main()
{
	int niz[20], finalni, i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10;++i)
		scanf("%d", &niz[i]);
	ubaci(niz,i);
	finalni=izbaci(niz,i*2);
	printf("Modificirani niz glasi: ");
	for(i=0; i<finalni;++i) {
		if(i==finalni-1)
			printf("%d. ", niz[i]);
		else if(i<finalni-1)
			printf("%d, ", niz[i]);
	}
	return 0;
}
