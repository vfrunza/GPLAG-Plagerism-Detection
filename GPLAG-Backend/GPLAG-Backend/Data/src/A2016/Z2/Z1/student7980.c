#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,n,cifrajedan,cp,cy,s,d=1,cifra=0;
	
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0)
	{
		n=abs(n);
	}
	while(n>10) 
	{
		cifrajedan=n%10;
		cp=(n/10)%10;
	
		s=abs(cifrajedan-cp)*d;
		d=d*10;
		cifra=cifra+s;
	
				
		n=n/10;
		
	
	
	}
			printf("%d",cifra);

	
	
	
	return 0;
}
