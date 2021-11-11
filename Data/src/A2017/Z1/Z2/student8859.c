#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.1415926535
int main() {
	double x1, x2, x3, y1, y2, y3, d1, d2, d3, ugao, ugao1, ugao2, ugao3, p;
	int step, min ,sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	
	d1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	d2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	d3=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	
	if(d1<0) d1*=(-1);
	if(d2<0) d2*=(-1);
	if(d3<0) d3*=(-1);
	
	
	p=1.0/2*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	
	
	if(p==0){
	printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}
	else if(fabs(d1-d2)<epsilon && fabs(d2-d3)<epsilon) {
		printf("Jednakostranicni\n"); printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}
	else if(fabs(d1*d1 - d2*d2 - d3*d3)<epsilon || fabs(d2*d2 - d1*d1 - d3*d3)<epsilon || fabs(d3*d3 - d1*d1 - d2*d2)<epsilon) {
		printf("Pravougli\n");
		if(fabs(d1-d2)<epsilon || fabs(d2-d3)<epsilon || fabs(d1-d3)<epsilon) {printf("Jednakokraki\n");}
		else if(fabs(d1-d2)>=epsilon && fabs(d2-d3)>=epsilon && fabs(d1-d3)>=epsilon) {printf("Raznostranicni\n");}
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	} 
	else if(fabs(d1-d2)<epsilon || fabs(d2-d3)<epsilon || fabs(d1-d3)<epsilon) { 
		printf("Jednakokraki\n");
		
		ugao1=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3)); if(ugao1<0) ugao1*=(-1);
		ugao2=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3)); if(ugao2<0) ugao2*=(-1);
		ugao3=acos((d2*d2+d1*d1-d3*d3)/(2*d2*d1)); if(ugao3<0) ugao3*=(-1);
		
		if(ugao1>=ugao2 &&  ugao1>=ugao3) ugao=ugao1;
		else if(ugao2>=ugao1 &&  ugao2>=ugao3) ugao=ugao2;
		else if(ugao3>=ugao2 &&  ugao3>=ugao1) ugao=ugao3;
		
		ugao=ugao*180/PI;
		
		step=ugao;
		min=(ugao-step)*60;
		sec=((ugao-step)*60 - min)*60;
		
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sec);
	}
	else if(fabs(d1-d2)>=epsilon && fabs(d2-d3)>=epsilon && fabs(d1-d3)>=epsilon) {
		printf("Raznostranicni\n");
		
		ugao1=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3)); if(ugao1<0) ugao1*=(-1);
		ugao2=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3)); if(ugao2<0) ugao2*=(-1);
		ugao3=acos((d2*d2+d1*d1-d3*d3)/(2*d2*d1)); if(ugao3<0) ugao3*=(-1);
		
		if(ugao1>=ugao2 &&  ugao1>=ugao3) ugao=ugao1;
		else if(ugao2>=ugao1 &&  ugao2>=ugao3) ugao=ugao2;
		else if(ugao3>=ugao2 &&  ugao3>=ugao1) ugao=ugao3;
		
		ugao=ugao*180/PI;
		
		step=ugao;
		min=(ugao-step)*60;
		sec=((ugao-step)*60 - min)*60;
		
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sec);
	}

	
	

	return 0;
}
