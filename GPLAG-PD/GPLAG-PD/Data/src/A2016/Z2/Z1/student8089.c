#include <stdio.h>
#include <stdlib.h>

int main() {
    int x,a,c,R=1,broj=0;
	printf("Unesite broj: ");
	scanf("%d",&x);
	x=abs(x);
	if (x/10==0){
		printf("0");
		return 0;
	}
	while (x!=0){
	  a=x%10;
	  x/=10;
	  if(x==0)break;
	  c=x%10;
	  broj+=abs(a-c)*R;
	  R*=10;
	  
	  
	   
	}
	
	printf("%d",broj);
return 0;
}