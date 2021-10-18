#include <stdio.h>
#include <stdlib.h>

int main() {
	int n=0,br=1,j=0,d=0,a=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if (n<0)
		n=abs(n);
	if(n>0 && n<10)
		a=0;
	while(n>10) {
		j=n%10;
		d=(n/10)%10;
		n/=10;
		a+=(abs(j-d))*br;
		br*=10;
		if(n==0)
			break;

	}
	
printf("%d",a);
return 0;
}
