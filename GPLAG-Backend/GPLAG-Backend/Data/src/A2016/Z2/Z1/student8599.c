#include <stdio.h>
#include <math.h>

int main() {
	long n;
	int  a, b, c, d, i, x, f;
	printf("Unesite broj: ");
	scanf("%ld", &n);
	if(n>-10 && n<10)
		printf("0");
	else {
		if(n<-10)
		n=(-1)*n;
		x=0;
		f=n;
		do{
			f=f/10;
			x+=1;
		} while(f>10);
		d=0;
		for(i=0; i<x; i++){
		a=n%10;
		b=n%100/10;
		n=n/10;
		c=b-a;
		if(c<0)
		c=a-b;
		d+=pow(10,i)*c;
}
		printf("%d", d);
	}
	return 0;
}
