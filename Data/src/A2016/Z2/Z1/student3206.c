#include <stdio.h>
#include <math.h>

int main() {
	int n,a,b,r,z,x=0,t=0,k=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n=fabs(n);
	if(n<10){
		printf("0");
		return 0;
	}
	if(n%10-(n/10)%10==0)
	k=1;
	while(n>9){
	  a=n%10;
	  n=n/10;
	  b=n%10;
	  r=fabs(a-b);
	  x*=10;
	  x+=r;
	}
	while(x>0){
		z=x%10;
		x=x/10;
		t=10*t+z;
	}
	if(k==1 && t!=0)
	printf("%d0",t);
	else
	printf("%d",t);
	return 0;
}
