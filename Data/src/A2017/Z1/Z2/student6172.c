#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265359
int main() {
	double x1,x2,x3,y1,y2,y3,a,b,c,p,alfa,beta,gama,najveci=0,ugaoustep,minute1,sekunde1,urad90;
	int stepeni,minute,sekunde;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	p=(1./2)*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	
		urad90=PI/2;
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	if(fabs(p-0)<EPSILON){
	printf("Linija\n");
	
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
		return 0;
	}
		
	
	//Ispituje se je li jednakostranicni
	else if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON && fabs(c-a)<EPSILON){
	printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
		return 0;
	}
	//Ispituje se je li jednakokraki i provjerava se je li trougao ujedno i pravougli 
	else if(fabs(a-b)<EPSILON || fabs(b-c)<EPSILON || fabs(c-a)<EPSILON){
	
		if((fabs(alfa-urad90)<=EPSILON) || (fabs(beta-(urad90))<=EPSILON) || (fabs(gama-urad90)<=EPSILON))
		printf("Pravougli\n");
		
		printf("Jednakokraki\n");
	}
	else {
		if((fabs(alfa-urad90)<=EPSILON) || (fabs(beta-(urad90))<=EPSILON) || (fabs(gama-urad90)<=EPSILON))
		printf("Pravougli\n");
		printf("Raznostranicni\n");
	}
	//Ispituje se najveci ugao
	if(alfa>beta && alfa>gama)
	najveci=alfa;
	else if(beta>alfa &&beta>gama)
	najveci=beta;
	else if(gama>alfa && gama>beta)
	najveci=gama;
	//Vrsi se pretvaranje vrijednosti ugla iz radijana u stepene,minute i sekunde
	ugaoustep=najveci*(180./PI);
	stepeni=ugaoustep;
	minute1=(ugaoustep-stepeni)*60;
	if(fabs(minute1-60)<EPSILON){
		stepeni=stepeni+1;
		minute1=0;
	
	}
minute=minute1;

	sekunde1=(minute1-minute)*60;
	
	if(fabs(sekunde1-60)<EPSILON){
	minute=minute+1;
	sekunde1=0;
	
	}
	
	sekunde=sekunde1;
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	
	
	
	return 0;
}
