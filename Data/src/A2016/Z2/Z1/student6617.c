#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main () {
	int n,i=0,e,g,d=0,j=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) {
		n=abs(n);
	}
	if(n>0 && n<10) {
		j=0;
		printf("%d",j);
		return 0;
	}
	while (n>9) {
		e=n%10;
		n=n/10;
		g=n%10;
		d=abs((e-g))*pow(10,i);
		j=j+d;
		i++;
	}
	printf("%d",j);
	return 0;
}
