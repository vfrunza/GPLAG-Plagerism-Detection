#include <stdio.h>
#include <math.h>
#define broj 500
#define pi 3.1415926

int main() {
	int i,u;
	double st,s,m,x,y,st1,m1,s1;
	int a,b,c,st2,m2,c1;
	double n[broj];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &u);
	
	printf("Uglovi su: \n");
	
	for(i=0; i<u; i++){
	scanf("%lf", &n[i]);
	
	
	st=n[i]*180/pi;
	st1=0.5+st;
	st2=(int)st1;
	a=(int)st;
	
	if(st1>st) st2=a; 

	x=st-(int)st; 
	
	m=x*60;
	m1=0.5+m;
	m2=(int)m1;
	b=fabs((int)m);
	
	if(m1>m) m2=b;
	
	y=m-(int)m;
	
	s=y*60;
	s1=round(s);
	c1=(int)s1;
	c=fabs(c1);
	

	if(c==60) {b++; c=0; }
	if(b==60 && a>0) {a++; b=0; c=0; }
	if(b==60 && a<0) {a--; b=0; c=0; }
	
	
	if(c<=30 && c>=0)
	printf("%d stepeni %d minuta %d sekundi \n", a,b,c);}
	
	
	return 0;
}
