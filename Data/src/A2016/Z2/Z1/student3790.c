#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,a1,a2,i,u,b;
	u=0;
	b=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0){n=-n;}
	for(i=n;i>=10;i=i/10){
		a1=i%10;
		a2=(i/10)%10;
		u=u+abs(a1-a2)*pow(10,b);
		b++;
	}
	printf("%d",u);
	return 0;
}
