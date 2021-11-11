#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int a,b,p,p1=0,suma,n=0;
	printf("Unesite broj: ");
	scanf("%d", &p);
	p=abs(p);
	if (p<10){
		p1=0;
		printf("%d", p1);
	} else {
	n=1;
	while(p>=10){
		a=p%10;
		p/=10;
		if(p!=0){
		b=p%10;
		suma=abs(b-a);
		p1=p1+suma*pow(10,n-1);
		n++;}
	}
	printf("%d", p1);
	}
	
	return 0;
}