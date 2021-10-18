#include <stdio.h>
#include <math.h>
#define PI 3.141592
#define E 0.0001
int main() {
	double x1,y1,x2,y2,x3,y3,d12,d13,d23,ug1,ug2,ug3,maxug;
	int stepen,minut,sekund;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	d12=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	d13=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	d23=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	ug1=acos((pow(d12,2)+pow(d13,2)-pow(d23,2))/(2.*d12*d13));
	ug2=acos((pow(d12,2)+pow(d23,2)-pow(d13,2))/(2.*d12*d23));
	ug3=acos((pow(d13,2)+pow(d23,2)-pow(d12,2))/(2.*d13*d23));
	ug1*=180./PI;
	ug2*=180./PI;
	ug3*=180./PI;
	if(fabs(ug1-90.)<E || fabs(ug2-90.)<E || fabs(ug3-90.)<E) printf("Pravougli\n");
	if(fabs(ug1-180.)<E || fabs(ug2-180.)<E || fabs(ug3-180.)<E) printf("Linija\n");
	else if(fabs(d12-d13)<E && fabs(d12-d23)<E && fabs(d23-d13)<E) printf("Jednakostranicni\n");
	else if(fabs(d12-d13)<E || fabs(d12-d23)<E || fabs(d23-d13)<E) printf("Jednakokraki\n");
	else printf("Raznostranicni\n");
	maxug=ug1;
	if(ug2>ug1) maxug=ug2;
	else if(ug3>ug1) maxug=ug3;
	if(ug3>ug2) maxug=ug3;
	stepen=(int)maxug;
	maxug-=stepen;
	maxug*=60.;
	minut=(int)maxug;
	maxug-=minut;
	maxug*=60.;
	sekund=(int)maxug;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen,minut,sekund);
	return 0;
}
