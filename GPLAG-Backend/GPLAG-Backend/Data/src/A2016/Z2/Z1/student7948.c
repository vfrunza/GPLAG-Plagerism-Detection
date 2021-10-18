#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,i,j,m,a,b,c,d,s;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	n=abs(n);
	for (i=1;i<n;i++){
		m=(int)n/(pow(10,i));
		if (m==0){
		break;}
	}
//------------------------------------------------------------------------------
	s=0;
	for (j=0;j<i-1;j++){
		a=n%10;
		b=n/10;
		c=b%10;
		d=abs(a-c);
		s=s+(d*pow(10,j));
		n=b;
	}
	printf("%d", s);
	return 0;
}
