#include <stdio.h>
#include <stdlib.h>
int cifre(int a, int b)
{
	int broj=0,c=0,i=1,predznak=1;
	if(a<0) predznak=-1;
	while(a) {
		c=abs(a%10);
		if(c!=b) {
			broj=broj+c*i;
			i*=10;
		}
		a/=10;
	}

	return predznak*broj;
}

int provjera(int niz2[], int vel2)
{
	int br=0,i,j;
	for(i=0; i<vel2; i++) {
		br=0;
		for(j=0; j<vel2; j++) {
			if(niz2[j]>9 || niz2[j]<0) return 0;
			if(niz2[i]==niz2[j]) br++;
		}
		if(br>1) return 0;
	}
	return 1;
}

int izbaci_cifre(int niz1[],int vel1,int niz2[],int vel2)
{
	int i,j;
	if(!provjera(niz2,vel2)) return 0;

	for(i=0; i<vel1; i++) {
		for(j=0; j<vel2; j++) {
			niz1[i]=cifre(niz1[i],niz2[j]);
		}
	}

	return 1;
}

int main()
{

	return 0;
}
