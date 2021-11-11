#include <stdio.h>
#include <math.h>
#define PI 3.141592654
#define EPSILON 0.0001
int main()
{
	double x1,x2,x3,y1,y2,y3,AB,AC,BC,ALFA,BETA,GAMA,sA,stepenA,minutA,sekundA,sB,stepenB,minutB,sekundB,sG,stepenG,minutG,sekundG;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	AB=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	AC=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	BC=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	ALFA=acos((AC*AC+AB*AB-BC*BC)/(2*AC*AB));
	BETA=acos((BC*BC+AB*AB-AC*AC)/(2*BC*AB));
	GAMA=acos((BC*BC+AC*AC-AB*AB)/(2*BC*AC));
	sA=ALFA*(180/PI);
	stepenA=floor(sA);
	minutA=floor((sA-stepenA)*60);
	sekundA=floor(((sA-stepenA)*60-minutA)*60);
	sB=BETA*(180/PI);
	stepenB=floor(sB);
	minutB=floor((sB-stepenB)*60);
	sekundB=floor(((sB-stepenB)*60-minutB)*60);
	sG=GAMA*(180/PI);
	stepenG=floor(sG);
	minutG=floor((sG-stepenG)*60);
	sekundG=floor(((sG-stepenG)*60-minutG)*60);
	if(fabs(sA-180)<EPSILON || fabs(sB-180)<EPSILON || fabs(sG-180)<EPSILON){
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
	} else if(fabs(AB-BC)<EPSILON && fabs(BC-AC)<EPSILON) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
	}else if(((pow(AB,2)+pow(BC,2)-pow(AC,2))<EPSILON && fabs(AB-BC)<EPSILON) || ((pow(AB,2)+pow(AC,2)-pow(BC,2))<EPSILON && fabs(AB-AC)<EPSILON) || ((pow(BC,2)+pow(AC,2)-pow(AB,2))<EPSILON && fabs(BC-AC)<EPSILON)){
		printf("Pravougli\n");
		printf("Jednakokraki\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
	}else if((fabs(AB-BC)<EPSILON || fabs(AB-AC)<EPSILON || fabs(BC-AC)<EPSILON) && sA>sB && sA>sG) {
		printf("Jednakokraki\n");
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", stepenA,minutA,sekundA);
	}else if(((fabs(AB-BC)<EPSILON) || (fabs(AB-AC)<EPSILON) || (fabs(BC-AC)<EPSILON)) && sB>sA && sB>sG){
		printf("Jednakokraki\n");
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", stepenB,minutB,sekundB);
	}else if(((fabs(AB-BC)<EPSILON) || (fabs(AB-AC)<EPSILON) || (fabs(BC-AC)<EPSILON)) && sG>sA && sG>sB){
		printf("Jednakokraki\n");
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", stepenG,minutG,sekundG);
	}else if(fabs(AB-BC)>EPSILON && fabs(AB-AC)>EPSILON && fabs(AC-BC)>EPSILON && sG>sA && sG>sB){
		printf("Raznostranicni\n");
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", stepenG,minutG,sekundG);
	}else if(fabs(AB-BC)>EPSILON && fabs(AB-AC)>EPSILON && fabs(AC-BC)>EPSILON && sB>sA && sB>sG){
		printf("Raznostranicni\n");
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", stepenB,minutB,sekundB);
	}else if(fabs(AB-BC)>EPSILON && fabs(AB-AC)>EPSILON && fabs(AC-BC)>EPSILON && sA>sB && sA>sG){
		printf("Raznostranicni\n");
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", stepenA,minutA,sekundA);
	}else if(fabs(AB-BC)>EPSILON && fabs(AB-AC)>EPSILON && fabs(AC-BC)>EPSILON && (pow(AB,2)+pow(BC,2)-pow(AC,2))<EPSILON){
		printf("Pravougli\n");
		printf("Raznostranicni\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
	}else if(fabs(AB-BC)>EPSILON && fabs(AB-AC)>EPSILON && fabs(AC-BC)>EPSILON && (pow(AB,2)+pow(AC,2)-pow(BC,2))<EPSILON){
		printf("Pravougli\n");
		printf("Raznostranicni\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");	
	}else if(fabs(AB-BC)>EPSILON && fabs(AB-AC)>EPSILON && fabs(AC-BC)>EPSILON && (pow(BC,2)+pow(AC,2)-pow(AB,2))<EPSILON){
		printf("Pravougli\n");
		printf("Raznostranicni\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");		
	}else if((pow(AB,2)+pow(BC,2)-pow(AC,2))<EPSILON || (pow(AB,2)+pow(AC,2)-pow(BC,2))<EPSILON || (pow(BC,2)+pow(AC,2)-pow(AB,2))<EPSILON){
		printf("Pravougli\n");
		printf("Najveci ugao ima 90 stepeeni, 0 minuta i 0 sekundi.\n");
	}
	return 0;
}
