#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define pi 3.14159
int main() {
double x1, y1, x2, y2, x3, y3, a, b, c, l = 0, be = 0, g = 0, maxUgao = 0,stepenip,minutep,sekundep,stepeni,minute,sekunde;
int Linija = 0, Pravougli=0, Jednakostranicni=0; 

printf("Unesite koordinate tacke t1: ");
scanf("%lf %lf", &x1,&x2);
printf("Unesite koordinate tacke t2: ");
scanf("%lf %lf", &x2,&y2);
printf("Unesite koordinate tacke t3: ");
scanf("%lf %lf", &x3,&y3);

a=sqrt(((x3-x2)*(x3-x2))+(y3-y2)*(y3-y2));
b=sqrt(((x3-x1)*(x3-x1))+(y3-y1)*(y3-y1));
c=sqrt(((x2-x1)*(x2-x1))+(y2-y1)*(y2-y1));

if(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))+sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))-sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))<=eps*(fabs((sqrt(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))+sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)))+fabs(sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))))){
	printf("Linija\n");

	Linija=1;
}
else{
	if (fabs(c*c-a*a-b*b)<eps || fabs(a*a-b*b-c*c)<eps || fabs(b*b-a*a-c*c)<eps){
		printf("Pravougli\n");
		Pravougli=1;
	}
	if(fabs(a-b)<eps && fabs(b-c)<eps && fabs(a-c)<eps ){
		printf("n\Jednakostranicni");
		Jednakostranicni=1;
	}
	else if((fabs(a-b)<eps && b!=c) || (fabs(b-c)<eps && b!=a) || (fabs(a-c)<eps && c!=b)) 
	printf("Jednakokraki");
	

else if(a!=b && a!=c && b!=c)
	printf("Raznostranicni");
	
}
if (Linija) printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
else if(Pravougli) printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
else if (Jednakostranicni) printf("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
else {
	l=acos((b*b+c*c-a*a)/(2*b*c));
	be=acos((a*a+c*c-b*b)/(2*a*c));
	g=acos((a*a+b*b-c*c)/(2*a*b));
	
	maxUgao=l;
	if(be>maxUgao) maxUgao=be;
	else if(g>maxUgao) maxUgao=g;
	
	stepenip=(maxUgao*180)/pi;
	stepeni=(int)stepenip;
	minutep=(stepenip-stepeni)*60;
	minute=(int)minutep;
	sekundep=(minutep-minute)*60;
	sekunde=(int)sekundep;
	
printf("\nNajveci ugao ima %g stepeni, %g minuta i %g sekundi.", stepeni, minute, sekunde);
}
return 0;
}















