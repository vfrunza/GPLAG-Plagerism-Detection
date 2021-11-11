#include <stdio.h>
#include <math.h>

int main()
{
	int p, c, n, k, i=0, s, r=0, b=0, l=0;
	printf("Unesite broj: ");
	scanf("%i", &n);
	if(n<0)
		n=-n;
	if(n<10)
		printf("0");
	else {
		c=n%10;
		n=n/10;
		do {
			p=n%10;
			n=n/10;
			k=fabs(p-c);
			r=r*10+k;
			c=p;
			if(r==0)
				b++;
		} while(n>0);
		do {
			s=r%10;
			r=r/10;
			i=i*10+s;

		} while(r>0);

		if(i==0) {
			printf("0");
		} else {
			printf("%i", i);
			while(l<b) {
				printf("0");
				b--;
			}
		}
	}
	return 0;
}