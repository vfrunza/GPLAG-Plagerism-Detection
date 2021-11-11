#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define eps 0.0001
int main() {
	double x1,y1,x2,x3,y2,y3,a,b,c,val,a1,d,e,f,g,b1,d1,e1,f1,g1,c1,d2,e2,f2,g2,h,h1,h2,i,i1,i2,j12,j13; //d12=a; d23=b; d13=c;e(stepen),f(minuta),g(sekunda)
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf",&x1);
	scanf("%lf",&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf",&x2);
	scanf("%lf",&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf",&x3);
	scanf("%lf",&y3);
	a=sqrt((pow(x2-x1,2)) + (pow(y2-y1,2)));
	c=sqrt((pow(x3-x1,2)) + (pow(y3-y1,2)));
	b=sqrt((pow(x3-x2,2)) + (pow(y3-y2,2)));
	val=180/PI;
	a1=((b*b)+(c*c)-(a*a))/(2*b*c);
	d=acos(a1)*val;
	e=(int)d;
	f=(d-e)*60;
	g=(int)f;
	h=(f-g)*60;
	i=(int)h;
	b1=((a*a)+(c*c)-(b*b))/(2*b*c);
	d1=acos(b1)*val;
	e1=(int)d1;
	f1=(d1-e1)*60;
	g1=(int)f1;
	h1=(f1-g1)*60;
	i1=(int)h1;
	c1=((a*a)+(b*b)-(c*c))/(2*a*b);
	d2=acos(c1)*val;
	e2=(int)d2;
	f2=(d2-e2)*60;
	g2=(int)f2;
	h2=(f2-g2)*60;
	i2=(int)h2;
    j12=(y2-y1)/(x2-x1);
    j13=(y1-y3)/(x1-x3);
if((fabs(j13-j12)<eps)){printf("Linija\n");}
else if(((e==90) || (e1==90) || (e2==90)) &&((a!=b) && (a!=c) && (b!=c))){
	printf("Pravougli\n");
	printf("Raznostranicni\n");}
else if(((e==90) || (e1==90) || (e2==90)) && ((fabs(a-b)<eps) || (fabs(c-a)<eps) || (fabs(c-b)<eps))){
	printf("Pravougli\n");
	printf("Jednakokraki\n");}
 else if((fabs(a-b)<eps) && (fabs(c-a)<eps) && (fabs(c-b)<eps)){printf("Jednakostranicni\n");}
 else if((fabs(a-b)<eps) || (fabs(c-a)<eps) || (fabs(c-a)<eps)){printf("Jednakokraki\n");}
 else if((a!=b) && (b!=c) && (a!=c)){printf("Raznostranicni\n");}
 if((a1<b1) && (a1<c1)){printf("Najveci ugao ima %.0lf stepeni, %.0lf minuta i %.0lf sekundi.\n",e,g,i);}
 if((b1<a1) && (b1<c1)){printf("Najveci ugao ima %.0lf stepeni, %.0lf minuta i %.0lf sekundi.\n",e1,g1,i1);}
 if((c1<a1) && (c1<b1)){printf("Najveci ugao ima %.0lf stepeni, %.0lf minuta i %.0lf sekundi.\n",e2,g2,i2);}

return 0;
	
}
