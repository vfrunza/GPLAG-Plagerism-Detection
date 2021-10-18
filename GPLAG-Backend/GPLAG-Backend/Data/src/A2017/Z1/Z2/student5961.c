#include <stdio.h>
#include<math.h>
#define epsilon 0.0001
#define PI 3.14159

int main() {
	double x1,y1,x2,y2,x3,y3;

	double povrsina;
	double a,b,c,alfa,beta,gama;
	double s;
	int maxstep,maxmin,maxsek;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	a=sqrt((x1-x2)*(x1 - x2) + (y1-y2)*(y1-y2));
	b=sqrt((x1 - x3)*(x1 - x3) +(y1 - y3)*(y1 - y3));
	c=sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
	
	alfa=acos((pow(b,2)+ pow(c,2) - pow(a,2))/(2*b*c));
	
	beta=acos((pow(a,2)+ pow(c,2)-pow(b,2))/(2*a*c));
	gama=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*b*a));
	
	
	if(alfa>beta && alfa>gama){
    alfa=(alfa*180)/PI;
	maxstep=(int)alfa;
	maxmin=(alfa-maxstep)*60;
	maxsek=(alfa-maxstep-maxmin/60.)*3600;
	}
	if(beta>alfa && beta>gama){
	beta=(beta*180)/PI;
	maxstep=(int)beta;
	maxmin=(beta-maxstep)*60;
	maxsek=(beta-maxstep-maxmin/60.)*3600;}
	
	if(gama>alfa && gama>beta){
	gama=(gama*180)/PI;
	maxstep=(int)gama;
	maxmin=(gama-maxstep)*60;
	maxsek=(gama-maxstep-maxmin/60.)*3600;
	}
	
	s=(a+b+c)/2;
	povrsina=sqrt(s*(s-a)*(s-b)*(s-c));
	
	
	if(povrsina==0){
	printf("Linija\n");
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",maxstep,maxmin,maxsek);
	}
	
	 
	else if(fabs(a-b)<epsilon && fabs(b-c)<epsilon){
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",maxstep,maxmin,maxsek);
		
	}
	else if((fabs(a-b)<epsilon || fabs(b-c)<epsilon || fabs(a-c)<epsilon) && (fabs(pow(a,2)-pow(b,2)-pow(c,2))<epsilon || fabs(pow(b,2)-pow(a,2)-pow(c,2))<epsilon || fabs(pow(c,2)-pow(a,2)-pow(b,2))<epsilon)){
		printf("Pravougli\n");
		printf("Jednakokraki\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",maxstep,maxmin,maxsek);
		
	}
	else if(fabs(a-b)<epsilon || fabs(b-c)<epsilon || fabs(a-c)<epsilon  ){
		printf("Jednakokraki\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",maxstep,maxmin,maxsek);
	}
	else if(fabs(pow(a,2)-pow(b,2)-pow(c,2))<epsilon || fabs(pow(b,2)-pow(a,2)-pow(c,2))<epsilon || fabs(pow(c,2)-pow(a,2)-pow(b,2))<epsilon){
		printf("Pravougli\n");
		printf("Raznostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",maxstep,maxmin,maxsek);
	}
	else if(a!=b && b!=c && a!=c){
		printf("Raznostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",maxstep,maxmin,maxsek);
		}
	

	



	return 0;
}
