#include <stdio.h>
#include <math.h>
int main() {
	int br;
	printf("Unesite broj: ");
	scanf("%d",&br);
	if(br<0)br=br*(-1);
	int c1=0,c2=0,pom=0,bro=0,z=0,s=0,g=1;
	c1=br%10;
	while(br>10){
		br/=10;
		c2=br%10;
		pom=c1-c2;
		if(pom<0)pom=pom*(-1);
		g=pow(10,bro);
		z=pom*g;
		s+=z;
		c1=c2;
		bro++;
	}
	printf("%d",s);
	return 0;
}
