#include <stdio.h>

int main() {
	int n,i,j,k,b=0,koef=1,g;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0) n=-n;
	
	while(n!=0) {
		if(n<10) n=0;
		i=n%10;
		n/=10;
		j=n%10;
		k=i-j;
		if(k<0) k=-k;
		g=k*koef;
		b+=g;
		koef*=10;
		
	}
	printf("%d",b);
	return 0;
}
