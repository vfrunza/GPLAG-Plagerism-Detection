#include <stdio.h>
#include <math.h>

int main() {
	
	int b,c1,c2,s=0,step=0;
	
	printf("Unesite broj: ");
	scanf("%d",&b);
	b=fabs(b);
	
	while(b>9){
		
		c1=b%10;
		b=b/10;
		c2=b%10;
		s=s+fabs(c1-c2)*pow(10,step);
		step++;
	}
	printf("%d",s);
	
	return 0;
}
