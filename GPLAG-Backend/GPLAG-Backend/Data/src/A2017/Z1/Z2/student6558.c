#include <stdio.h>
#include <math.h>

#define epsilon 0.0001
#define pi 3.14159265
#define jedan 1.0001

int main() {
	double ax,ay,bx,by,cx,cy,AB,AC,BC,suma1,suma2,suma3,kAB,kAC,kBC,uAB,uAC,uBC,cosAB,cosBC,cosAC,step;
	double sAB,sAC,sBC,mAB,mAC,mBC,SAB,SAC,SBC;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &ax,&ay);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&bx, &by);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &cx,&cy);
	AB=sqrt(pow((ax-bx),2)+pow((ay-by),2));
	AC=sqrt(pow((ax-cx),2)+pow((ay-cy),2));
	BC=sqrt(pow((bx-cx),2)+pow((by-cy),2));
	suma1=(pow(AC,2)+pow(BC,2));
	suma2=(pow(AB,2)+pow(AC,2));
	suma3=(pow(AB,2)+pow(BC,2));
	kAB=pow(AB,2);
	kAC=pow(AC,2);
	kBC=pow(BC,2);
	cosBC=(kAC+kAB-kBC)/(2*AC*AB);
	cosAB=(kBC+kAC-kAB)/(2*BC*AC);
	cosAC=(kAB+kBC-kAC)/(2*AB*BC);
	step=180.0/pi;
	uAB=acos(cosAB)*step;
	uBC=acos(cosBC)*step;
	uAC=acos(cosAC)*step;
	mAB=(uAB-floor(uAB))*60;
	mAC=(uAC-floor(uAC))*60;
	mBC=(uBC-floor(uBC))*60;
	SAB=(mAB-floor(mAB))*60;
	SAC=(mAC-floor(mAC))*60;
	SBC=(mBC-floor(mBC))*60;
	sAB=(ay-by)/(ax-bx);
	sBC=(by-cy)/(bx-cx);
	sAC=(ay-cy)/(ax-cx);
	
	if(fabs(suma1-kAB)<epsilon || fabs(suma2-kBC)<epsilon || fabs(suma3-kAC)<epsilon){
		printf("Pravougli\n");
	}
	if(fabs(AC-BC)<epsilon && fabs(AB-BC)<epsilon && fabs(AB-AC)<epsilon){
	    printf("Jednakostranicni\n");
	}
	else if(fabs(sAB-sBC)<jedan && fabs(sAB-sAC)<jedan && fabs(sBC-sAC)<jedan){
		printf("Linija\n");
	}
	
	else if(fabs(AC-BC)<epsilon || fabs(AB-BC)<epsilon || fabs(AB-AC)<epsilon){
	    printf("Jednakokraki\n");
	}
	else if(fabs(AC-BC)>epsilon && fabs(AB-BC)>epsilon && fabs(AB-AC)>epsilon){
		printf("Raznostranicni\n");
	}
	
	if(AB>=AC && AB>=BC){
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",floor(uAB),floor(mAB),floor(SAB));
	}
	else if(AC>=AB && AC>=BC){
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",floor(uAC),floor(mAC),floor(SAC));
	}
	else if(BC>=AB && BC>=AC){
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",floor(uBC),floor(mBC),floor(SBC));
	}
	
	

	return 0;
}
