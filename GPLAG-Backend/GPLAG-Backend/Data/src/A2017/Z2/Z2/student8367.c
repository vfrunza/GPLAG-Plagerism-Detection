#include <stdio.h>

int main() {
	int n,niz[100], niz_cifara[1000]={0}, broj=0, brojac=0, i=0, j=0, brpojava=0,a=0, temp=0, broj_nula=0;
	printf("Unesite velicinu niza: ");
	scanf ("%d", &n);
	printf("Unesite clanove niza: ");
	for (i=0;i<n;i++) {
		scanf ("%d", &niz[i]);
	}
	for (i=0; i<n;i++) {
		temp=niz[i];
		if (niz[i]==0) { niz_cifara[brojac]=0; brojac++; }
		broj_nula=0;
		while (temp!=0) {
			broj*=10; broj+=temp%10;
			if (broj==0) broj_nula++;
			temp/=10;
		}
	
	while (broj!=0) {
		niz_cifara[brojac]=broj%10;
		brojac++;
		broj/=10;
		while (broj_nula>0) {
			niz_cifara[brojac]=0; broj_nula--; brojac++;
		}
	}} 
	for (i=0; i<brojac; i++) {
		brpojava=1;
		a=i+1;
		while (niz_cifara[i]==niz_cifara[a]) {
			brpojava++; a++;
			if (a>=brojac) break;
		}  if(brpojava==1) {
			for(j=brojac; j>i; j--) {
				if(j!=0) niz_cifara[j]=niz_cifara[j-1];
			} niz_cifara[j+1]=brpojava; brojac++; i++;}
		else {
			for(j=i+2; j<brojac-1; j++) {
				niz_cifara[j]=niz_cifara[j+brpojava-2];
			} brojac-=brpojava-2;
			niz_cifara[i+1]=brpojava; i++;
		}
	}
	printf ("Finalni niz glasi: \n");
	for(i=0; i<brojac; i+=2) {
	printf("%d %d ", niz_cifara[i], niz_cifara[i+1]);
	}
	return 0;
}
