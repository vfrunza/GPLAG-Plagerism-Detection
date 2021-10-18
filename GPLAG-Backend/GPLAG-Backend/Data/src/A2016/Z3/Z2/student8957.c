#include <stdio.h>

int ZbirCifara (int broj){
	int cifra,zc=0;
	if (broj<0) broj*=-1;
	while (broj!=0){
		cifra=broj%10;
		zc+=cifra;
		broj/=10;
	}
	return zc;
}


void ubaci (int niz[], int vel){
	int i,j;
	for (i=1;i<vel;i++){
		if (i%2!=0){
			for (j=vel;j>i;j--)
				niz[j]=niz[j-1];
			vel++;
			niz[i]=ZbirCifara(niz[i-1]);
		}
	}
	niz[vel]=ZbirCifara(niz[vel-1]);
}

int FibonacijeviBrojevi (int broj){
	int prvi=1, drugi=1, treci;
	if (broj==1 || broj==2) return 1;
	while (prvi+drugi<=broj){
		if (prvi+drugi==broj) return 1;
		treci=prvi;
		prvi=drugi;
		drugi+=treci;
	}
	return 0;
}

int izbaci (int niz[], int vel){
	int i,j;
	for(i=0;i<vel;i++){
		if (FibonacijeviBrojevi(niz[i])){
			for(j=i;j<vel-1;j++)
				niz[j]=niz[j+1];
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	int niz[200],i,velicina;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++)
		scanf ("%d", &niz[i]);
	ubaci(niz,10);
	velicina=izbaci(niz,20);
	printf ("Modificirani niz glasi: ");
	for (i=0;i<velicina;i++){
		if(i==velicina-1) printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	}
	return 0;
}
