#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.1415926535897932384626433832795028841971

int main() {
	double x1,y1,x2,y2,x3,y3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	double p;
	p=fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));

	double a,b,c;
	a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	
	if (fabs(a*a-b*b-c*c)<EPSILON || fabs(b*b-a*a-c*c)<EPSILON || fabs(c*c-a*a-b*b)<EPSILON )printf("Pravougli\n");
	
	if(fabs(p-0)<EPSILON) printf("Linija\n");
	else if(fabs(a-b)<EPSILON && fabs(a-c)<EPSILON && fabs(a-c)<EPSILON) printf("Jednakostranicni\n");
	else if(fabs(a-b)<EPSILON && fabs(b-c)>EPSILON && fabs(a-c)>EPSILON) printf ("Jednakokraki\n");
	else if (fabs(a-c)<EPSILON && fabs(a-b)>EPSILON && fabs(b-c)>EPSILON) printf("Jednakokraki\n");
	else if (fabs(b-c)<EPSILON && fabs(a-b)>EPSILON && fabs(a-c)>EPSILON) printf("Jednakokraki\n");
	else printf("Raznostranicni\n");
	
	double x,y,z;
	x=acos((b*b+c*c-a*a)/(2*b*c))*180/PI;
	y=acos((a*a+c*c-b*b)/(2*a*c))*180/PI;
	z=acos((a*a+b*b-c*c)/(2*a*b))*180/PI;
   
   double minx,miny,minz;
   minx=((x-(int)x)*60);
   miny=((y-(int)y)*60);
   minz=((z-(int)z)*60);
   
   if (x>=y && x>=z) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)x, (int)minx, (int)((minx-(int)minx)*60));
	if (y>=x && y>=z) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)y, (int)miny, (int)((miny-(int)miny)*60));
   if(z>=x && z>=y) printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)z, (int)minz, (int)((minz-(int)minz)*60));

	return 0;
}
