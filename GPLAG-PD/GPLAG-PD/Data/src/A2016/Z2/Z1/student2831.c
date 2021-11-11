#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,a,b,c,s=0,h,d=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n>0 && n<10) printf("0");
	else {
		h=abs(n);
		while(h>=10) {
			a=h%10;
			b=h%100;
			b=b/10;
			c=abs(a-b);
			s=s+(c*d);
			d=d*10;
		    h=h/10;
		}
	printf("%d",s);

	}

	return 0;
}
