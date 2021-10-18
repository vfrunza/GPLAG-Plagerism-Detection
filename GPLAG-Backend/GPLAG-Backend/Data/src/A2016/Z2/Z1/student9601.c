#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int broj,a,b,c,n=-1,d=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	do{
	
		a=broj%10;;
		broj/=10;
		if(broj==0)
			break;
		b=broj%10;
		n++;
		c=abs(a-b);
			if (c==0)
				continue;
				else
					d=d+c*(pow(10,n));
	}while(broj!=0);
	printf("%d",d);
	return 0;
}
