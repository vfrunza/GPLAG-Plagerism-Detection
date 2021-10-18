#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int broj, pomocni1,pomocni2,razlika,brojac=0,i, konacna1=0,pomocni,konacna2=0,pomocna3,istina;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj<0) broj=abs(broj);
	pomocni=broj;
	while(pomocni>0){
		pomocni=pomocni/10;
		brojac++;
	}
	istina=0;
	for(i=0;i<brojac-1;i++){
	pomocni1=broj%10;
	broj=broj/10;
	pomocni2=broj%10;
	razlika=abs(pomocni1-pomocni2);
	if(razlika==0 && i==0) istina=1;
	konacna1=(konacna1*10)+razlika;
	}
	while(konacna1>0){
		pomocna3=konacna1%10;
		konacna2=konacna2*10+pomocna3;
		konacna1=konacna1/10;
		
	}
	if(istina==1){
		konacna2=konacna2*10;
	printf("%d",konacna2);}
else printf("%d",konacna2);
	
return 0;
}
