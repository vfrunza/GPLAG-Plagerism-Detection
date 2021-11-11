#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int broj,cifra,x,y,i,brojcifara=0,kopija,suma=0,brojcifara1;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0) broj=abs(broj);
	kopija=broj;
	while(kopija!=0) {
		brojcifara++;
		kopija/=10;
	} brojcifara1=brojcifara-1;
     for(i=broj;i!=0;i/=10){
     	if(i==1 || i==2 || i==3 || i==4 || i==5 || i==6 || i==7 || i==8 || i==9) break;
     	else {
		x=i%10;
		y=(i%100)/10;
		cifra=abs(x-y);
		cifra=cifra*pow(10,brojcifara-brojcifara1-1);
		suma+=cifra;
		brojcifara1--;
	}} 
	printf("%d", suma);
	return 0;
}
