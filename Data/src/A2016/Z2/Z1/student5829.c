#include <stdio.h>
#include <stdlib.h>
int main() {
	int n,a,o,k,br,mn;
	mn=1;
	br=0;
	printf ("Unesite broj: ");
	scanf ("%d", &n);
	if (n<0) { n = abs(n);
	

	while (n>9) {
    	
      	a=n%10;
		n=n/10;
		o=n%10;
		k=abs(a-o);
		
		br=br+mn*k;
		mn=mn*10;
	}
		printf ("%d", br);
	}
	
	else if (n>0 && n<10) printf ("0");
	
	else {
		while (n>9) {
    	
      	a=n%10;
		n=n/10;
		o=n%10;
		k=abs(a-o);
		
		br=br+mn*k;
		mn=mn*10;
	}
	printf ("%d", br);
	}

 
	return 0;
}
