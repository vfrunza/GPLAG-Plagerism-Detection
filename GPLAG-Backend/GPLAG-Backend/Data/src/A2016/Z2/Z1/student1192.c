#include <stdio.h>
#include<math.h>
int main() {
	int n, c, c2, c3, m, r,r1, r2, br1, br2;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)
		n=fabs(n);
	if(n<10)
		printf("0");
	else 
	{
	r=0;
	r1=0;
	m=n;
	br1=0;
	br2=0;
	c2=0;
	while(n>0)
	{
		if(n==m)
		{
		c=n%10;
		n=n/10;
		c2=c;
		}
		else 
		{
		br1++;
		c=n%10;
		n=n/10;
		c3=fabs(c2-c);
		if((br1==1)&&(c3==0))
			br2=1;
		c2=c;
		r=r*10 + c3;
		}
		
	}
	while(r>0)
	{
		r2=r%10;
		r1=r1*10 + r2;
		r=r/10;
	}
	if(br2==1)
		r1=r1*10;
	printf("%d", r1);
	}
	return 0;
}
