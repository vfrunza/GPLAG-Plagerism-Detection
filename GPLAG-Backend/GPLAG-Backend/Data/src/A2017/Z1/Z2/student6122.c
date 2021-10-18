#include <stdio.h>
#include <math.h>
#define  EPSILON 0.0001
#define PI 3.1415926535
int main() {
	double a,b,c,d,e,f,x,y,z;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &a, &b);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &c, &d);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &e, &f);
	x=sqrt(pow(a-c,2)+pow(b-d,2));
	y=sqrt(pow(a-e,2)+pow(b-f,2));
	z=sqrt(pow(e-c,2)+pow(f-d,2));

	double najveca, srednja, najmanja;
	if(x>=y && x>=z){
		najveca=x;
		if(y>=z) {srednja=y; najmanja=z;}
		else {srednja=z; najmanja=y;}
	}
	if(y>=x&&y>=z){
			najveca=y;
		if(x>=z) {srednja=x; najmanja=z;}
		else {srednja=z; najmanja=x;}
	}
	if(z>=x&&z>=y){
			najveca=z;
		if(x>=y) {srednja=x; najmanja=y;}
		else {srednja=y; najmanja=x;}
	}

	double ugao,arkus;
	ugao=(pow(najmanja,2)+pow(srednja,2)-pow(najveca,2))/(2*najmanja*srednja);
	int stepeni, minute, sekunde; 
	arkus=acos(ugao)*(180/PI);
	stepeni=(int)(arkus);
	minute=(int)((arkus-stepeni)*60);
	sekunde=(int)(((arkus-stepeni)*60-minute)*60);

	if(stepeni==180){
		printf("Linija\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
		return 0;
	} 
	if(fabs(pow(x,2)-pow(y,2)-pow(z,2))<=EPSILON || fabs(pow(y,2)-pow(z,2)-pow(x,2))<=EPSILON || fabs(pow(z,2)-pow(x,2)-pow(y,2))<=EPSILON) printf("Pravougli\n");
	if(fabs(x-y)<=EPSILON && (y-z)<=EPSILON) printf("Jednakostranicni\n");
	else if(fabs(x-y)<EPSILON || fabs(x-z)<EPSILON || fabs(y-z)<EPSILON) printf("Jednakokraki\n");
	else printf("Raznostranicni\n");
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	return 0;
}
