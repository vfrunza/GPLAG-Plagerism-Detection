#include <stdio.h>
#include <math.h>

int main() {
	int n,x,br=0,suma=0;
	
	printf("Unesite broj: ");
	scanf("%d",&n);
	
	if(n<0) n=-n;
	
	while(n>=10) {
		
		x=(n%10)-((n/10)%10);
		
		if(x<0) x=-x;
		
		suma+=pow(10,br)*x;
		br++;
		n=n/10;
	}
	printf("%d",suma);
	return 0;
}
