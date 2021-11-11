#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265

int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,alfa,alfa1,alfa2,alfa3,beta,beta1,beta2,beta3,gama,gama1,gama2,gama3;
	int stepen_alfa,stepen_beta,stepen_gama,minuta_alfa,minuta_beta,minuta_gama,sekundi_alfa,sekundi_beta,sekundi_gama;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
	b=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	c=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	alfa=acos((b*b+c*c-a*a)/(2*b*c)); alfa1=((alfa*180)/PI);  
	beta=acos((a*a+c*c-b*b)/(2*a*c)); beta1=((beta*180)/PI);
	gama=acos((a*a+b*b-c*c)/(2*a*b)); gama1=((gama*180)/PI);
	stepen_alfa=(int)alfa1; alfa2=((alfa1-stepen_alfa)*60);
	minuta_alfa=(int)alfa2; alfa3=((alfa2-minuta_alfa)*60);
	sekundi_alfa=(int)alfa3;
	stepen_beta=(int)beta1; beta2=((beta1-stepen_beta)*60);
	minuta_beta=(int)beta2; beta3=((beta2-minuta_beta)*60);
	sekundi_beta=(int)beta3;
	stepen_gama=(int)gama1; gama2=((gama1-stepen_gama)*60);
	minuta_gama=(int)gama2; gama3=((gama2-minuta_gama)*60);
	sekundi_gama=(int)gama3;

	if(fabs(a-c)<EPSILON && fabs(b-c)<EPSILON && fabs(a-b)<EPSILON){
		printf("Jednakostranicni\n");
		if(alfa1>beta1 && alfa1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_alfa,minuta_alfa,sekundi_alfa); 
		}
		else if(beta1>alfa1 && beta1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_beta,minuta_beta,sekundi_beta); 
		}
		else if(gama1>alfa1 && gama1>beta1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_gama,minuta_gama,sekundi_gama); 
		}
	}
	else if((c>a && c>b && fabs(c*c-(a*a+b*b))<EPSILON && a!=b)||(b>a && b>c && fabs(b*b-(a*a+c*c))<EPSILON && a!=c)||(a>b && a>c && fabs(a*a-(b*b+c*c))<EPSILON && b!=c)){
		printf("Pravougli\n");
		printf("Raznostranicni\n");
		if(alfa1>beta1 && alfa1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_alfa,minuta_alfa,sekundi_alfa); 
		}
		else if(beta1>alfa1 && beta1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_beta,minuta_beta,sekundi_beta); 
		}
		else if(gama1>alfa1 && gama1>beta1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_gama,minuta_gama,sekundi_gama); 
		}
	}
	else if(fabs(c*c-(a*a+b*b)<EPSILON && fabs(a*a-b*b)<EPSILON)||(fabs(b*b-(a*a+c*c))<EPSILON && fabs(a-c)<EPSILON)||(fabs(a*a-(b*b+c*c)<EPSILON) && fabs(b*b-c*c)<EPSILON)){
		printf("Pravougli\n");
		printf("Jednakokraki\n");
		if(alfa1>beta1 && alfa1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_alfa,minuta_alfa,sekundi_alfa); 
		}
		else if(beta1>alfa1 && beta1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_beta,minuta_beta,sekundi_beta); 
		}
		else if(gama1>alfa1 && gama1>beta1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_gama,minuta_gama,sekundi_gama); 
		}
	}
	else if((fabs(a-b)<EPSILON && b!=c && stepen_alfa!=180 && stepen_beta!=180 && stepen_gama!=180)||(fabs(a-c)<EPSILON && c!=b && stepen_alfa!=180 && stepen_beta!=180 && stepen_gama!=180)||(fabs(b-c)<EPSILON && c!=a && stepen_alfa!=180 && stepen_beta!=180 && stepen_gama!=180)){
		printf("Jednakokraki\n");
		if(alfa1>beta1 && alfa1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_alfa,minuta_alfa,sekundi_alfa); 
		}
		else if(beta1>alfa1 && beta1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_beta,minuta_beta,sekundi_beta); 
		}
		else if(gama1>alfa1 && gama1>beta1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_gama,minuta_gama,sekundi_gama); 
		}
	}
		else if(a!=b && b!=c && a!=c && stepen_alfa!=180 && stepen_beta!=180 && stepen_gama!=180){
			printf("Raznostranicni\n");
				if(alfa1>beta1 && alfa1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_alfa,minuta_alfa,sekundi_alfa); 
		}
		else if(beta1>alfa1 && beta1>gama1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_beta,minuta_beta,sekundi_beta); 
		}
		else if(gama1>alfa1 && gama1>beta1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_gama,minuta_gama,sekundi_gama); 
		}
		}
		else if(fabs(alfa1-180)<=EPSILON){
			printf("Linija\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_alfa,minuta_alfa,sekundi_alfa); 
		}
		else if(fabs(beta1-180)<=EPSILON){
			printf("Linija\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_beta,minuta_beta,sekundi_beta); 
		}
		else if(fabs(gama1-180)<=EPSILON){
			printf("Linija\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_gama,minuta_gama,sekundi_gama); 
		}
		else 
		return 0;
		}
	
