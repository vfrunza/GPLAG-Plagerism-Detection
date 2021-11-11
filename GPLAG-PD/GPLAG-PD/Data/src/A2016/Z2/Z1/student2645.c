#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int n, x, y, suma=0, z, p=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if(n<0) {
		n=abs(n);
	}
	else if(n/10==0) {
		printf("0");
		return 0;
	}
	
	while(n!=0) {
		if(n/10==0) 
			break;
		x=n%10; y=n%100; y=y/10;
		z=abs(x-y);
		suma=suma+z*p;
		
		p=p*10;
		
		n=n/10;
	}
	
	printf("%d", suma);
	
	
	
	
	return 0;
}
