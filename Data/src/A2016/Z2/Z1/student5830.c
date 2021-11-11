#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int n,d,p,u=1;
	int b=0,t;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n>=0 && n<10){printf("0");return 0;}
	while(abs(n)>=10)
	{
		
		p=n%10;
		d=((int)n/10)%10;
		t=p-d;
		b=b+(abs(t))*u;

		u=u*10;
		n=(int)n/10;

	}
	printf("%d",b);
	return 0;
}
