#include <stdio.h>
#define eps 0.0001
#include <math.h>
#define pi 3.14159265359
int main() {
	double x1,y1,x2,y2,x3,y3,a=0,b=0,c=0;
	double alfa=0,beta=0,gama=0;
	int alfa_s,beta_s,gama_s;
	double alfa1,beta1,gama1;
	int alfa_m,alfa_sek,beta_m,beta_sek,gama_m,gama_sek;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	a=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	c=sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
	alfa=(acos((b*b+c*c-a*a)/(2*b*c)));
	beta=(acos((a*a+c*c-b*b)/(2*a*c)));
	gama=(acos((a*a+b*b-c*c)/(2*a*b)));
	alfa1=alfa*(180/pi);
	beta1=beta*(180/pi);
	gama1=gama*(180/pi);
	

	if(fabs((a*a + b*b)-(c*c))<eps ){
		printf("Pravougli\n");
	} if(fabs(b-c)<eps){
		printf("Jednakokraki\n");
	} if(fabs(a-b)>eps && fabs(b-c)>eps){
		printf("Raznostranicni\n");
	} if(fabs(a-b)<eps && fabs(gama1-90)<eps){
	
		printf("Jednakokraki\n");
	}if(fabs(a-b)<eps && fabs(b-c)<eps){
		printf("Jednakostranicni\n");
	}
	if(alfa1>beta1 && alfa1>gama1){
		
		alfa_s=(int)(alfa1+0.5);
		alfa_m=(int)((alfa1-alfa_s)*3600)/60;
		alfa_sek=(int)((alfa1-alfa_s)*3600)%60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",alfa_s,alfa_m,alfa_sek);
	}else if(beta1>alfa1 && beta1>gama1){
		
		beta_s=(int)(beta1+0.5);
		beta_m=(int)((beta1-beta_s)*3600)/60;
		beta_sek=(int)((beta1-beta_s)*3600)%60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",beta_s,beta_m,beta_sek);
	}else if(gama1>alfa1 && gama1>beta1){
		
		gama_s=(int)(gama1+0.5);
		gama_m=(int)((gama1-gama_s)*3600)/60;
		gama_sek=(int)((gama1-gama_s)*3600)%60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",gama_s,gama_m,gama_sek);
	}
	return 0;
}
