#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001
#define PI 3.141592

int main() {

	double x1,x2,x3,y1,y2,y3,D12,D23,D31;
	double alfa,beta,gama,stepen,minut,sekund;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	
	
	/*STRANICE*/
	
	D12=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
	D23=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
	D31=sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
	
	
	/*UGLOVI*/
	
	alfa=acos((pow(D23,2)+pow(D31,2)-pow(D12,2))/(2*D23*D31));
	beta=acos((pow(D12,2)+pow(D31,2)-pow(D23,2))/(2*D12*D31));
	gama=acos((pow(D12,2)+pow(D23,2)-pow(D31,2))/(2*D12*D23));
	
	if( alfa>beta && alfa>gama){
		alfa*=180/PI;
		stepen=(int)alfa;
		alfa-=stepen;
		alfa*=60;
		minut=(int)alfa;
		alfa-=minut;
		alfa*=60;
		sekund=(int)alfa;
	
	}
	else if (beta>alfa && beta>gama){
		beta*=180/PI;
		stepen=(int)beta;
		beta-=stepen;
		beta*=60;
		minut=(int)beta;
		beta-=minut;
		beta*=60;
		sekund=(int)beta;

	}
	else if (gama>alfa && gama>beta){
		gama*=180/PI;
		stepen=(int)gama;
		gama-=stepen;
		gama*=60;
		minut=(int)gama;
		gama-=minut;
		gama*=60;
		sekund=(int)gama;

	}
	
	if(stepen==90 && minut==0 && sekund==0)printf("Pravougli\n");
	
	/*ISPITIVANJE OBLIKA*/
	
	if(stepen==180 && minut==0 && sekund==0) printf("Linija\n");  
	else if( fabs(D12-D23)<EPSILON && fabs(D23-D31)<EPSILON) printf ("Jednakostranicni\n");
	else if( fabs(D12-D23)<EPSILON && fabs(D23-D31)>EPSILON) printf("Jednakokraki\n");
	else if( fabs(D12-D23)>EPSILON && fabs(D23-D31)>EPSILON) printf("Raznostranicni\n");
	
	
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n",stepen,minut,sekund);

	
	
	return 0;
}
