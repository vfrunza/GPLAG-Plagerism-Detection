#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.141592653
int main() {
	double x1,y1,x2,y2,x3,y3;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	double a,b,c;
	a=sqrt(pow(x1-x2,2)+ pow(y1-y2,2));
	b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	c=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	double najveca,srednja,najmanja;
	if(a>=b && b>=c){
		najveca=a;
		srednja=b;
		najmanja=c;
	}
	else if(a>=c && c>=b){
		najveca=a;
		srednja=c;
		najmanja=b;
	}
	else if(b>=a && a>=c){
		najveca=b;
		srednja=a;
		najmanja=c;
	}
	else if(b>=c && c>=a){
		najveca=b;
		srednja=c;
		najmanja=a;
	}
	else if(c>=a && a>=b){
		najveca=c;
		srednja=a;
		najmanja=b;
	}
	else {
		najveca=c;
		srednja=b;
		najmanja=a;
	}
	
	
	double ugao1,ugao2,ugao3,ugao_max;
	ugao1=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
	ugao2=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
	ugao3=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
	
	if(ugao1>ugao2 && ugao2>ugao3){
		ugao_max=ugao1;
	}
	else if(ugao2>ugao1 && ugao1>ugao3){
		ugao_max=ugao2;
	}
	else{
		ugao_max=ugao3;
	}
	ugao_max=(ugao_max)*(180/PI);
	
	int stepeni,minute,sekunde;
	stepeni=(int)(ugao_max);
	minute=(int)((ugao_max-stepeni)*60);
	sekunde=(int)(((ugao_max-stepeni)*60-minute)*60);

if(stepeni==180){
	printf("Linija");
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	return 0;
}
if(fabs(pow(najveca,2)-pow(srednja,2)-pow(najmanja,2))<=e) {
	printf("Pravougli\n");
}
if(fabs(a-b)<=e && fabs(a-c)<=e && fabs(b-c)<=e){
	printf("Jednakostranicni\n");
}
else if(fabs(a-b)<e || fabs(b-c)<e || fabs(c-a)<e){
	printf("Jednakokraki\n");
}
else{	
	printf("Raznostranicni\n");
}

printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	
	
	
	return 0;
}
