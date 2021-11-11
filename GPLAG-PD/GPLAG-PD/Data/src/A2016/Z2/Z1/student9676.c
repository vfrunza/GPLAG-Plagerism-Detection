#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int n, a=0, b=0, s1=0, s=0, j=0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if (n>-10 && n<10){
		printf("0");
		return 0;
	}
	
	while (n!=0){
	
		if (n>-10 && n<10){
			break;
		}
		
		a=n%10;
		b=(n/10)%10;
		
		s1=abs(a-b);
		
		s=s1*pow(10,j)+s;
		
		n=n/10;
		j++;
	}
	
	printf("%d", s);
	
	return 0;
}
