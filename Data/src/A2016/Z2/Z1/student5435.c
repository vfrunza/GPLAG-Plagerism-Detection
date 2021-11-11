#include <stdio.h>
#include <stdlib.h>

int main() {
	int a,b,d,k=0,pom,brojac=0,l=0;
	int c,s=0;
	
	printf("Unesite broj: ");
	scanf("%d",&a);
	c=a;
	 if(a%10==a){printf("0");return 0;}
	else if(a<0){
		a=abs(a);}
	while(a%10!=a){
		b=a%10;
		a=a/10;
		c=a*10;
		d=a%10;
		c=abs(c+abs(b-d));
		if(k==0 && brojac>0){l=1;}
		if(k==0){k=c%10;}
		else if(k!=0 || (k==0)){k=((c%10)+k*10);}
		c=a;
		brojac++;
	}
	while(k>0){
		pom=k%10;
		s=s*10+pom;
		k=k/10;
		
	}
	if(l==0){
	printf("%d",s);
	}
	else if(l==1){
		s=s*10;
		printf("%d",s);
	}
	return 0;
}
