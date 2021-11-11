#include <stdio.h>
#include <math.h>
int main() {
	int k,c1,c2,n,s;
	
	printf ("Unesite broj: ");
	scanf("%d",&n);
	c1=n%10;
	n=n/10;
	s=0;
	k=1;
	while (n!=0)
{
	c2=n%10;
	s=s+(k*(fabs(c1-c2)));
	k*=10;
	n/=10;
	c1=c2;
}
  printf ("%d",s);
	return 0;
}
