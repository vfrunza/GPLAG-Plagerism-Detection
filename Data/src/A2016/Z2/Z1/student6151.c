#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int n, c, b,broj=0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	int k=1;
	
	while(n!=0){
		c=abs(n)%10;
     	n=abs(n)/10;
     	if(n==0)break;
     	b=abs(n)%10;
     	
     	broj=broj+(abs(c-b)*k);
     	k=k*10;
     	
	}
	printf("%d", broj);
	
	return 0;
}
