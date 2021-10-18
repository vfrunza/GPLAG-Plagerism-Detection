#include <stdio.h>
#include <math.h>
#define pi 3.14
int main() {
	double x1,x2,x3,y1,y2,y3,a,b,c,s,P,alfa,beta,gama,veci,stepen,min,sek;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);	
	
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); /*Stranica a, tacke t1 i t2*/
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)); /*Starnica b, tacke t2 i t3*/
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)); /*Starnica c, tacke t3 i t1*/
	
	s=(a+b+c)/2;
	P=sqrt(s*(s-a)*(s-b)*(s-c));
	if(P==0){
		 printf("Linija");
		 printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		 return 0;
	}
	
	if(c==sqrt((a*a)+(b*b)) || b==sqrt((a*a)+(c*c)) || a==sqrt((c*c)+(b*b))) printf("Pravougli\n");
	if((a!=b) && (b!=c) && (a!=c)) printf ("Raznostranicni\n");
	else if((a==b) && (b==c)) printf("Jednakostranicni\n");
	else if(((a==b) && (a!=c)) || ((b==c) && (b!=a)) || ((c==a) && (c!=b))) printf("Jednakokraki\n");
	
	alfa=acos(((c*c)+(b*b)-(a*a))/(2*b*c));
	beta=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
	gama=acos(((a*a)+(b*b)-(c*c))/(2*a*b));
	
	alfa=(alfa*180)/pi;
	beta=(beta*180)/pi;
	gama=(gama*180)/pi;
	
	veci=alfa;
	if(beta>veci) veci=beta;
	if(gama>veci) veci=gama;
	
	stepen=(int)veci;
	min=(int)(veci-stepen)*60;
	sek=(min-(int)min)*60;
	
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",stepen,min,sek);
	
	return 0;
}
