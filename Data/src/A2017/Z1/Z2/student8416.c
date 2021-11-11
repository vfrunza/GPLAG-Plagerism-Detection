#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 0.0001
#define PI 3.141592653

int main() {
	double x1, y1, x2, y2, x3, y3, dab, dac, dbc, alfa, beta, gama;
	int stepeni, minute, sekunde;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	dab=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	dac=sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
	dbc=sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)));
	alfa=acos((dbc*dbc+dac*dac-dab*dab)/(2*dbc*dac))*(180./PI);
	beta=acos((dab*dab+dac*dac-dbc*dbc)/(2*dab*dac))*(180./PI);
	gama=acos((dab*dab+dbc*dbc-dac*dac)/(2*dab*dbc))*(180./PI);
	
/*	printf("Stranica a: %f", dab);
	printf("\nStranica b: %f", dbc);
	printf("\nStranica c: %f", dac);
	printf("\n%g", alfa);
	printf("\n%g", beta);
	printf("\n%g", gama);*/
	
	if(abs(alfa-180)<eps || abs(beta-180)<eps || abs(gama-180)<eps){
		printf("Linija\n");
		goto kraj;
	}
	if(abs(alfa-90)<eps || abs(beta-90)<eps || abs(gama-90)<eps) printf("Pravougli\n");
	if(abs(alfa-60)<eps && abs(beta-60)<eps && abs(gama-60)<eps) printf("Jednakostranicni\n");
	if((abs(alfa-beta)<eps && abs(alfa-gama)>eps) || (abs(alfa-gama)<eps && abs(alfa-beta)>eps) || (abs(beta-gama)<eps && abs(beta-alfa)>eps)){
		printf("Jednakokraki\n");
		goto kraj;
	}
	if(abs(alfa-beta)>eps && abs(beta-gama)>eps && abs(alfa-gama)>eps) printf("Raznostranicni\n");
	
	kraj:
	if(alfa>=beta && alfa>=gama){
		stepeni=(int)alfa;
		minute=(int)((alfa-stepeni)*3600)/60;
		sekunde=(int)((alfa-stepeni)*3600)%60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", stepeni, minute, sekunde);
	}
	
	if(gama>=beta && gama>=alfa){
		stepeni=(int)gama;
		minute=(int)((gama-stepeni)*3600)/60;
		sekunde=(int)((gama-stepeni)*3600)%60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", stepeni, minute, sekunde);
	}
	
	if(beta>=alfa && beta>=gama){
		stepeni=(int)beta;
		minute=(int)((beta-stepeni)*3600)/60;
		sekunde=(int)((beta-stepeni)*3600)%60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", stepeni, minute, sekunde);
	}
	

return 0;	
}
