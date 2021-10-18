#include <stdio.h>
#include <stdlib.h>

int main() {
	long int n, a, c=0, s=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=abs(n);
	if (n<10){printf("0"); return 0;}
	while(n>=10)
	{
		a=n%10;
		a=abs(a-((n/10)%10));
		c+=a*s;
		s*=10;
		n/=10;
	}
	printf("%d", c);
	return 0;
}
