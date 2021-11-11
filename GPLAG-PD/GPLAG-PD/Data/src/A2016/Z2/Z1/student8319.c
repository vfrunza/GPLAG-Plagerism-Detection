#include <stdio.h>
#include <math.h>
int main() {
	int a,b,br=0,x=1,n;
	printf("Unesite broj:");
	scanf("%d",&n);
	
	do
	{
		a=n%10;
		n=n/10;
		if(n==0)
		break;
		b=n%10;
		br=br+fabs(a-b)*x;
		x=x*10;
		
	}while(n!=0);
	
	printf(" %d",br);
	
	return 0;
}
