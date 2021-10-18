#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int a, i=0,zadnjacifra, predzadnja, rezultat=0, broj=0; 
	int sum=0;
	printf("Unesite broj: ");
	scanf("%d",  &a);
while (a!=0)
	{zadnjacifra=a%10; 
    predzadnja=(a%100-zadnjacifra)/10;
    a=a/10;
    if(a==0) break;
   rezultat=abs(zadnjacifra-predzadnja);
   broj=pow(10, i)*rezultat;
   sum=sum+broj; i++;}
	   printf("%d", sum);
	
 
   return 0;}