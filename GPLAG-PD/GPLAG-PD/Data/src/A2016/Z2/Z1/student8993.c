#include <stdio.h>
#include <math.h>
int main() {
int n,i=1,s=0,z=0,b=0;
printf("Unesite broj: ");
scanf("%d",&n);
if(n>=0 && n<9) {
	s=0; 
	printf("%d",s);
	return 0; }
if(n<0)
n=n*(-1);
while(n>0) {
	z=n%10;
	n=n/10;
	b=n%10;

	if(n==0) break;
	s=s+fabs((z-b))*i;
	if((n/10)<0) break;
	i=i*10;
}

printf("%d",s);
	return 0;
}
