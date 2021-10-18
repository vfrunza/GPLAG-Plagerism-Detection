#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int i=0,j=0,n=0,m=0,a,k=0,r;
	
	printf("Unesite broj: ");
	scanf("%i",&a);
	 if (a>=0&&a<10) {printf("0");  return 0; }
	if(a>0&&a<10) { r=0; printf("%i",r); }
	if(a<0) { a=a*(-1);
		do {
	i=(a%10)-((a%100)/10);
	a=a/10;
	if (i<0) i=abs(i);
	n=n+(i*pow(10,m));
	m=m+1; }
		while(a>9);
		printf("%i",n);
		}
	if (a>10) {
		do {
	i=(a%10)-((a%100)/10);
	a=a/10;
	if (i<0) i=i*(-1);
	j=j+(i*pow(10,k));
	k=k+1; }
		while(a>9); 
		printf("%i",j);
	}
	return 0;
}
