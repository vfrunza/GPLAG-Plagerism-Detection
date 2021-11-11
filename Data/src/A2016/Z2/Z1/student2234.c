#include <stdio.h>
#include <math.h>

int main() {
	int n,x,y,c1,c2,i;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) n=fabs(n);
	else if(n>=0 && n<=9){
		y=0;
		printf("%d",y); 
		return 0;
	}
	i=1;
	y=0;
	c1=n%10;
	n=n/10;
	c2=n%10;
	n=n/10;
	y=fabs(c1-c2);
	while(n!=0){
		c1=c2;
		c2=n%10;
		n=n/10;
		x=fabs(c1-c2);
		y+=x*pow(10,i);
		i++;
	}
	printf("%d",y);
	
	return 0;
}
