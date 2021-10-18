#include <stdio.h>
#include <math.h>
#define E 0.0001

int main() {
/*	printf("Zadaća 1, Zadatak 2");*/
	double x1,x2,x3,y1,y2,y3,d12,d23,d31,kut;
	int s,m,st,pt=0,jst=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	d12=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	d23=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	d31=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	if(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))<E){
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
		return 0;
	}
	if(d12<d31 && d23<d31) if(fabs(d31*d31-d23*d23-d12*d12)<E){
		printf("Pravougli\n");
		pt=1;
	}
	else if(d12<d23 && d31<d23)	if(fabs(d23*d23-d12*d12-d31*d31)<E) {
		printf("Pravougli\n");
		pt=1;
	}
	else if(d23<d12 && d31<d12) if(fabs(d12*d12-d23*d23-d31*d31)<E){
		printf("Pravougli\n");
		pt=1;
	}
	if(fabs(d12-d23)<E && fabs(d23-d31)<E && fabs(d31-d12)<E) {
		printf("Jednakostranicni\n");
		jst=1;
	}
	else if((fabs(d12-d23)<E && fabs(d12-d31)>=E) || (fabs(d12-d31)<E && fabs(d12-d23)>=E) || (fabs(d23-d31)<E && fabs(d23-d12)>=E)) printf("Jednakokraki\n");
	else if(d12!=d23 && d23!=d31 && d31!=d12) printf("Raznostranicni\n");
	if(pt==1) printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
	else if(jst==1) printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
	else{
		if(d12<d31 && d23<d31) kut=acos((d12*d12+d23*d23-d31*d31)/(2*d12*d23));
		else if(d12<d23 && d31<d23) kut=acos((d12*d12+d31*d31-d23*d23)/(2*d12*d31));
		else kut=acos((d23*d23+d31*d31-d12*d12)/(2*d23*d31));
		kut*=180/3.14159265359;
		st=(int)kut;
		m=(int)((kut-st)*60);
		s=(int)((((kut-st)*60)-m)*60);
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n",st,m,s);
	}
	return 0;
}
