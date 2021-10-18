#include <stdio.h>
#include<stdlib.h>
int main() {
	int a,k=0, p=0,d=0,l=1;
	printf("Unesite broj: ");
	scanf("%d",&a);
	if(a<0)
		a*=-1;
	if(a<10)
	{
		printf("0");
		return 0;
		
	}
	
	while(a>9)
	{
		p=a%10;
		a=a/10;
		d=a%10;
		k+=abs(p-d)*l;
		l*=10;
	}
	printf("%d",k);
	return 0;
}