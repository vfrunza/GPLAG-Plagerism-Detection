#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main () {
	int x,o,q,p=0,t=0,s=0;
	printf ("Unesite broj: ");
	scanf ("%d",&x);
		if (x<0) {
			x=abs(x); 
			}
		if ((x>0) && (x<10)) {
			
			s=0;
		printf ("%d",s);
		return 0;
			}
	for (;x>=10;p++)
	{
		o=x%10;
		x=x/10;
		q=x%10;
		t=abs((o-q))*pow(10,p);
		s=s+t;
	}
	printf ("%d",s);
	return 0;
}