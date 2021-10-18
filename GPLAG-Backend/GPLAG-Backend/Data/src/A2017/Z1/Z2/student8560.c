#include <stdio.h>
#include<math.h>
#define eps 0.0001
int main() {
	double x_1,x_2,x_3,y_1,y_2,y_3,a,b,c,alfa,beta,gama,najveci,min1;
	int step,min,sec;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x_1,&y_1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x_2,&y_2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x_3,&y_3);
	a=sqrt((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1));
	b=sqrt((x_3-x_2)*(x_3-x_2)+(y_3-y_2)*(y_3-y_2));
	c=sqrt((x_3-x_1)*(x_3-x_1)+(y_3-y_1)*(y_3-y_1));
	if(((fabs(x_1*(y_2-y_3)+x_2*(y_3-y_1)+x_3*(y_1-y_2)))/2)==0) printf("Linija");
	else if((round(a*a+b*b)==round(c*c)) || (a*a+b*b)==c*c){
		printf("Pravougli");
		if((fabs(a-b)<eps && fabs(a-c)>eps) || (fabs(a-c)<eps && fabs(a-b)>eps) || (fabs(b-c)<eps && fabs(b-a)>eps)) printf("\nJednakokraki");
		else printf("\nRaznostranicni");
	}
	else if((fabs(a-b)<eps && fabs(a-c)>eps) || (fabs(a-c)<eps && fabs(a-b)>eps) || (fabs(b-c)<eps && fabs(b-a)>eps)) printf("Jednakokraki");
	else if(fabs(a-b)<eps && fabs(a-c)<eps && fabs(b-c)<eps) printf("Jednakostranicni");
	else if(fabs(a-b)>eps && fabs(a-c)>eps && fabs(b-c)>eps) printf("Raznostranicni");
	
	alfa=acos((c*c+b*b-a*a)/(2*c*b));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	if(alfa>=beta && alfa>=gama) najveci=alfa;
	else if(beta>=alfa && beta>=gama) najveci=beta;
	else najveci=gama;
	
	najveci=najveci*(180./(4*atan(1)));
	step=(int)najveci;
	min1=(najveci-step)*60;
	min=(int)min1;
	sec=(min1-min)*60;
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",step,min,sec);
	return 0;
}