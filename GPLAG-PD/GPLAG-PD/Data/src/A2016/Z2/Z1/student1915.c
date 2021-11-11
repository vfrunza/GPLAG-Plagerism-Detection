#include <stdio.h>
#include<math.h>

int main() {
int n;
int a,b,c;
int pom,pomb,pomc,nule;


   printf("Unesite broj: ");
	scanf("%d",&n);
	
	if(n<0){
		n*=-1;
	}
nule=1;
pom=n;
pomb=n%10;
while(pom>0){
	pom/=10;
	pomc=pom%10;
	
	if(pomb-pomc==0) nule*=10;
	else break;
}



 a=0;
 b=n%10;
	
while(n/10!=0){
	
n/=10;

c=n%10;

a*=10;
a+=fabs(b-c);

b=c;

}

n=a;
a=0;

while(n>0){
	a*=10;
	a+=n%10;
	n/=10;
}
	a*=nule;
printf("%d\n",a);

	return 0;
}
