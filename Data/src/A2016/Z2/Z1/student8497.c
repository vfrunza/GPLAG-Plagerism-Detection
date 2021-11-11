#include <stdio.h>
#include <math.h>

int main() {
	int n,i,x,rezultat;
	i=0;rezultat=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n/10==0)rezultat=0;
	else
	{
		n=fabs(n);
		do{
			x=n%10-(n/10)%10;
			x=fabs(x);
			rezultat=rezultat+(x*pow(10,i));
			i++;
			n=n/10;
		}
		while(n>=10);
	}
	printf("%d",rezultat);
	return 0;
}
