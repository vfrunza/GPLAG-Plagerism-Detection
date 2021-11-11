#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
int a,b, broj, rezultat=0, kolicnik=1;
printf("Unesite broj: ");
scanf("%d",&broj);

broj=abs(broj);
if(broj<10)
{ printf("0");return 0;
} while 
(broj>=10){
	a=broj%10;
	broj=broj/10;
	b=broj%10;
	rezultat=rezultat+(abs(a-b))*kolicnik;
	kolicnik=kolicnik*10;
	

}
printf("%d",rezultat);

	return 0;
}
