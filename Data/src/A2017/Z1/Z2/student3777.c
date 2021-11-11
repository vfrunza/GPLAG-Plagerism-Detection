#include <stdio.h>
#include <math.h>
#define eps 0.001
#define PI 3.14
int main () {
	double x,z,y,k,j,i,a,b,c;
	int najveciugao,Q,M,N;
	printf("Unesite koordinate tacke t1:");
	scanf("%lf%lf", &x,&y);
	printf(" Unesite koordinate tacke t2:");
	scanf("%lf%lf", &i,&j);
	printf(" Unesite koordinate tacke t3:");
	scanf("%lf%lf", &z,&k);
	a=pow(pow(z-x,2)+pow(k-y,2),1/2);
	b=pow(pow(i-x,2)+pow(j-y,2),1/2);
	c=pow(pow(i-z,2)+pow(j-k,2),1/2);
	Q=acos((a*a-b*b-c*c)/(2*b*c));
	M=acos((b*b-a*a-c*c)/(2*a*c));
	N=acos((c*c-a*a-b*b)/(2*a*b));
	int svesekunde=najveciugao*60*60;
	int sek=svesekunde%60;
	int min=(svesekunde/60)%60;
	int step=svesekunde/3600;

	 if((fabs(a-b)<eps) || (fabs(a-c)<eps) || (fabs(b-c)<eps)){
		printf(" Pravougli\n");
		printf("Jednakokraki");
		printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	
	} else if (fabs(a*a-(b*b+c*c))<eps || fabs(b*b-(b*b+c*c))<eps || fabs(c*c-(a*a+b*b))<eps) {
		printf("Pravougli");
		printf("Najveci ugao je 90 stepeni, 0 minuta i 0 sekundi");
	} else if ((fabs(a-b)<eps) && (fabs(a-c)<eps) && (fabs(b-c)<eps)){
		printf ("Jednakostranicni");
	} else if ((fabs(a-b)<eps) || (fabs(a-c)<eps) || (fabs(b-c)<eps)){
		printf("Jednakokraki");
	}
	return 0;
}





