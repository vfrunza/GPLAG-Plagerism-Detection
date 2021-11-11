#include <stdio.h>
#include <math.h>

int main() {
	int n, a, b,c, i=0, x=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=fabs(n);
	if(n<=10)
	{
		n=0;
		printf("%d", n);
	}
	else
	{
		while(n>=10)
		{
			a=n%10;
			b=((n/10)%10);
			c=a-b;
			if(c<0)
			{
				c=fabs(c);
			}
			x+=c*(pow(10,i));
			i++;
			n=n/10;
		}
		printf("%d", x);
	}
	return 0;
}
