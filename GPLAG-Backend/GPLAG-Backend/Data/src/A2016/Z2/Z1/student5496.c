#include <stdio.h>
#include <math.h>
int main() {
	int n,C1,C2;
	int k=1;
	int S=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=fabs (n);
		while(n>=10){
		C1=n%10;
		C2=(n/10)%10;
		S+=fabs((C1-C2)*k);
		k*=10;
		n/=10;
    
	}
	printf("%d", S);
	return 0;
}
