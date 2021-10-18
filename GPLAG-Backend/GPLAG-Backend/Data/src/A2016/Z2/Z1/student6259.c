#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int n, i, x, suma=0, br=0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if(n<0) n=abs(n);
	else if(n/10==0){
		printf("%d", 0);
		return 0;
	}
	
	for(i=0;;i++) {
		x=abs(n%10-((int)(n/10))%10);
		suma=suma + x*pow(10,br);
		n/=10;
		if (n/10==0) break;
		br++;
	}
	
	printf("%d", suma);
	
	return 0;
}
