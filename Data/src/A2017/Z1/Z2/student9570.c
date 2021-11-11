#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.14
int main() {
	int istina=1,uks,s,m,st;
	double d1,d2,d3,x1,x2,x3,y1,y2,y3,W,Q,Z,p,q,r,NS;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	d1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	d2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	d3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
p=d2*d2+d3*d3-d1*d1;
r=d3*d3+d1*d1-d2*d2;
q=d1*d1+d2*d2-d3*d3;
W=acos(p/(2*d1*d3));
Q=acos(r/(2*d1*d3));
Z=acos(q/(2*d1*d2));
if(fabs (q<e) || fabs(r<e) || fabs(p<e))
  {
  	printf("Pravougli\n");
  }
  if(fabs(d1-d2)<e && fabs(d2-d3)<e)
  {
  	printf("Jednakostranicni\n");
  	
  }
  else if (fabs((d1+d2)-d3)<e || fabs((d1+d3)-d2)<e || fabs((d2+d3)-d1)<e)
  {
  	istina=0;
  	printf("Linija\n");
  	
  }
  else if(((fabs(d1-d2)<e && fabs(d1-d3)>e && fabs(d2-d3)>e) || (fabs(d1-d3)<e && fabs(d1-d2)>e && fabs(d3-d2)>e) ||  (fabs(d3-d2)<e && fabs(d2-d1)>e && fabs(d3-d1)>e)) &&(istina==1))
  {
  	printf("Jednakokraki\n");
  	
  }
  else if(fabs(d1-d2)>e && fabs(d1-d3)>e && fabs(d2-d3)>e)
	{
		printf("Raznostranicni\n");
	}
	if(W>Q && W>Z)
	{
		NS=W;
	}
		if(Q>W && Q>Z)
	{
		NS=Q;
	}
	if(Z>W && Z>Q)
	{
		NS=Z;
	}
	uks=(360*60*60*NS/(2*M_PI));
	s=uks%60;
	m=(uks/60)%60;
	st=uks/3600;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st,m,s);
	return 0;
}
