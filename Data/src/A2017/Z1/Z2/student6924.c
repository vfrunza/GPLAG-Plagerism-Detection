#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.1415926535 

int main(){
    double x1, x2, x3, y1 ,y2, y3, d1, d2, d3, a, b, c, ugao, nugao, step, min, sek;
    
    printf("Unesite koordinate tacke t1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Unesite koordinate tacke t2: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Unesite koordinate tacke t3: ");
    scanf("%lf %lf", &x3, &y3);
    


    d1=sqrt(pow(x2-x1,2)+pow(y2-y1,2)); 
	d2=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	d3=sqrt(pow(x1-x3,2)+pow(y1-y3,2));

	if(d1-d2<=EPSILON && d2-d3<=EPSILON)
	{
		a=d1; b=d2; c=d3;
	} 
	else if(d1-d3<=EPSILON && d3-d2<=EPSILON)
	{
		a=d1; b=d3; c=d2;
	} 
	else if(d2-d1<=EPSILON && d1-d3<=EPSILON)
	{
		a=d2; b=d1; c=d3;
	} 
	else if(d2-d3<=EPSILON && d3-d1<=EPSILON)
	{
		a=d2; b=d3; c=d1;
	} 
	else if(d3-d1<=EPSILON && d1-d2<=EPSILON)
	{
		a=d3; b=d1; c=d2;
	}
	else if(d3-d2<=EPSILON && d2-d1<=EPSILON)
	{
		a=d3; b=d2; c=d1;
	}
	

	ugao=( (a*a+b*b-c*c) / (2*b*a) );
	nugao=( (acos(ugao))*180 )/ PI;
	step=(int) nugao;
	min=(int) ( (nugao-step)*60 );
	sek=(int) ( ( ( (nugao-step)*60)-min)*60);
	
	
	
	if(fabs(c-sqrt(a*a+b*b))<EPSILON) {
		printf("Pravougli\n");
	} 
	if(fabs(ugao-1)<EPSILON || fabs(ugao+1)<EPSILON)
	{   
		printf("Linija\n");
	}  
	else if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON)
	{
		printf("Jednakostranicni\n");
	} 
	else if(fabs(a-b)<EPSILON && fabs(a-c)>EPSILON && fabs(b-c)>EPSILON)
	{
		printf("Jednakokraki\n");
	} 
	else if(fabs(c-b)<EPSILON && fabs(a-c)>EPSILON && fabs(a-b)>EPSILON)
	{
		printf("Jednakokraki\n");
	} 
	else if(fabs(c-a)>EPSILON && fabs(b-a)>EPSILON && fabs(b-c)>EPSILON)
	{
		printf("Raznostranicni\n");
	}
	
	
	printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.\n", step, min, sek);

    return 0;
}