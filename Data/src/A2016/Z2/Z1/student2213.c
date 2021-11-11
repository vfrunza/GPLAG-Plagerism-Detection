#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int novibroj=0,broj,cifra1,cifra2,i,p=0;
	
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=abs(broj);

for(i=0;i<broj;i++){
if(i>10){
cifra1=broj%10;
cifra2=(broj/10)%10;

novibroj=novibroj+abs(cifra1-cifra2)*pow(10,p);
p++;

broj=broj/10;
	} }
	printf("%d",novibroj);
		
	return 0;
}
