#include <stdio.h>
#include <math.h>

int abs(int n);

int main() {
	
	int n, c, i, temp, suma=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n>=0 && n<=9)
	{
		printf("0");
		return 0;
	}
	else 
	{
		if(n<0) {
			n=abs(n);
		}
	
		c=n%10;
		temp=c;
		n/=10;
		i=1;
		while(n!=0) {
			c=n%10;
			suma+=abs(temp-c)*i;
			temp=c;
			n/=10;
			i*=10;
			
		}
	}
	printf("%d", suma);
	return 0;
}
