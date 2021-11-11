#include <stdio.h>
void ubaci(int niz[], int vel) {
	int i,j,suma=0,temp;
	for(i=0; i<2*vel; i+=2) {
		temp=niz[i];
		if(temp<0) {
			temp*=(-1);
		}
		while(temp>0) {
			suma+=temp%10;
			temp/=10;
		}
		for(j=2*(vel-1); j>i; j--)
		niz[j+1]=niz[j];
		niz[i+1]=suma;
		suma=0;
	}
}
int izbaci(int niz[], int vel) {
	int i,j,a,b,c;
	for(i=0; i<vel; i++) {
		a=1;
		b=2;
		c=a+b;
		while(c<niz[i]) {
			a=b;
			b=c;
			c=a+b;
		}
		if(niz[i]==1 || niz[i]==2 || niz[i]==c) {
			for(j=i; j<vel-1; j++)
			niz[j]=niz[j+1];
			vel--;
			i--;
		}
	}
	return vel;
}
int main() {
	int niz[20],i,duzina;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
	scanf("%d", &niz[i]);
	ubaci(niz,i);
	duzina=izbaci(niz, i*2);
	printf("Modificirani niz glasi: ");
	for(i=0; i<duzina; i++) {
		if(i==duzina-1) printf("%d.", niz[i]);
		else printf("%d, ", niz[i]);
	}
	return 0;
}
