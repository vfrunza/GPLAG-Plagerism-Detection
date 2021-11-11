#include <stdio.h>
#include <math.h>
int main(){
	int n=0, c1=0, c2=0, suma=0, k=1, s=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0){
		n=fabs(n);
	}
	if(n>=0 && n<=9){
	    printf("0");
	    return 0;
	}
	c1=n%10;
	n/=10;
	while(n!=0){
		c2=n%10;
		s=fabs(c1-c2);
		suma+=(s*k);
		k*=10;
		c1=c2;
		n/=10;
	}
	printf("%d", suma);
	return 0;
}