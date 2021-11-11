#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	long long int a=0,s=0,c=0;
	printf("Unesite broj: ");
	scanf("%i",&a);
	a=abs(a);
	while(a>=10){
		s+=abs((a%10)-(a/10)%10)*pow(10,c);
		c++;
		a=a/10;
		
	}
	printf("%i",s);
	return 0;
}