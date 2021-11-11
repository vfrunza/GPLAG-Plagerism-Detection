#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#define PI 3.14

int main() {
	double x1,x2,x3,y1,y2,y3,a,b,c,ka,kb,kc,alfa,beta,gama,maxugao=0,stp,min,sek,stp1,min1,sek1;
	printf("Unesite koordinate tacke t1:");
	scanf("%lf%lf",&x1,&y1);
	printf("Unesite koordinate tacke t2:");
	scanf("%lf%lf",&x2,&y2);
	printf("Unesite koordinate tacke t3:");
	scanf("%lf%lf",&x3,&y3);
	a=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	b=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
	c=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
	ka=(y2-y1)/(x2-x1);
	kb=(y3-y1)/(x3-x1);
	kc=(y2-y3)/(x2-x3);
	if(ka-kb<epsilon && ka-kc<epsilon && kb-kc<epsilon){
		printf("Linija\n");
	}
	if(a-b<epsilon && a-c<epsilon && b-c<epsilon){
		printf("Jednakostranicni\n");
	}
	if((ka*kb)+1<epsilon || (ka*kc)+1<epsilon || (kb*kc)+1<epsilon){
		printf("Pravougli\n");
	}
	if ((a-b<epsilon && a-c>epsilon) || (a-c<epsilon && a-b>epsilon) || (b-c<epsilon && b-a>epsilon)){
		printf("Jednakokraki\n");
	}
	if(a-b>epsilon && a-c>epsilon){
		printf ("Raznostranicni\n");
	}
	alfa=acos((c*c+b*b-a*a)/2*b*c);
	beta=acos((c*c+a*a-b*b)/2*a*c);
	gama=acos((a*a+b*b-c*c)/2*a*b);
	if (alfa>maxugao){
		maxugao=alfa;
	}
	else if(beta>maxugao){
		maxugao=beta;
	}
	else if(gama>maxugao){
		maxugao=gama;
	}
	stp=maxugao*180/PI;
	stp1=(int) stp;
	min=(stp-stp1)*60;
	min1=(int) min;
	sek=(min-min1)*60;
	sek1=(int) sek;
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stp1,min1,sek1);
	return 0;
}
