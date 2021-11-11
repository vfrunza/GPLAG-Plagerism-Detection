#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int x;
	int y,z,a=0,u;
	int i=0;
	printf("Unesite broj: ");
	scanf("%d",&x);
	if (x<0) x=x*(-1);
	if(x/10==0) a=0;
	else {
		while(x>10){
			y=x%10;
			x/=10;
			z=x%10;
			u=abs(y-z);
			a+=u*pow(10,i);
			i++;
		}
	}
	printf("%d", a);
	return 0;
}