#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265
int main() {
	double t1x,t1y,t2x,t2y,t3x,t3y;
	double a,b,c,alfa,beta,gama,najveci,ostatak,ostatak1;
	int linija = 0;
	int deci,minute,sekunde;
	double epsilon = 0.0001;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &t1x,&t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &t2x,&t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &t3x,&t3y);
	a = sqrt(pow(t1x-t2x,2)+pow(t1y-t2y,2));
	b = sqrt(pow(t2x-t3x,2)+pow(t2y-t3y,2));
	c = sqrt(pow(t1x-t3x,2)+pow(t1y-t3y,2));
	alfa = acos((b*b+c*c-a*a)/(2*c*b))*180/PI;
	beta = acos((a*a+c*c-b*b)/(2*a*c))*180/PI;
	gama = acos((b*b+a*a-c*c)/(2*a*b))*180/PI;
	if(fabs(alfa- 180.0) <= epsilon ||fabs(beta- 180.0) <= epsilon || fabs(gama- 180.0) <= epsilon ){
		printf("Linija\n");
		linija = 1;
	}else if(fabs(alfa- 90.0) <= epsilon ||fabs(beta - 90.0) <= epsilon || fabs(gama - 90.0) <= epsilon ){
		printf("Pravougli\n");
	}
	if((fabs((a - b)) <= epsilon) && (fabs((b - c)) <= epsilon) && (fabs((c - a)) <= epsilon) && linija != 1){
		printf("Jednakostranicni\n");
	}else if(((fabs((a - b)) <= epsilon) || (fabs((a - c)) <= epsilon) || (fabs((c - b)) <= epsilon)) && linija != 1){
		printf("Jednakokraki\n");
	}else if(linija != 1){
		printf("Raznostranicni\n");
	}
	/*Odredivanje najvećeg ugla*/
	najveci = alfa;
	if(najveci < beta){
		najveci = beta;
	}
	if(najveci < gama){
		najveci = gama;
	}
	/*Deci je decimalni dio najveceg ugla*/
	deci = najveci;
	/*ostatak je dio iza decimalnog dijela, decimalni ostatak*/
	ostatak = najveci - deci;
	if(ostatak<=epsilon){
		ostatak = 0;
	}
	ostatak1 = (ostatak*60) - floor(ostatak*60);
	if(fabs(ostatak1 - ostatak)<=epsilon){
		ostatak1 = 0;
	}
	minute = ostatak *60;
	sekunde = ostatak1 *60;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",deci,minute,sekunde);
	return 0;
}
