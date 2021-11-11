#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int broj,rez=0,cif1,cif2,i=0,razl=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=abs(broj);
	if(broj<10){rez=0;printf("%d",rez);return 0;}
	//if(broj<0){broj=abs(broj);}
		do{
			cif1=broj%10;
			broj/=10;
			if(broj!=0){
			cif2=broj%10;
			razl=cif1-cif2;
	//		if(razl<0) razl=abs(razl);
			rez=rez+abs(razl)*pow(10,i);
			i++;}
		}while(broj!=0); 
		printf("%d",rez);
	return 0;
}