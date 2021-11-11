#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int broj,rezultat,cifra_1,cifra_2,pom=0,i=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj<0){
		broj=-broj;
	}
	
	while(broj!=0){
		cifra_1=broj%10;
		broj/=10;
		if(broj==0) 
			break;
		i++;
		cifra_2=broj%10;
		rezultat=abs(cifra_1-cifra_2);
		pom=pom+rezultat*pow(10,i);
	}
	pom=pom/10;
	printf("%d",pom);
	return 0;
}