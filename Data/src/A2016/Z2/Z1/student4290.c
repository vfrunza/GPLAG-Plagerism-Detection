#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int broj_cifara(int n){
	int brojac=0;
	while(abs(n)>0){
		n=n/10;
		brojac++;
	}
	return brojac;
}
int funkcija(int n){
	int broj=0;
	int brcif=broj_cifara(n);
	int i=0;
	if(broj_cifara(n)==1)return 0;
	else{
		while(i<(brcif-1)){
			broj+=(abs((n%10)-((n/10)%10)))*pow(10,i);
			i++;
			n=n/10;
		}
	return broj;
	}
}

int main() {
	int ja;
	printf("Unesite broj: ");
	scanf("%d",&ja);
	printf("%d",funkcija(ja));
	return 0;
}
