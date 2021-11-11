#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.14159
#include <stdlib.h>
int main() {
	double x1,y1,x2,y2,x3,y3,d1,d2,d3,A,B,C,ugao,od,step=0,min=0,sec=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	
	d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	d3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

	C=sqrt(pow(d1,2)+pow(d2,2)); A=sqrt(pow(d2,2)+pow(d3,2)); B=sqrt(pow(d1,2)+pow(d3,3));
	
	if (fabs(d1-d2)<epsilon && fabs(d1-d3)<epsilon && fabs(d2-d3)<epsilon){
		printf("Jednakostranicni\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
		return 0;}
		
	if ((fabs(C-d3)<epsilon || fabs(B-d2)<epsilon || fabs(A-d1)<epsilon)){
		printf("Pravougli\n");}
		
		if ((fabs(((x2-x1)/(x3-x1))-((y2-y1)/(y3-y1))))<epsilon){                    
			printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");return 0;}
		else if((fabs(y2-y1))<epsilon && (fabs(y3-y2))<epsilon && (fabs(y3-y1))<epsilon){
				printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");return 0;}
		else if((fabs(x2-x1))<epsilon && (fabs(x3-x2))<epsilon && (fabs(x3-x1))<epsilon){
		printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");return 0;}
		
		
		if ((fabs(d1-d2)>epsilon) && (fabs(d1-d3))>epsilon){
		od=((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
		ugao=((acos(od))*(180/PI));
		step=(int)ugao;
		min=(int)((ugao-step)*60);
		sec=(int)((((ugao-step)*60)-min)*60);}
		
		if (d2>d3 && d2>d1){
		od=((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
		ugao=((acos(od))*(180/PI));
		step=(int)ugao;
		min=(int)((ugao-step)*60);
		sec=(int)((((ugao-step)*60)-min)*60);}
		
		if (d3>d1 && d3>d2){
		od=((d1*d1+d2*d2-d3*d3)/(2*d2*d1));
		ugao=((acos(od))*(180/PI));
		step=(int)ugao;
		min=(int)((ugao-step)*60);
		sec=(int)((((ugao-step)*60)-min)*60);}
	
		
	if (((fabs(d1-d2)<epsilon && fabs(d1-d3)>epsilon) || (fabs(d1-d3)<epsilon && fabs(d1-d2)>epsilon) || (fabs(d2-d3)<epsilon && fabs(d2-d1)>epsilon ))){
		printf("Jednakokraki\n");
			if(step<90){
				printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",step,min,sec);
		return 0;}}
	
		if (d1>d2 && d1>d3){
		od=((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
		ugao=((acos(od))*(180/PI));
		step=(int)ugao;
		min=(int)((ugao-step)*60);
		sec=(int)((((ugao-step)*60)-min)*60);}
		
		if (d2>d3 && d2>d1){
		od=((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
		ugao=((acos(od))*(180/PI));
		step=(int)ugao;
		min=(int)((ugao-step)*60);
		sec=(int)((((ugao-step)*60)-min)*60);}
		
		if (d3>d1 && d3>d2){
		od=((d1*d1+d2*d2-d3*d3)/(2*d2*d1));
		ugao=((acos(od))*(180/PI));
		step=(int)ugao;
		min=(int)((ugao-step)*60);
		sec=(int)((((ugao-step)*60)-min)*60);}
		
	if ((fabs(d1-d2))>epsilon)  {
		printf("Raznostranicni\n");
		
		if(step>90){
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",step,min,sec);}}
		
	if ((fabs(C-d3)<epsilon) || (fabs(B-d2)<epsilon) || (fabs(A-d1)<epsilon)){
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
		return 0;}
		
			return 0;}
