#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int main() {
	int n,a,c,b,br=0,d=0;
	
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) n=abs(n);
	if(n<10 && n>0){ printf("%d",d);}
	else{
	
	do{
		
	a=n%10;
	b=(n/10)%10;
	c=fabs(fabs(a)-fabs(b));
	d=d+pow(10,br)*c;
	br++;
	n=n/10;
	
	}while (n>9);
	printf("%d",d);}
	return 0;
}
