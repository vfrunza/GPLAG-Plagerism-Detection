#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int i, broj=0, prvi, drugi, n;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=abs(n);
	if(n<10) { printf("0"); return 0; }
	prvi=n%10;
	n=(n/10.)-(prvi/10.);
	drugi=n%10;
	n=((n/10.)-(drugi/10.));
	broj+=abs(prvi-drugi);
	
	
	for(i=10; ; i*=10) {
		
		if(n>9) { 
		prvi=drugi;
		drugi=n%10;
		if(n==19) n=1;
		else
		n=(n/10.)-(drugi/10.);
		broj+=abs(prvi-drugi)*i; }
		else {
		prvi=drugi;
		drugi=n;
		broj+=abs(prvi-drugi)*i;
		break; } 
	}
	
	printf("%d", broj);
	return 0;
}