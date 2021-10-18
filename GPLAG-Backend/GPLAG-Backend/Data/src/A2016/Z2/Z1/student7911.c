#include <stdio.h>
#include <math.h>

int main(){
	int broj,elva=0,brojac1=0,brojacnula=0,don=0;
	int cifra1,cifra2,cifra;
	
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj = fabs(broj);
	
	if(broj<10){ 
		printf("0");
}
	else{
	while(broj!=0){
	cifra1 = broj%10;
	broj=broj/10;
	if(brojac1!=0)
	elva=elva*10+fabs(cifra1-cifra2);
	if(elva==0 && brojac1==1)
	brojacnula++;
		cifra2=cifra1;
		brojac1++;
	}
	if(elva==0) printf("0");
	else{
	
	while(elva!=0){
	cifra=elva%10;
	elva/=10;
	if(don==0 && cifra==0) continue;
	printf("%d",cifra);
	don++;
}
if(brojacnula>0) printf("0");

}
}
	return 0;
}