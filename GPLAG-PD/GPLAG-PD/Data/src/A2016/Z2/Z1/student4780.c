#include <stdio.h>
#include <stdlib.h>


int main() {
	int x,d1,d2,sum=0,p=1;
	
	printf("Unesite broj: ");
	scanf("%d", &x);
	
	d1=x%10; x=x/10;
	
	while(x!=0){
		
		d2=x%10;
		sum=sum+abs((d1-d2))*p;
		p*=10;
		d1=d2; x=x/10;
		
	}
  printf("%d",sum);
  
  
  return 0;
}
