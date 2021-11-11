#include <stdio.h>
#include <stdlib.h>
int main() {
	int a,b,pwr;
	printf("Unesite broj: ");
	scanf("%d",&a);
	a=abs(a);
	b=0;
	if(a<10){
		b=0;
	}else{
		pwr=1;
		while(a>9){
			b+=abs(a%10-(a/10)%10)*pwr;
			a/=10;
			pwr*=10;
		}
	}
	printf("%d",b);
	return 0;
}
