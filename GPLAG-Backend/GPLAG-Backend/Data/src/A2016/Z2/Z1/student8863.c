#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
	int a, b, c, d=0, i=1;
	printf("Unesite broj: ");
	scanf("%d",&a);
	
	if(abs(a)<=9)
		{
			printf("0");
			return 0;
		}
			a=abs(a);
	do{
	
		b=a%10;
		c=(a%100-b)/10;
		d=d+abs(b-c)*i;
		a=a/10;
		i=i*10;
	}while(a>9);
	printf("%d", d);
	return 0;
}
