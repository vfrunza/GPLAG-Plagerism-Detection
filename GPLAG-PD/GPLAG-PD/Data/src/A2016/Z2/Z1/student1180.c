#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int a,x,y,s,b=0,z=0;
	printf("Unesite broj: ");
	scanf("%d", &a);
	
	if(a<0) a=fabs(a);
	else if(a<10){ 
		printf("0");
		return 0;
	}
	while(a!=0)
	{
		x=a%10;
		b++;
		y=(a/10)%10;
		s=fabs(x-y);
		z=z+(pow(10,(b-1))*s);
		a=a/10;
		if(a<10) break;
	}
	printf("%d",z);
	
	
	return 0;
}
