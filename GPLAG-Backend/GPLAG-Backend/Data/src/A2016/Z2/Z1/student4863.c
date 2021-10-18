#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int x,n,a,b,r=0, br_cifara=0,i,i2, j=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=abs(n);
	x=n;
	do{
		x/=10;
		br_cifara++;
	}while(x!=0);
	br_cifara--;
	i=br_cifara;
	i2=i;
	if(br_cifara==0) printf("0");
	
	else
		do{
			a=n/pow(10,br_cifara);
			b=n/pow(10,--br_cifara);
			b%=10;
			n=n-(a*(pow(10,++br_cifara)));
			r=abs(a-b);
			if(br_cifara ==i && r==0){
				printf("");
				i--;
				j++;
			}
			else	
				printf("%d", r);
			br_cifara--;
	
			if(br_cifara==0 && j==i2)
				printf("0");
		}while(br_cifara!=0);
	
	

	
	return 0;
}
