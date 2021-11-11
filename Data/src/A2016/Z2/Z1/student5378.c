#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n,j=1,k,c1,c2,x=0,temp=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	k=1;
	if (n<0){ n=abs(n);}
	while (n>=10){
		
		c1=n%10;
		c2=(n/10)%10;
		x+=abs(c1-c2)*k;
		k*=10;
		n/=10;
		j++;
}

	printf("%d",x);
	return 0;
}
