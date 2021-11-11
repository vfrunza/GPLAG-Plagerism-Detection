#include <stdio.h>
#include <math.h>

int main() {
	int n,a,b,c,k=1,suma=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if (n<10 && n>=0 ) {
		printf("0");
		return 0; }
	if(n<0) 
		n*=-1;
        
		while(n!=0) {
			if(n<10) break;
			a=n%10;
			
			n/=10;
			b=n%10;
			c=a-b;
			
			if(c<0) c*=-1;
			suma+=c*k;
			k*=10;
		}
	   printf("%d", suma);
			return 0;
	}
