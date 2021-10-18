#include <stdio.h>
#include <math.h>

int main() 
{
	int n,br1,br2,a,b=0,c=1;
	
	printf("Unesite broj: ");
	scanf("%d",&n);
	
	if(n<0)
		n=fabs(n);
	if(n<10)
	{
		printf("0");
		return 0;
	}	
	
	while(n>=10)
	{
		br1=n%10;
		n/=10;
		br2=(n%10);
		
		a=fabs(br1-br2);
		
		b+=a*pow(10,c);c++;
		
	}
	
	printf("%d",b/10);
	
	return 0;
}
