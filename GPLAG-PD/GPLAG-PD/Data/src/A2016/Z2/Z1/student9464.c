#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n,br1=0,br2=0,u=0,c=10,a,brojac=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0)
		n*= -1;
	while(n>9){
		br1=n%10;
		n=n/10;
		br2=n%10;
		a=br1-br2;
		u+=abs(a)* pow(c,brojac);
		brojac++;
	}
	printf("%d",u);
	return 0;
}
