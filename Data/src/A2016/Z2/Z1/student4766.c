#include <stdio.h>
#include <stdlib.h>
int main() {
	int x, c1, c2, mult, newX;
	newX =0;
	mult = 1;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if(x<0)
	x = -x;
	if(x>10){
	do{
	c1 = x%10;
	c2 = x%100 - c1;
	c2 = c2/10;
	newX += (abs(c1-c2))*mult;
	mult *=10;
	x = x/10;
	}while(x>9);
	}
	printf("%d", newX);
	return 0;
}