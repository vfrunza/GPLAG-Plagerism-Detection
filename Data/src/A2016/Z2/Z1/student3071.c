#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int broj,nova,cifra=0,noviBroj=0,test,i=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj<0){
		broj=(-broj);
	}
	int brojCifri=0,test1=broj;
	while(test1!=0){
		test1=test1/10;
		brojCifri++;
	}
	test=broj;
	nova=broj%10;
	cifra=0;
	while(test!=0 && i<(brojCifri-1)){
		test=test/10;
		cifra=abs(nova-test%10);
		noviBroj+=cifra*pow(10,i);
		nova=test%10;
		i++;
	}
	printf("%d",noviBroj);
	return 0;
}
