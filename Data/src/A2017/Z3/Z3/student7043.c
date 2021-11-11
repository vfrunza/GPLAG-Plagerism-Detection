#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *niz_1,int vel_1,int *niz_2,int vel_2){
	int i=0;
	int j=0;
	int k=0;
	int brojac=0;
	int negativan=0;
	int broj;
	int niz_cifara_broja_iz_niza_1[10]={0};
	for (i=0;i<vel_2;i++)
	if (niz_2[i]<0 || niz_2[i]>9) return 0;
	for (i=0;i<vel_2;i++)
		for (j=i+1;j<vel_2;j++)
		if (niz_2[i]==niz_2[j]) return 0;
	while(k<vel_1){
	negativan =0;
	i=0;
	brojac=0;
	j=0;
	broj=niz_1[k];
	if (broj<0) {
		negativan=1;
		broj=fabs(broj);
	}
	while(broj!=0){
		niz_cifara_broja_iz_niza_1[i]=broj%10;
		broj=broj/10;
		i++;
		brojac++;
	}
	for (i=0;i<vel_2;i++){
		for (j=0;j<brojac;j++){
			if (niz_2[i]<0 || niz_2[i]>9) return 0;
			if (niz_2[i]==niz_cifara_broja_iz_niza_1[j]) niz_cifara_broja_iz_niza_1[j]=15;
		}
	}
	i=0;
	j=0;
	while(i<brojac){
		while(niz_cifara_broja_iz_niza_1[i]!=15 && i<brojac) {
			i++;
			j=i;
			}
			if (niz_cifara_broja_iz_niza_1[i]==15) {
				if (niz_cifara_broja_iz_niza_1[j+1]!=15)
				j++;
				while( i<brojac) {
					niz_cifara_broja_iz_niza_1[i]=niz_cifara_broja_iz_niza_1[i+1];
					i++;
				}
				i=j;
				brojac--;
			}
		}
	i=0;
	while(i<brojac){
		broj=broj+niz_cifara_broja_iz_niza_1[i]*pow(10,i);
		i++;
	}
	if (negativan){
		broj=broj*-1;
	niz_1[k]=broj;
	} else {
		niz_1[k]=broj;
		}
	k++;
	}
	return 1;
}

int main() {
	int brojevi[] = {123, 456};
	int cifre1[] = {1, 2, 3, 1};
	int cifre2[] = {1, 2, 10, 4};
	int cifre3[] = {1, 2, 3, -4};
	int i, rez;
	rez = izbaci_cifre(brojevi, 2, cifre1, 4);
	printf("%d\n", rez);
	rez = izbaci_cifre(brojevi, 2, cifre2, 4);
	printf("%d\n", rez);
	rez = izbaci_cifre(brojevi, 2, cifre3, 4);
	printf("%d\n", rez);
	cifre3[3] = 4;
	rez = izbaci_cifre(brojevi, 2, cifre3, 4);
	printf("%d\n", rez);
	printf("%d %d", brojevi[0], brojevi[1]);
}