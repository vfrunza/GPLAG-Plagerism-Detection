#include <stdio.h>
#include <math.h>
int main() {
	int n,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,x7=0,x8=0,t=0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n==0){
		printf("0");
	}
	else if(n>=10 && n<100){
		a=n%10;
		b=n/10;
		x1=a-b;
		p1=fabs(x1);
		printf("%d",p1);
	}
	else if(n>=100 && n<1000){
		a=n%10;
		b=(n/10)%10;
		c=n/100;
		x1=a-b;
		x2=b-c;
		p1=fabs(x1);
		p2=fabs(x2);
		if(p2==0){
			printf("%d",p1);
		}
		else{
			printf("%d%d",p2,p1);
		}
	}
	else if(n>=1000 && n<10000){
		a=n%10;
		b=(n/10)%10;
		c=(n/100)%10;
		d=n/1000;
		x1=a-b;
		x2=b-c;
		x3=c-d;
		p1=fabs(x1);
		p2=fabs(x2);
		p3=fabs(x3);
		if(p3==0 && p2==0){
			printf("%d",p1);
		}
		else if(p3==0){
			printf("%d%d",p2,p1);
		}
		else{
			printf("%d%d%d",p3,p2,p1);
		}
	}
	else if(n>=10000 && n<100000){
		a=n%10;
		b=(n/10)%10;
		c=(n/100)%10;
		d=(n/1000)%10;
		e=n/10000;
		x1=a-b;
		x2=b-c;
		x3=c-d;
		x4=d-e;
		p1=fabs(x1);
		p2=fabs(x2);
		p3=fabs(x3);
		p4=fabs(x4);
		if(p4==0 && p3==0 && p2==0){
			printf("%d",p1);
		}
		else if(p4==0 && p3==0){
			printf("%d%d",p2,p1);
		}
		else if(p4==0){
			printf("%d%d%d",p3,p2,p1);
		}
		else{
			printf("%d%d%d%d",p4,p3,p2,p1);
		}
	}
	else if(n>=100000 && n<1000000){
		a=n%10;
		b=(n/10)%10;
		c=(n/100)%10;
		d=(n/1000)%10;
		e=(n/10000)%10;
		f=n/100000;
		x1=a-b;
		x2=b-c;
		x3=c-d;
		x4=d-e;
		x5=e-f;
		p1=fabs(x1);
		p2=fabs(x2);
		p3=fabs(x3);
		p4=fabs(x4);
		p5=fabs(x5);
		if(p5==0 && p4==0 && p3==0 && p2==0){
			printf("%d",p1);
		}
		else if(p5==0 && p4==0 && p3==0){
			printf("%d%d",p2,p1);
		}
		else if(p5==0 && p4==0){
			printf("%d%d%d",p3,p2,p1);
		}
		else if(p5==0){
			printf("%d%d%d%d",p4,p3,p2,p1);
		}
		else{
			printf("%d%d%d%d%d",p5,p4,p3,p2,p1);
		}
	}
	else if(n>=1000000 && n<10000000){
		a=n%10;
		b=(n/10)%10;
		c=(n/100)%10;
		d=(n/1000)%10;
		e=(n/10000)%10;
		f=(n/100000)%10;
		g=n/1000000;
		x1=a-b;
		x2=b-c;
		x3=c-d;
		x4=d-e;
		x5=e-f;
		x6=f-g;
		p1=fabs(x1);
		p2=fabs(x2);
		p3=fabs(x3);
		p4=fabs(x4);
		p5=fabs(x5);
		p6=fabs(x6);
		if(p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
			printf("%d",p1);
		}
		else if(p6==0 && p5==0 && p4==0 && p3==0){
			printf("%d%d",p2,p1);
		}
		else if(p6==0 && p5==0 && p4==0){
			printf("%d%d%d",p3,p2,p1);
		}
		else if(p6==0 && p5==0){
			printf("%d%d%d%d",p4,p3,p2,p1);
		}
		else if(p6==0){
			printf("%d%d%d%d%d",p5,p4,p3,p2,p1);
		}
		else{
			printf("%d%d%d%d%d%d",p6,p5,p4,p3,p2,p1);
		}
	}
	else if(n>=10000000 && n<100000000){
		a=n%10;
		b=(n/10)%10;
		c=(n/100)%10;
		d=(n/1000)%10;
		e=(n/10000)%10;
		f=(n/100000)%10;
		g=(n/1000000)%10;
		h=n/10000000;
		x1=a-b;
		x2=b-c;
		x3=c-d;
		x4=d-e;
		x5=e-f;
		x6=f-g;
		x7=g-h;
		p1=fabs(x1);
		p2=fabs(x2);
		p3=fabs(x3);
		p4=fabs(x4);
		p5=fabs(x5);
		p6=fabs(x6);
		p7=fabs(x7);
		if(p7==0 && p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
			printf("%d",p1);
		}
		else if(p7==0 && p6==0 && p5==0 && p4==0 && p3==0){
			printf("%d%d",p2,p1);
		}
		else if(p7==0 && p6==0 && p5==0 && p4==0){
			printf("%d%d%d",p3,p2,p1);
		}
		else if(p7==0 && p6==0 && p5==0){
			printf("%d%d%d%d",p4,p3,p2,p1);
		}
		else if(p7==0 && p6==0){
			printf("%d%d%d%d%d",p5,p4,p3,p2,p1);
		}
		else if(p7==0){
			printf("%d%d%d%d%d%d",p6,p5,p4,p3,p2,p1);
		}
		else{
			printf("%d%d%d%d%d%d%d",p7,p6,p5,p4,p3,p2,p1);
		}
	}
	else if(n>=100000000 && n<1000000000){
		a=n%10;
		b=(n/10)%10;
		c=(n/100)%10;
		d=(n/1000)%10;
		e=(n/10000)%10;
		f=(n/100000)%10;
		g=(n/1000000)%10;
		h=(n/10000000)%10;
		i=n/100000000;
		x1=a-b;
		x2=b-c;
		x3=c-d;
		x4=d-e;
		x5=e-f;
		x6=f-g;
		x7=g-h;
		x8=h-i;
		p1=fabs(x1);
		p2=fabs(x2);
		p3=fabs(x3);
		p4=fabs(x4);
		p5=fabs(x5);
		p6=fabs(x6);
		p7=fabs(x7);
		p8=fabs(x8);
		if(p8==0 && p7==0 && p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
			printf("%d",p1);
		}
		else if(p8==0 && p7==0 && p6==0 && p5==0 && p4==0 && p3==0){
			printf("%d%d",p2,p1);
		}
		else if(p8==0 && p7==0 && p6==0 && p5==0 && p4==0){
			printf("%d%d%d",p3,p2,p1);
		}
		else if(p8==0 && p7==0 && p6==0 && p5==0){
			printf("%d%d%d%d",p4,p3,p2,p1);
		}
		else if(p8==0 && p7==0 && p6==0){
			printf("%d%d%d%d%d",p5,p4,p3,p2,p1);
		}
		else if(p8==0 && p7==0){
			printf("%d%d%d%d%d%d",p6,p5,p4,p3,p2,p1);
		}
		else if(p8==0){
			printf("%d%d%d%d%d%d%d",p7,p6,p5,p4,p3,p2,p1);
		}
		else{
			printf("%d%d%d%d%d%d%d%d",p8,p7,p6,p5,p4,p3,p2,p1);
		}
	}
	else if(n>0 && n<10){
		printf("0");
	}
	else if(n<0){
		t=fabs(n);
		if(t<10){
			printf("0");
		}
		else if(t>=10 && t<100){
			a=t%10;
			b=t/10;
			x1=a-b;
			p1=fabs(x1);
			printf("%d",p1);
		}
		else if(t>=100 && t<1000){
			a=t%10;
			b=(t/10)%10;
			c=t/100;
			x1=a-b;
			x2=b-c;
			p1=fabs(x1);
			p2=fabs(x2);
			if(p2==0){
				printf("%d",p1);
			}
			else{
				printf("%d%d",p2,p1);
			}
		}
		else if(t>=1000 && t<10000){
			a=t%10;
			b=(t/10)%10;
			c=(t/100)%10;
			d=t/1000;
			x1=a-b;
			x2=b-c;
			x3=c-d;
			p1=fabs(x1);
			p2=fabs(x2);
			p3=fabs(x3);
			if(p3==0 && p2==0){
				printf("%d",p1);
			}
			else if(p3==0){
				printf("%d%d",p2,p1);
			}
			else{
				printf("%d%d%d",p3,p2,p1);
			}
		}
		else if(t>=10000 && t<100000){
			a=t%10;
			b=(t/10)%10;
			c=(t/100)%10;
			d=(t/1000)%10;
			e=t/10000;
			x1=a-b;
			x2=b-c;
			x3=c-d;
			x4=d-e;
			p1=fabs(x1);
			p2=fabs(x2);
			p3=fabs(x3);
			p4=fabs(x4);
			if(p4==0 && p3==0 && p2==0){
				printf("%d",p1);
			}
			else if(p4==0 && p3==0){
				printf("%d%d",p2,p1);
			}
			else if(p4==0){
				printf("%d%d%d",p3,p2,p1);
			}
			else{
				printf("%d%d%d%d",p4,p3,p2,p1);
			}
			
		}
		else if(t>=100000 && t<1000000){
			a=t%10;
			b=(t/10)%10;
			c=(t/100)%10;
			d=(t/1000)%10;
			e=(t/10000)%10;
			f=t/100000;
			x1=a-b;
			x2=b-c;
			x3=c-d;
			x4=d-e;
			x5=e-f;
			p1=fabs(x1);
			p2=fabs(x2);
			p3=fabs(x3);
			p4=fabs(x4);
			p5=fabs(x5);
			if(p2==0 && p3==0 && p4==0 && p5==0){
				printf("%d",p1);
			}
			else if(p5==0 && p4==0 && p3==0){
				printf("%d%d",p2,p1);
			}
			else if(p5==0 && p4==0){
				printf("%d%d%d",p5,p4,p3);
			}
			else if(p5==0){
				printf("%d%d%d%d",p4,p3,p2,p1);
			}
			else{
				printf("%d%d%d%d%d",p5,p4,p3,p2,p1);
			}
		}
		else if(t>=1000000 && t<10000000){
			a=t%10;
			b=(t/10)%10;
			c=(t/100)%10;
			d=(t/1000)%10;
			e=(t/10000)%10;
			f=(t/100000)%10;
			g=t/1000000;
			x1=a-b;
			x2=b-c;
			x3=c-d;
			x4=d-e;
			x5=e-f;
			x6=f-g;
			p1=fabs(x1);
			p2=fabs(x2);
			p3=fabs(x3);
			p4=fabs(x4);
			p5=fabs(x5);
			p6=fabs(x6);
			if(p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
				printf("%d",p1);
			}
			else if(p6==0 && p5==0 && p4==0 && p3==0){
				printf("%d%d",p2,p1);
			}
			else if(p6==0 && p5==0 && p4==0){
				printf("%d%d%d",p3,p2,p1);
			}
			else if(p6==0 && p5==0){
				printf("%d%d%d%d",p4,p3,p2,p1);
			}
			else if(p6==0){
				printf("%d%d%d%d%d",p5,p4,p3,p2,p1);
			}
			else{
				printf("%d%d%d%d%d%d",p6,p5,p4,p3,p2,p1);
			}
		}
		else if(t>=10000000 && t<100000000){
			a=t%10;
			b=(t/10)%10;
			c=(t/100)%10;
			d=(t/1000)%10;
			e=(t/10000)%10;
			f=(t/100000)%10;
			g=(t/1000000)%10;
			h=t/10000000;
			x1=a-b;
			x2=b-c;
			x3=c-d;
			x4=d-e;
			x5=e-f;
			x6=f-g;
			x7=g-h;
			p1=fabs(x1);
			p2=fabs(x2);
			p3=fabs(x3);
			p4=fabs(x4);
			p5=fabs(x5);
			p6=fabs(x6);
			p7=fabs(x7);
			if(p7==0 && p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
				printf("%d",p1);
			}
			else if(p7==0 && p6==0 && p5==0 && p4==0 && p3==0){
				printf("%d%d",p2,p1);
			}
			else if(p7==0 && p6==0 && p5==0 && p4==0){
				printf("%d%d%d",p3,p2,p1);
			}
			else if(p7==0 && p6==0 && p5==0){
				printf("%d%d%d%d",p4,p3,p2,p1);
			}
			else if(p7==0 && p6==0){
				printf("%d%d%d%d%d",p5,p4,p3,p2,p1);
			}
			else if(p7==0){
				printf("%d%d%d%d%d%d",p6,p5,p4,p3,p2,p1);
			}
			else{
				printf("%d%d%d%d%d%d%d",p7,p6,p5,p4,p3,p2,p1);
			}
		}
	}
	return 0;

}
