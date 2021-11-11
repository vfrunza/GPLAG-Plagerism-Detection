#include <stdio.h>
#include <math.h>

int main() {
	int broj, cifra, kopija, rezultat=0, racun,i=1;
	
	 
	
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=fabs(broj);
	
	if(broj>=0 && broj<10) printf("%d",0);
	
	else{
		do{
		cifra=broj%10;
		kopija=((broj%100)-cifra)/10;
		racun=cifra-kopija;
		rezultat=rezultat+i*fabs(racun);
		broj=broj/10;
		i*=10;
		
		}while(broj/10!=0);
		printf("%d",rezultat);
	
	}
	return 0;
}
