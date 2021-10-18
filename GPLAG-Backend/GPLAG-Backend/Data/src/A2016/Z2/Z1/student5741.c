#include <stdio.h>
#include <math.h>

int main() {
	int n,x1,x2,a,r,r1,br,p1,i,p2,r2,r11,p11,a11,a12,p12,br1;
	br=0;
	r2=0;
	br1=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	a=fabs(n);
	if(n<10 && n>=0){
		printf("0");
	}
	else{
		do{
			a=a/10;
			br++;
		}
		while(a!=0);
		a=fabs(n);
		p11=pow(10,br-1);
		p12=pow(10,br-2);
		a11=a/p11;
		a12=(a%p11)/p12;
		r11=a11-a12;
		a=fabs(n);
		for(i=br-1;i>0;i--){
			p1=pow(10,i);
			p2=pow(10,i-1);
			x1=a/p1;
			x2=(a%p1)/p2;
			r=x1-x2;
			r1=fabs(r);
			if(r1==0 && r2==0 && r11==0){
				printf("");
				br1++;
				if(br1==br-1){
					printf("0");
				}
			}
			else{
			printf("%d",r1);
			}
			a=a%p1;
			r2=r1;
		}
	}
	return 0;
}
