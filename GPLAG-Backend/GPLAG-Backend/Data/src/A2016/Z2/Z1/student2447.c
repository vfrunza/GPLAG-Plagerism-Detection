#include <stdio.h>
#include <math.h>

int main() {
	
	int n,a,b,c=0,i=1;
	
	printf("Unesite broj: ");
	scanf("%d",&n);
	
	if(n<0){
				n=fabs(n);
			}
			
			if(n<10){
				printf("0");
				return 0;
			}
		
		while(n>=10){
			
			a=n%10;
			n=n/10;
		
			b=n%10;
		
			c=i*fabs(a-b)+c;
			i*=10;
			
			
		}
	/*	int k=0;
		for(;c!=0;){
			k=c%10+10*k;
			c/=10;
		}*/
		
	printf("%d",c);
	
	return 0;
}
