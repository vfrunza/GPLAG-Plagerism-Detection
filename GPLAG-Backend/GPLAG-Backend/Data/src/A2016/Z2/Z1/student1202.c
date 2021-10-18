#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
/* printf("Zadaca 2: Zadatak 1"); */

int broj,prva_cifra,druga_cifra=1;
int suma=0;
int brojac=0;
/* unos broja i ispitivanje u skladu sa uslovima zadataka */
printf("Unesite broj: ");
scanf("%d",&broj);
if(broj<10 && broj>-10){printf("0"); return 0;} /* ako je broj jednocifren, ispisi nulu */
else if (broj < 0) broj=broj*(-1); /* ako je negativan, ispisi apsolutnu vrijednost tog broja */
while(broj > 0){
	prva_cifra=broj%10;
	broj=(int)broj/10;
	druga_cifra=broj%10;
if(broj >0){
	suma+=(abs(prva_cifra-druga_cifra))*pow(10,brojac);
}
else {
	printf("%d",suma);
	return 0;
}
brojac++;
}
/*while(broj>=10 ){

	prva_cifra=broj%10;
	broj=(int)broj/10;
	druga_cifra=broj%10;
	if(prva_cifra>druga_cifra)printf("%d",prva_cifra-druga_cifra);
	else printf("%d",druga_cifra-prva_cifra);
	if(broj>=10) druga_cifra=prva_cifra;
	else return 0;
	

	
}*/


	return 0;
}
