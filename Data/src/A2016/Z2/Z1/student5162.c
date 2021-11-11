#include <stdio.h>
#include <math.h>

int main() {
	int n,a,b,c=0,i,br=0,n1=0,k=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) n=n*(-1);
	n1=n;
	while(n>10){
		a=n%10;
		br++;
		n/=10;
	}
	n=n1;
	
	for(i=0;i<br;i++){
		
		a=n%10;
		n/=10;
		b=n%10;
		if(b>=a) c=(b-a)*k+c;
		else if(a>=b) c=(a-b)*k+c;
		k*=10;
		
		}
		printf("%d",c);
	
	return 0;
}
