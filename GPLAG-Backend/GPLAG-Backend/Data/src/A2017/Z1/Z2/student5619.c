#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#define E 0.0001
int main(){
	double x1,x2,x3,y1,y2,y3,d1,d2,d3,L,B,G;
	int s1,s2,s3,m1,m2,m3,sec1,sec2,sec3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	d3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	L=(acos((d3*d3+d1*d1-d2*d2)/(2*d3*d1)))*(180/PI);
	B=(acos((d2*d2+d1*d1-d3*d3)/(2*d2*d1)))*(180/PI);
	G=(acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3)))*(180/PI);
	s1=(int)L;
	m1=(int)((L-s1)*60);
	sec1=(int)((((L-s1)*60)-m1)*60);
	s2=(int)B;
	m2=(int)((B-s2)*60);
	sec2=(int)((((B-s2)*60)-m2)*60);
	s3=(int)G;
	m3=(int)((G-s3)*60);
	sec3=(int)((((G-s3)*60)-m3)*60);
	if (s1==0 || s1==180 || s2==0 || s2==180 || s3==0 || s3==180) printf("Linija\n");
	if (s1==90 || s2==90 || s3==90) printf("Pravougli\n");
	if (fabs(d1-d2)<E && fabs(d1-d3)<E && fabs(d2-d3)<E) printf("Jednakostranicni\n");
	if (fabs(d1-d2)<E || fabs(d1-d3)<E || fabs(d2-d3)<E) printf("Jednakokraki\n");
	else printf("Raznostranicni\n");
	if (L>B && L>G) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",s1,m1,sec1);
	else if (B>L && B>G) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",s2,m2,sec2);
	if (G>L && G>B) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",s3,m3,sec3);
	return 0;
}
