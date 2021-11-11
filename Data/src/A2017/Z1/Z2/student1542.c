#include <stdio.h>
#include <math.h>

#define PI 3.14159256359
#define e 0.0001
int main() {
//	double secalfa, secbeta, secgama;
//	double minalfa, minbeta, mingama;
//	double stepalfa, stepbeta, stepgama;
		double x1,y1;
		double x2,y2;
		double x3,y3;
	double a,b,c; //stranice
	double alfa1 ,beta1 ,gama1; //uglovi u rad
	double alfa ,beta ,gama; //ugl u step
	double P;
	printf ("Unesite koordinate tacke t1: "); scanf("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: "); scanf("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: "); scanf("%lf %lf", &x3, &y3);
	
	//Stranica a//
	a=sqrt(pow(x1-x2,2) + pow(y1-y2,2) );
	//Stranica b//
	b=sqrt(pow(x2-x3,2) + pow(y2-y3,2) );
	//Stranica c//
	c=sqrt(pow(x3-x1,2) + pow(y3-y1,2) );
	
	alfa1 = acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
	beta1 = acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
	gama1 = acos((pow(b,2)+pow(a,2)-pow(c,2))/(2*b*a));
	
	alfa = alfa1 * (180.00/PI);
	beta = beta1 * (180.00/PI);
	gama = gama1 * (180.00/PI);
	
		P=0.5*fabs(x1 * (y2-y3) + x2*(y3-y1) +x3*(y1-y2));
	
	if (P==0.00) {
		printf ("Linija");
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;}
	
	double stepalfa = alfa-((int)alfa);
	int minalfa = (stepalfa*3600) / 60;
	int secalfa = fmod((stepalfa*3600),60.00);
	double stepa = (int)alfa;
	
	double stepbeta = beta-((int)beta);
	int minbeta = (stepbeta*3600) / 60;
	int secbeta = fmod((stepbeta*3600),60.00);
	double stepb = (int)beta;
	
	double stepgama = gama-((int)gama);
	int mingama = (stepgama*3600) / 60;
	int secgama = fmod((stepgama*3600),60.00);
	double stepg = (int)gama;
	
	//fabs(a*a + b*b - (c*c) <=e) || fabs(a*a -(b*b) + c*c <=e) || fabs( b*b + c*c -(a*a)<=e)//
	if (fabs(alfa-90.00)<=e || fabs(beta-90.00)<=e || fabs(gama-90.00)<=e) printf ("Pravougli\n");
	//if (alfa==90.00 || beta==90.00 || gama==90.00) printf ("Pravougli\n");//
	if (fabs(alfa-beta)<=e && fabs(beta-gama)<=e) printf ("Jednakostranicni\n");
	else if (fabs(alfa - beta)<=e || fabs(beta-gama)<=e || fabs(alfa-gama)<=e) printf ("Jednakokraki\n");
	else if (a!=b && a!=c && c!=b) printf("Raznostranicni\n");
	
	if (alfa>beta && alfa>gama){
	printf ("Najveci ugao ima %.0f stepeni, %d minuta i %d sekundi.",stepa ,minalfa, secalfa);}
	
	else if (beta>alfa && beta>gama){
	printf ("Najveci ugao ima %.0f stepeni, %d minuta i %d sekundi.",stepb ,minbeta, secbeta);}
	
	else{
	printf ("Najveci ugao ima %.0f stepeni, %d minuta i %d sekundi.",stepg ,mingama, secgama);}
	
	return 0;
}
