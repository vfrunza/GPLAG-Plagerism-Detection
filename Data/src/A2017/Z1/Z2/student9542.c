#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.1415926535
int main() {
	double x1,x2,x3,y1,y2,y3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	
	double d1,d2,d3;
	d1=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	d2=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	d3=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	
	double max, min, mid;
	if(d1>=d2 && d1>=d3){
		max=d1;
		if(d2>=d3) {
			mid=d2;
			min=d3;} else { 
				mid=d3;
				min=d2; } 
	} if(d2>=d1 && d2>=d3){
		max=d2;
		if(d3>=d1){
			mid=d3;
			min=d1;} else {
				mid=d1;
				min=d3;}
	} if(d3>=d1 && d3>=d2){
		max=d3;
		if(d2>=d1){
			mid=d2;
			min=d1;} else {
				mid=d1;
				min=d2;} 			
	} 
	
	double angle, arc;
	angle=((min*min)+(mid*mid)-(max*max))/(2*min*mid);
	int stepen, minuta, sec;
	arc=acos(angle);
	stepen=(int)((arc)*(180/PI));
	minuta=(int)(((arc)*(180/PI)-stepen)*60);
	sec=(int)(((((arc)*(180/PI)-stepen)*60)-minuta)*60);
	
	if(stepen==180) { printf("Linija\n");
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sec);
	return 0;}
	
	if (fabs(d3-sqrt((d1*d1)+(d2*d2)))<EPSILON || fabs(d2-sqrt((d3*d3)+(d1*d1)))<EPSILON || fabs(d1-sqrt((d3*d3)+(d2*d2)))<EPSILON) printf("Pravougli\n");
	if (fabs(d1-d2)<=EPSILON && fabs(d2-d3)<=EPSILON) printf("Jednakostranicni\n");
	else if (fabs(d1-d2)<=EPSILON || fabs(d2-d3)<=EPSILON || fabs(d3-d1)<=EPSILON) printf ("Jednakokraki\n");
	else printf("Raznostranicni\n");
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepen, minuta, sec);
	
	return 0;
}
