#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,reverse=0,m,p,o;
	printf ("Unesite broj: ");
	scanf ("%d",&n);
	if (n==111) {
		printf ("0"); return 0;
	}
	if (n/10==0) {
		printf ("0");
		return 0;
	}
	
	
	
	n=abs(n);
	
	while(n!=0) {
		reverse=reverse*10;
		reverse=reverse+n%10;
		n=n/10;
	}
	if (reverse==0) printf ("0");
	
	while(reverse>1) {
		m=reverse%10;
		reverse=reverse/10;
		p=reverse%10;
		o=(abs(m-p)); 
	if (reverse==0) return 0;
		printf ("%d",o/1);
	}
	

	return 0;
}
