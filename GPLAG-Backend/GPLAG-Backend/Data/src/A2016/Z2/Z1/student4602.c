#include <stdio.h>
#include<stdlib.h>

int main() {
	int n=0, i=0, a=0,m=0, c=0,broj=0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0) n=n*(-1);
	
	while(n>10){
		
		i=n%10;
	    a=n/10;
	    m=a%10;
		c *= 10 ;
		c+= abs(i-m);
		n/=10;
	}
	i=0;
		while(c){
			i=c%10;
			broj *=10;
			broj +=i;
			c/=10;
			
		}
	printf("%d", broj);
	return 0;
}
