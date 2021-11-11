#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int a=0,dekadnavr, c1, c2,br,i;
	
		printf("Unesite broj: ");
		scanf("%d", &a); 
		
		br=0; c2=0; c1=0; 
	dekadnavr=1;
	a=abs(a);

	
	while (a<=-10 ||a>=10)
	{
		c2=(a/10)%10;
		c1=a%10;
		br+=abs(c2-c1)*dekadnavr;
		dekadnavr*=10;
		a/=10;
		
	}

		
		
	
	printf("%d", br);
	

	return 0;
}
