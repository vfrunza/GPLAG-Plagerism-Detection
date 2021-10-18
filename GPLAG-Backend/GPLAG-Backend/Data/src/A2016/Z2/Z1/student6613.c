#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int main() {
	int n,rc,c1,c,v,i=0,s=0,k=0,pc,x;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n=abs(n);
	x=abs(n);
	do{
		pc=x%10;
		x=x/10;
		k++;
	}while(x!=0);
	if(k==1){printf("0");
	return 0;} else{
	c=n%10;
	n=n/10;
	do{
        v=pow(10,i);
		c1=n%10;
		rc=abs(c-c1);
		s=s+rc*v;
		c=c1;
		n=n/10;
		i++;
	} while(n!=0);
	
	printf("%d",s);}
	return 0;
}