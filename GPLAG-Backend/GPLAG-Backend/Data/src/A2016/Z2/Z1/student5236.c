#include <stdio.h>
#include <stdlib.h>
int main() {
	int x,c1,c2,n=1,rez=0;
	printf("Unesite broj:");
	scanf("%d",&x);
	
	if( x>0 && x<10 ){
		rez=0;
	}
	if(x<0){
		x=-x;
	}
	while(x>=10){
		
		c1=x%10;
		c2=(x/10)%10;
		rez+=abs(c1-c2)*n;
		n*=10;
		x/=10;
	}
    printf(" %d",rez);
	return 0;
}
