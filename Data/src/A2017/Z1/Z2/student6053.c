#include <stdio.h>
#include<math.h>
#define E 0.00001
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923
int main() {
	double x1,x2,x3,y1,y2,y3,a,b,c,alfa,beta,gama,max=0,maxs;
	int st,m,s;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf",&x3,&y3);
	if(fabs(((x2-x1)/(x3-x1))-((y2-y1)/(y3-y1)))<E || (fabs(x1-x2)<E &&fabs(x1-x3)<E) ||(fabs(y2-y1)<E && fabs(y1-y3)<E)){
	 printf("Linija\n");
	 printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	 return 0;
	}
	
	
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	alfa=acos((b*b+c*c-a*a)/(2*b*c));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	if(alfa>=beta && alfa>=gama) max=alfa;
	else if(beta>=alfa && beta>=gama) max=beta;
	else if(gama>=alfa && gama>=beta) max=gama;
	
	maxs=(max*180)/PI;
/*	printf("%g\n",maxs);*/
	st=maxs;
	m=(int)((maxs-st)*3600)/60;
	s=(int)((maxs-st)*3600)%60;

	if(fabs(a-b)<E && fabs(b-c)<E) { printf("Jednakostranicni\n");
	/*printf("Najaveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");*/
	}
	if(fabs((a*a+b*b)-c*c)<E || fabs((a*a+c*c)-b*b)<E || fabs((b*b+c*c)-a*a)<E) printf("Pravougli\n");
	if(fabs(a-b)>E && fabs(b-c)>E && fabs(a-c)>E) printf("Raznostranicni\n");
	if((fabs(a-b)<E && fabs(b-c)>E)  || (fabs(b-c)<E && fabs(c-a)>E) || (fabs(a-c)<E && fabs(c-b)>E)) printf("Jednakokraki\n");
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",st,m,s);
	
	
	return 0;
}
