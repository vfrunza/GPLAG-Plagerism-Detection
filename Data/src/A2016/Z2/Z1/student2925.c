#include <stdio.h>
#include <math.h>
int main() {
	int n,c1,c2,k,s;
	printf("Unesite broj: ");
	scanf("%d",&n);
	c1=n%10;
	n/=10;
	k=1;
	s=0;
	while(n!=0)
	{
	    c2=n%10;
	    int x=fabs(c1-c2);
	    s=s+x*k;
	    k*=10;
	    c1=c2;
	    n/=10;
	}
	printf("%d",s);
	return 0;
}
