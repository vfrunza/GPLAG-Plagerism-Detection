#include <stdio.h>

int main() {
	int n, niz[100], sve_cifre[1000], i,  cifra, brojac=0;
	long int spojeni=0; /*svi elementi niza spojeni u jedan veliki broj*/
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	}while(n<0 || n>100);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++)
		do{
			scanf("%d", &niz[i]);
		}while(niz[i]<0);
	for(i=n-1; i>=0; i--)
		while(niz[i]!=0){
			cifra = niz[i]%10;
			niz[i] /= 10;
			spojeni = spojeni*10 + cifra;
			brojac++;
		}
	i=0;
	if(cifra==0){
		sve_cifre[0] = 0;
		i++;
		while(spojeni!=0 && spojeni%10==0){
			i++;
			spojeni/=10;
		}
		
	}
	printf("%ld", spojeni);
	//treba porediti starau i novu cifru 
	while (i<brojac){
		cifra = spojeni%10;
		spojeni\=10;
		sve_cifre[2*i]=cifra 
	}
	return 0;
}
