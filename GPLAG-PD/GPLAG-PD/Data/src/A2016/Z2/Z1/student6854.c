#include <stdio.h>
#include <math.h>

int main() {
	int broj,broj2=0,a=0,a1=0,b=0,i=0,c=0,p,k;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	b=broj;
	for(;;){
		p=1;
		a=broj%10;
		broj/=10;
		a1=broj%10;
		if(i>=1){
		for(k=1;k<=i;k++){
			p*=10;
		}
		}
		c=fabs(a-a1);
		broj2+=c*p;
		broj/=10;
		if(broj==0) break;
		broj*=10;
		broj+=a1;
		i++;
	}
	if (b<10 && b>=0) printf("0");
	else printf("%d",broj2);
	return 0;
}
