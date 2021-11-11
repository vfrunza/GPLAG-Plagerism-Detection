#include <stdio.h>
#include <math.h>
int main() {
	 long int x;
	 long int Br=0,c,c1,c2,R,y=0,z,br=0;
	printf("Unesite broj: ");
	scanf("%ld",&x);
	if(x>=-9 && x<=9) {
		printf("0");
	}
	else if(x<-9) {
			z=x%10;
		x=-x;
			while(x!=0) {
		c=x%10;
		br++;
		Br=Br*10+c;
		x=x/10;
	}
	x=Br;
	while(x!=0) {
		c1=x%10;
		c2=(x%100)/10;
		if(c1<c2) {
			R=fabs(c1-c2);
	}
	else { R=c1-c2;
		}
		y=y*10+R;
		x=x/10;
	}
	if(z==0) printf("%ld",y);
	if(br>9) printf("%ld",(y-z)/10-1);
	else printf("%ld",(y-z)/10);
	}
	else {
			z=x%10;
	while(x!=0) {
		c=x%10;
		br++;
		Br=Br*10+c;
		x=x/10;
	}
	x=Br;
	
	while(x!=0) {
		c1=x%10;
		c2=(x%100)/10;
		if(c1<c2) {
			R=fabs(c1-c2);
		
		}
		else { R=c1-c2;
		}
		y=y*10+R;
		x=x/10;
	}
	if(z==0) printf("%ld",y);
	else if(br>9) printf("%ld",(y-z)/10-1);
	else printf("%ld",(y-z)/10);
	}
	return 0;
}
