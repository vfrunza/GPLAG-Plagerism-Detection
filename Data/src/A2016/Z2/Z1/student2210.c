#include <stdio.h>
#include <math.h>

int main() {
	int a;
	int n,br=0;
	int b1,b2,k=1,broj=0,nova,i;
	printf("Unesite broj: ");
	scanf("%d",&n);
	a=n;
	while(n!=0){
		n/=10;
		br++;
		  
	}
	for(i=0;i<br-1;i++){
		b1=a%10;
		b2=(a/10)%10;
		nova=fabs(b1-b2);
		broj=nova*k+broj;
		a/=10;
		k*=10;
	}
	printf("%d",broj);
   

	return 0;
}
