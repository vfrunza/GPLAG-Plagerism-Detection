#include <stdio.h>
#include <stdlib.h>
void ubaci(int niz[],int velicina)
{
	int velicina2=2*velicina;
	int sumacifara=0;
	int i,j,cifra,t=1;
	int niz2[20];
	int clanniza;
	for(j=0; j<velicina2; j++) {
		if(j%2==0) {
			niz2[j]=niz[j/2];
		} else {
			clanniza=abs(niz[j-t]);
			while(clanniza!=0) {
				cifra=clanniza%10;
				sumacifara=sumacifara+cifra;
				clanniza=clanniza/10;
			}
			niz2[j]=sumacifara;
			sumacifara=0;
			t=t+1;
		}
	}
	for(i=0; i<velicina2; i++) {
		niz[i]=niz2[i];
	}
}
int izbaci(int niz[],int velicina)
{
	int o=0,j,k;
	int prvi=1,drugi=1;
	int niz3[1000];
	for(j=0; j<velicina; j++) {
		do {
			niz3[o]=prvi+drugi;
			prvi=drugi;
			drugi=niz3[o];
			if(niz[j]==niz3[o] || niz[j]==1) {
				for(k=j; k<velicina-1; k++) {
					niz[k]=niz[k+1];
				}
				velicina--;
				j--;
				break;
			}
			o++;
		} while(niz[j]>niz3[o-1]);
		prvi=1;
		drugi=1;
		o=0;
	}
	return velicina;
}
int main()
{
	int i,u;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	int velicinanakraju=izbaci(niz,20);
	if(velicinanakraju==0) {
		printf("Prazan niz");
		return 0;
	}
	printf("Modificirani niz glasi: ");
	for(u=0; u<velicinanakraju; u++) {
		if(u>=0 && u<velicinanakraju-1) {
			printf("%d, ",niz[u]);
		} else {
			printf("%d.",niz[u]);
		}
	}
	return 0;
}
