#include <stdio.h>
#include <stdlib.h>
int main() {
	int k=1,n,b,d,c=0,m=0,g;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n>-10 && n<10){
	printf("0");
	}else{
		if(n<0) 
		n=-n;
		while(n>=10){
			b=n%10;
			d=(n/10)%10;
			k=k*10;
			c=abs(b-d);
			g=c*k;
			m=m+g;
		    n=n/10;
		}
		 m=m/10;
		printf("%d", m);
	}
	return 0;
}
