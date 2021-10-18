#include <stdio.h>
#include <stdlib.h>
int main() {

int a, c=0, cifra1, cifra2, b=1, razlika;
printf("Unesite broj: ");
scanf("%d", &a);
 a=abs(a);

if(a<10)
{printf("0"); 
return 0;}

do { 
	cifra1=a%10;
	a=a/10;
	cifra2=a%10;
	razlika=abs(cifra1-cifra2);
	c=c+b*razlika;
	b=b*10;
}
while(a>9);
printf("%d", c);
return 0;

}
