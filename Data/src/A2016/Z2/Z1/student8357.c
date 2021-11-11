#include <stdio.h>
#include <math.h>
int main() {
	long long int n,i,a,x=0,k=10;
	printf("Unesite broj: ");
	scanf("%lld",&n);
	n=fabs(n);
	for(i=n;i>i%10;i=i/10){
		a=fabs(i%10-(i%100/10));
			if(i==n){
				x=x+a; 
				};
			   x=x+a*k;
			   k=k*10;
		}
		printf("%lld",x/10);
	

	return 0;
}
