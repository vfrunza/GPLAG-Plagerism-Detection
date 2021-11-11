#include <stdio.h>
#include <math.h>
int main() {
	int n,j,d,br=0,a,x=0,n1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if (n>=0 && n<10) {printf("0"); return 0;}
	if(n<0) n=fabs(n);
	n1=n;
	while (n1>0)
	{
		n1=n1/10;
		br++;
	}
	
	while(br>1)
	{	
		j=n/(pow(10,br-1));
		d=(n-j*(pow(10,br-1)))/(pow(10,br-2));
		a=fabs(j-d);
		n=n-j*pow(10,br-1);
		br--;
		x=x+a*pow(10,br-1);
	}
		
		printf("%d",x);
		
	
	return 0;
}
