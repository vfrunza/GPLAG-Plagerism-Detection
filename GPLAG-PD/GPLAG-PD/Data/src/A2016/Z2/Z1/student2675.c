#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i,b=0,n,r,p,h,t=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n=abs(n);
	p=n;
	while(p>0)
	{
		p=p/10;
		b++;
	}
	if(b==1 || n==0)
	{
		printf("0");
	}
	else
	{
		for(i=b;i>1;i--)
		{
			h=(int)pow(10,i-1);
			r=abs(((n/(h/10))%10)-(n/h));
			if(r!=0)
			{
				t=1;
			}
			if(t || i==2)
			{
				printf("%d",r);
			}
			n=n%h;
		}
	}
	return 0;
}