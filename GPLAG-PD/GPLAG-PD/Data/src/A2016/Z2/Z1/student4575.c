#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int x, a=0, b=0, c=0, z=0, y=0, t=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if (x>=0 && x<10)
	printf("0");
	if (x<0){ x=abs(x);
	do{
	a=(x%10)-((x%100)/10);
	x=x/10;
	if(a<0) a=abs(a);
	b=b+(a*pow(10,z));
	z=z+1;}
	while (x>9);
	printf("%d", b);
	}
	if (x>10) {
    do {
	c=(x%10)-((x%100)/10);
	x=x/10;
	if(c<0) c=abs(c);
	y=y+(c*pow(10,t));
	t=t+1;}
	while(x>9);
	printf("%d", y);}
	
	return 0;
}
