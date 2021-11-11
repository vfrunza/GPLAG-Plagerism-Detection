#include <stdio.h>
#include <math.h>

int main() {
	int  n, rez= 0, umanjenik= 0, umanjilac= 0 , brojac= 1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n>(-10) && n<10 ){printf("0");  return 0;}
	if(n<0) n= n * (-1);
	
	umanjenik= n%10;
	n/= 10;
	while(n!=0)
		{
		umanjilac = n % 10;
		rez+= fabs(umanjenik - umanjilac) * brojac;
		umanjenik = umanjilac;
		n/= 10;
		brojac*= 10;
		}
	printf("%d", rez);
	
	
	return 0;
}
