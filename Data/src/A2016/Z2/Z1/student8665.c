#include <stdio.h>
#include <math.h>

int main() {
	int x=0,c1=0,c2=0,novibroj=0,broj=0;
		printf("Unesite broj: ");
		scanf("%d", &x);
	if(x<0)
		x=fabs(x);
	if(x<10){
		printf("0");
		return 0;
		}
	
	while(x>10){
		c1=x%10;
		x=x/10;
		c2=x%10;
		novibroj+=(fabs(c1-c2)*pow(10,broj));
		broj++;
	}
		printf("%d", novibroj);
	
	return 0;
}
