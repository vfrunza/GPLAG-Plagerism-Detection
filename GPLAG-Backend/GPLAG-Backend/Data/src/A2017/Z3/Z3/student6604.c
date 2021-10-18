#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//rastavi na cifre 

int brisi(int broj, int cifra)
{
	int niz_cifara[11]={0}, brojac=0, neg=0, i=0, j;
	
	if(broj<0) neg=1;
	else neg=0;
	
	broj=abs(broj);
	
	while (broj!=0) {
		niz_cifara[i]=broj%10;
		broj=broj/10;
		i++;
	}
	brojac=i;
	
	for(i=0; i<brojac; i++){
		if(niz_cifara[i]==cifra){
			for (j = i; j < brojac-1; j++) {
				niz_cifara[j]=niz_cifara[j+1];
			}
			brojac--;
			i--;
		}
	}
	broj=0;
	for (i = brojac-1; i >=0; i--) {
		broj=10*broj+niz_cifara[i];
	}
	if (neg) return (broj*(-1));
	
	return broj;
}


int izbaci_cifre(int *niz, int velicina1, int *niz_cifara, int velicina2)
{
	int i, j, temp;
	
	for (i = 0; i < velicina2; i++) {
		if (niz_cifara[i]<0 || niz_cifara[i]>9)return 0;
	}
	
	for (i = 0; i < velicina2; i++) {
		for (j = i+1; j < velicina2; j++) {
			if (niz_cifara[j]==niz_cifara[i])return 0;
		}
	}
	
	for (i = 0; i < velicina1; i++) {
		temp=niz[i];
		for (j = 0; j < velicina2; j++) {
			while (temp!=0) {
				if ((abs(temp)%10)==niz_cifara[j]) {
					niz[i]=brisi(niz[i], niz_cifara[j]);
				}
				temp/=10;
			}
				temp=niz[i];
		}
		
	}
	return 1;
}
	
int main()
{
	return 0;
}
