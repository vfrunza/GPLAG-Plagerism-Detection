#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int n,c,r,c1,s=0,m,x,i=0,j=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	{m=n;
	
	do{x=m%10;
		m=m/10;
		i++;}while(m!=0);
	
	if(i==1){printf("0");return 0;}}
	
	if(n>0){
		do{
		c=n%10;
		c1=(n%100)/10;
		n=n/10;
		r=abs(c-c1);
		
		s=s+r*(pow(10,j));
		j++;}while(n>10); 
	printf("%d",s);
	return 0;}
	if(n<0)
	{
		n=abs(n);
		do{
		c=n%10;
		c1=(n%100)/10;
		n=n/10;
		r=abs(c-c1);
		
		s=s+r*(pow(10,j));
		j++;}while(n>10);
	printf("%d",s);
		return 0;
	}
	

	
	return 0;
}
