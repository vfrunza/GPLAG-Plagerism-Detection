#include <stdio.h>
#include <math.h>

#define epsilon 0.0001

int main() {
	double t1x,t1y, t2x,t2y, t3x,t3y, u1d,u1m,u1s, u2d,u2m,u2s, u3d,u3m,u3s, a,b,c, PI;
	double u1,u2,u3,ud,um,us;
	int u;
	PI=4*atan(1);
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf",&t1x,&t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf",&t2x,&t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf",&t3x,&t3y);
	
	a=sqrt((t2x-t1x)*(t2x-t1x)+(t2y-t1y)*(t2y-t1y));
	b=sqrt((t3x-t2x)*(t3x-t2x)+(t3y-t2y)*(t3y-t2y));
	c=sqrt((t3x-t1x)*(t3x-t1x)+(t3y-t1y)*(t3y-t1y));
	
	u1d=(acos((c*c+a*a-b*b)/(2*a*c))*(180./PI));
	u=u1d;
	u1m=(u1d-u)*60;
	u=u1m;
	u1s=(u1m-u)*60;
	
	u2d=(acos((a*a+b*b-c*c)/(2*a*b))*(180./PI));
	u=u2d;
	u2m=(u2d-u)*60;
	u=u2m;
	u2s=(u2m-u)*60;
	
	u3d=(acos((b*b+c*c-a*a)/(2*b*c))*(180./PI));
	u=u3d;
	u3m=(u3d-u)*60;
	u=u3m;
	u3s=(u3m-u)*60;
	
	if((fabs(u1d-u2d)<epsilon && fabs(u1d-u3d)<epsilon) || ((u1d-u2d)>epsilon && (u1d-u3d)>epsilon) || ((u1d-u2d)>epsilon && (fabs(u1d-u3d))<epsilon) || ((u1d-u3d)>epsilon && (fabs(u1d-u2d))<epsilon)) {
		ud=u1d;
		um=u1m;
		us=u1s;	
	/*	if(us==59) { us=0; um++; }
		if(um==60) {um=0; ud++; }*/
	}
	else if(((u2d-u1d)>epsilon && (u2d-u3d)>epsilon) || ((u2d-u1d)>epsilon && (fabs(u2d-u3d)<epsilon)) || ((u2d-u3d)>epsilon && (fabs(u2d-u1d))<epsilon)) {
		ud=u2d;
		um=u2m;
		us=u2s;		
	/*	if(us==59) { us=0; um++; }
		if(um==60) {um=0; ud++; }*/
	}
	else {
		ud=u3d;
		um=u3m;
		us=u3s;
	/*	if(us==59) { us=0; um++; }
		if(um==60) {um=0; ud++; }*/
	}

	if(fabs((t3y-t1y)/(t3x-t1x)-(t2y-t1y)/(t2x-t1x))<epsilon) {
		printf("Linija\n");
		printf("Najveci ugao ima %.0lf stepeni, %.0lf minuta i %.0lf sekundi.",ud,um,us);
		return 0;
	}
	if(fabs(a*a+b*b-c*c)<epsilon || fabs(a*a+c*c-b*b)<epsilon || fabs(c*c+b*b-a*a)<epsilon) printf("Pravougli\n");
	if(fabs(a-b)<epsilon && fabs(b-c)<epsilon && fabs(a-c)<epsilon) printf("Jednakostranicni\n");
	else if((fabs(a-b)<epsilon && fabs(a-c)>epsilon) || (fabs(a-c)<epsilon && fabs(a-b)>epsilon) || (fabs(c-b)<epsilon && fabs(a-c)>epsilon)) printf("Jednakokraki\n");
	else printf("Raznostranicni\n");
	printf("Najveci ugao ima %.0lf stepeni, %.0lf minuta i %.0lf sekundi.",ud,um,us);
	return 0;
}