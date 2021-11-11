#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.14

int main() {
	double x1,x2,x3,y1,y2,y3;
	double a,b,c;
	double alfa,beta,gama,max_ugao;
	int stepen,minuta,sekunda;
	int linija=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt((pow((x1-x2),2))+(pow((y1-y2),2)));
	b=sqrt((pow((x3-x2),2))+(pow((y3-y2),2)));
	c=sqrt((pow((x3-x1),2))+(pow((y3-y1),2)));
	alfa=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
	beta=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
	gama=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
	alfa=alfa*180/PI;
	beta=beta*180/PI;
	gama=gama*180/PI;
	if(alfa>beta && alfa>gama)
		max_ugao=alfa;
	if(beta>alfa && beta>gama)
		max_ugao=beta;
	if(gama>alfa && gama>beta)
		max_ugao=gama;
	stepen=(int)max_ugao;
	minuta=(int)((max_ugao-stepen)*60);
	sekunda=((((max_ugao-stepen)*60)-(int)((max_ugao-stepen)*60))*60);
	if(fabs(max_ugao-180)<epsilon){
		printf("Linija\n");
		linija=1;
	}
	if((fabs((pow(a,2)+pow(b,2))-pow(c,2))<epsilon || (fabs((pow(b,2)+pow(c,2))-pow(a,2))<epsilon) && (fabs((pow(a,2)+pow(c,2))-pow(b,2))<epsilon))){
		if(linija==0)
		printf("Pravougli\n");}
	if((fabs(a-b)<epsilon || fabs(b-c)<epsilon || fabs(a-c)<epsilon) && (!(fabs(a-b)<epsilon && fabs(a-c)<epsilon && fabs(b-c)<epsilon)))
	{
		if(linija==0)
		printf("Jednakokraki\n");}
	if(fabs(a-b)>epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon){
		if(linija==0)
		printf("Raznostranicni\n");}
	if(fabs(a-b)<epsilon && fabs(a-c)<epsilon && fabs(b-c)<epsilon){
		if(linija==0)
		printf("Jednakostranicni\n");}
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",stepen,minuta,sekunda);
	
	return 0;
}
