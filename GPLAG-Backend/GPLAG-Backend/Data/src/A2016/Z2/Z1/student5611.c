#include <stdio.h>
#include <math.h>

int main() {
	int n,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,t=0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n==0){
		printf("0");
	}
	else if(n<=-1){
		t=fabs(n);
		if(t<=9){
			printf("0");
		}
		else if(t>9 && t<100){
			a=t%10;
			b=t/10;
			
			p1=fabs(a-b);
			printf("%d", p1);
		}	
		else if(t>99 && t<1000){
			a=t%10;
			b=(t%100)/10;
			c=t/100;
		
			p1=fabs(a-b);
			p2=fabs(b-c);
			if(p2==0){
				printf("%d", p1);
			}
			else{
				printf("%d%d", p2,p1);
			}
		}
		else if(t>999 && t<10000){
			a=t%10;
			b=(t%100)/10;
			c=(t%1000)/100;
			d=t/1000;
		
			p1=fabs(a-b);
			p2=fabs(b-c);
			p3=fabs(c-d);
			if(p3==0 && p2==0){
				printf("%d", p1);
			}
			else if(p3==0){
				printf("%d%d", p2,p1);
			}
			else{
				printf("%d%d%d", p3,p2,p1);
			}
		}
		else if(t>9999 && t<100000){
			a=t%10;
			b=(t%100)/10;
			c=(t%1000)/100;
			d=(t%10000)/1000;
			e=t/10000;
		
			p1=fabs(a-b);
			p2=fabs(b-c);
			p3=fabs(c-d);
			p4=fabs(d-e);
			if(p4==0 && p3==0 && p2==0){
				printf("%d", p1);
			}
			else if(p4==0 && p3==0){
				printf("%d%d", p2,p1);
			}
			else if(p4==0){
				printf("%d%d%d", p3,p2,p1);
			}
			else{
				printf("%d%d%d%d", p4,p3,p2,p1);
			}
		}
		else if(t>99999 && t<1000000){
			a=t%10;
			b=(t%100)/10;
			c=(t%1000)/100;
			d=(t%10000)/1000;
			e=(t%100000)/10000;
			f=t/100000;
		
			p1=fabs(a-b);
			p2=fabs(b-c);
			p3=fabs(c-d);
			p4=fabs(d-e);
			p5=fabs(e-f);
			if(p2==0 && p3==0 && p4==0 && p5==0){
				printf("%d", p1);
			}
			else if(p5==0 && p4==0 && p3==0){
				printf("%d%d", p2,p1);
			}
			else if(p5==0 && p4==0){
				printf("%d%d%d", p5,p4,p3);
			}
			else if(p5==0){
				printf("%d%d%d%d", p4,p3,p2,p1);
			}
			else{
				printf("%d%d%d%d%d", p5,p4,p3,p2,p1);
			}
		}
		else if(t>999999 && t<10000000){
			a=t%10;
			b=(t%100)/10;
			c=(t%1000)/100;
			d=(t%10000)/1000;
			e=(t%100000)/10000;
			f=(t%1000000)/100000;
			g=t/1000000;
		
			p1=fabs(a-b);
			p2=fabs(b-c);
			p3=fabs(c-d);
			p4=fabs(d-e);
			p5=fabs(e-f);
			p6=fabs(f-g);
			if(p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
				printf("%d", p1);
			}
			else if(p6==0 && p5==0 && p4==0 && p3==0){
				printf("%d%d", p2,p1);
			}
			else if(p6==0 && p5==0 && p4==0){
				printf("%d%d%d", p3,p2,p1);
			}
			else if(p6==0 && p5==0){
				printf("%d%d%d%d", p4,p3,p2,p1);
			}
			else if(p6==0){
				printf("%d%d%d%d%d", p5,p4,p3,p2,p1);
			}
			else{
				printf("%d%d%d%d%d%d", p6,p5,p4,p3,p2,p1);
			}
		}
		else if(t>9999999 && t<100000000){
			a=t%10;
			b=(t%100)/10;
			c=(t%1000)/100;
			d=(t%10000)/1000;
			e=(t%100000)/10000;
			f=(t%1000000)/100000;
			g=(t%10000000)/1000000;
			h=t/10000000;
		
			p1=fabs(a-b);
			p2=fabs(b-c);
			p3=fabs(c-d);
			p4=fabs(d-e);
			p5=fabs(e-f);
			p6=fabs(f-g);
			p7=fabs(g-h);
			if(p7==0 && p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
				printf("%d", p1);
			}
			else if(p7==0 && p6==0 && p5==0 && p4==0 && p3==0){
				printf("%d%d", p2,p1);
			}
			else if(p7==0 && p6==0 && p5==0 && p4==0){
				printf("%d%d%d", p3,p2,p1);
			}
			else if(p7==0 && p6==0 && p5==0){
				printf("%d%d%d%d", p4,p3,p2,p1);
			}
			else if(p7==0 && p6==0){
				printf("%d%d%d%d%d", p5,p4,p3,p2,p1);
			}
			else if(p7==0){
				printf("%d%d%d%d%d%d", p6,p5,p4,p3,p2,p1);
			}
			else{
				printf("%d%d%d%d%d%d%d", p7,p6,p5,p4,p3,p2,p1);
			}
		}
	}	
	else if(n>9 && n<=99){
		a=n%10;
		b=n/10;
		
		p1=fabs(a-b);
		printf("%d", p1);
	}
	else if(n>99 && n<1000){
		a=n%10;
		b=(n%100)/10;
		c=n/100;
		
		p1=fabs(a-b);
		p2=fabs(b-c);
		if(p2==0){
			printf("%d", p1);
		}
		else{
			printf("%d%d", p2,p1);
		}
	}
	else if(n>999 && n<10000){
		a=n%10;
		b=(n%100)/10;
		c=(n%1000)/100;
		d=n/1000;
		
		p1=fabs(a-b);
		p2=fabs(b-c);
		p3=fabs(c-d);
		if(p3==0 && p2==0){
			printf("%d", p1);
		}
		else if(p3==0){
			printf("%d%d", p2,p1);
		}
		else{
			printf("%d%d%d", p3,p2,p1);
		}
	}
	else if(n>9999 && n<100000){
		a=n%10;
		b=(n%100)/10;
		c=(n%1000)/100;
		d=(n%10000)/1000;
		e=n/10000;
		
		p1=fabs(a-b);
		p2=fabs(b-c);
		p3=fabs(c-d);
		p4=fabs(d-e);
		if(p4==0 && p3==0 && p2==0){
			printf("%d", p1);
		}
		else if(p4==0 && p3==0){
			printf("%d%d", p2,p1);
		}
		else if(p4==0){
			printf("%d%d%d", p3,p2,p1);
		}
		else{
			printf("%d%d%d%d", p4,p3,p2,p1);
		}
	}
	else if(n>99999 && n<1000000){
		a=n%10;
		b=(n%100)/10;
		c=(n%1000)/100;
		d=(n%10000)/1000;
		e=(n%100000)/10000;
		f=n/100000;
		
		p1=fabs(a-b);
		p2=fabs(b-c);
		p3=fabs(c-d);
		p4=fabs(d-e);
		p5=fabs(e-f);
		if(p5==0 && p4==0 && p3==0 && p2==0){
			printf("%d", p1);
		}
		else if(p5==0 && p4==0 && p3==0){
			printf("%d%d", p2,p1);
		}
		else if(p5==0 && p4==0){
			printf("%d%d%d", p3,p2,p1);
		}
		else if(p5==0){
			printf("%d%d%d%d", p4,p3,p2,p1);
		}
		else{
			printf("%d%d%d%d%d", p5,p4,p3,p2,p1);
		}
	}
	else if(n>999999 && n<10000000){
		a=n%10;
		b=(n%100)/10;
		c=(n%1000)/100;
		d=(n%10000)/1000;
		e=(n%100000)/10000;
		f=(n%1000000)/100000;
		g=n/1000000;
		
		p1=fabs(a-b);
		p2=fabs(b-c);
		p3=fabs(c-d);
		p4=fabs(d-e);
		p5=fabs(e-f);
		p6=fabs(f-g);
		if(p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
			printf("%d", p1);
		}
		else if(p6==0 && p5==0 && p4==0 && p3==0){
			printf("%d%d", p2,p1);
		}
		else if(p6==0 && p5==0 && p4==0){
			printf("%d%d%d", p3,p2,p1);
		}
		else if(p6==0 && p5==0){
			printf("%d%d%d%d", p4,p3,p2,p1);
		}
		else if(p6==0){
			printf("%d%d%d%d%d", p5,p4,p3,p2,p1);
		}
		else{
			printf("%d%d%d%d%d%d", p6,p5,p4,p3,p2,p1);
		}
	}
	else if(n>9999999 && n<100000000){
		a=n%10;
		b=(n%100)/10;
		c=(n%1000)/100;
		d=(n%10000)/1000;
		e=(n%100000)/10000;
		f=(n%1000000)/100000;
		g=(n%10000000)/1000000;
		h=n/10000000;
		
		p1=fabs(a-b);
		p2=fabs(b-c);
		p3=fabs(c-d);
		p4=fabs(d-e);
		p5=fabs(e-f);
		p6=fabs(f-g);
		p7=fabs(g-h);
		if(p7==0 && p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
			printf("%d", p1);
		}
		else if(p7==0 && p6==0 && p5==0 && p4==0 && p3==0){
			printf("%d%d", p2,p1);
		}
		else if(p7==0 && p6==0 && p5==0 && p4==0){
			printf("%d%d%d", p3,p2,p1);
		}
		else if(p7==0 && p6==0 && p5==0){
			printf("%d%d%d%d", p4,p3,p2,p1);
		}
		else if(p7==0 && p6==0){
			printf("%d%d%d%d%d", p5,p4,p3,p2,p1);
		}
		else if(p7==0){
			printf("%d%d%d%d%d%d", p6,p5,p4,p3,p2,p1);
		}
		else{
			printf("%d%d%d%d%d%d%d", p7,p6,p5,p4,p3,p2,p1);
		}
	}
	else if(n>99999999 && n<1000000000){
		a=n%10;
		b=(n%100)/10;
		c=(n%1000)/100;
		d=(n%10000)/1000;
		e=(n%100000)/10000;
		f=(n%1000000)/100000;
		g=(n%10000000)/1000000;
		h=(n%100000000)/10000000;
		i=n/100000000;
		
		p1=fabs(a-b);
		p2=fabs(b-c);
		p3=fabs(c-d);
		p4=fabs(d-e);
		p5=fabs(e-f);
		p6=fabs(f-g);
		p7=fabs(g-h);
		p8=fabs(h-i);
		if(p8==0 && p7==0 && p6==0 && p5==0 && p4==0 && p3==0 && p2==0){
			printf("%d", p1);
		}
		else if(p8==0 && p7==0 && p6==0 && p5==0 && p4==0 && p3==0){
			printf("%d%d", p2,p1);
		}
		else if(p8==0 && p7==0 && p6==0 && p5==0 && p4==0){
			printf("%d%d%d", p3,p2,p1);
		}
		else if(p8==0 && p7==0 && p6==0 && p5==0){
			printf("%d%d%d%d", p4,p3,p2,p1);
		}
		else if(p8==0 && p7==0 && p6==0){
			printf("%d%d%d%d%d", p5,p4,p3,p2,p1);
		}
		else if(p8==0 && p7==0){
			printf("%d%d%d%d%d%d", p6,p5,p4,p3,p2,p1);
		}
		else if(p8==0){
			printf("%d%d%d%d%d%d%d", p7,p6,p5,p4,p3,p2,p1);
		}
		else{
			printf("%d%d%d%d%d%d%d%d", p8,p7,p6,p5,p4,p3,p2,p1);
		}
	}
	else if(n>=1 && n<=9){
		printf("0");
	}
	return 0;
}
