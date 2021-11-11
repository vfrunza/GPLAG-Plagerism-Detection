#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define brel 10
#define brel2 20
void preslozi(int *niz, int velicina)
{
	int i;
	int cifra;
	int broj;
	int broj2=0;
	for (i=velicina-1; i>=0; i--) {
		*(niz+2*i)=*(niz+i);
	}
	for (i=0; i<velicina*2; i++) {
		if(i%2==1) {
			broj=*(niz+i-1);
			while (broj!=0) {
				cifra=broj%10;
				broj2+=cifra;
				broj/=10;
			}
			*(niz+i)=abs(broj2);
			broj2=0;
		}
	}
}
int izbaci(int *niz,int velicina)
{
	int i;
	int j;
	int m;
	int prvi=0;
	int drugi=1;
	int slijedeci;
	for(i=0; i<velicina; i++) {
		prvi=0;
		drugi=1;
		for(j=1; j<10000; j++) {
			if(j==1) slijedeci=j;
			else {
				slijedeci=prvi+drugi;
				prvi=drugi;
				drugi=slijedeci;
			}
			if(*(niz+i)==slijedeci) {
				for(m=i; m<velicina-1; m++) {
					*(niz+m)=*(niz+m+1);
				}
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
int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	return 0;
}