#include <stdio.h>
#include <math.h>

int main() {
	
	int broj, cifra1, cifra2, nova_cifra;
	int suma=0, desetica=1;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	
	do{
	broj=fabs(broj);
	if(broj/10==0){
		printf("0");
		return 0;
	}
	cifra1=broj%10;
	broj=broj/10;
	cifra2=broj%10;
	nova_cifra=fabs(cifra1-cifra2);
	suma=suma+(nova_cifra*desetica);
	desetica=desetica*10;
	}while(broj>=10);
	
	printf("%d",suma);
	return 0;
}
