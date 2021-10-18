#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.14

int main() {
	int sec1, sec2, sec3, min1, min2, min3, stepen1, stepen2, stepen3, max=0, maxMin, maxSec;
	double x1, x2, x3, y1, y2, y3, a, b, c, alfa, beta, gama;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	
	alfa=acos((b*b+c*c-a*a)/(2*b*c));

	beta=acos((a*a+c*c-b*b)/(2*a*c));

	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	alfa=alfa*(180/PI);
	beta=beta*(180/PI);
	gama=gama*(180/PI);
	
	if(alfa>beta && alfa>gama){
	stepen1=(int)(alfa);
	min1=(int)((alfa-stepen1)*60);
	sec1=(int)(((alfa-stepen1)*60-min1)+60);}

    if(beta>alfa && beta>gama){
	stepen2=(int)(beta);
	min2=(int)((beta-stepen2)*60);
	sec2=(int)(((beta-stepen2)*60-min2)+60);}

    
	stepen3=(int)(gama);
	min3=(int)((gama-stepen3)*60);
	sec3=(int)(((gama-stepen3)*60-min3)+60);

	
	if((stepen1==90) || (stepen2==90) || (stepen3==90))
		printf("Pravougli");
	if(fabs(a-b)<E && fabs(b-c)<E) {
		printf("\nJednakostranicni");
	}else if( fabs(a-b)<E || fabs(a-c)<E || fabs(b-c)<E) {
		printf("\nJednakokraki");
	}else if(fabs(a-b)>E && fabs(b-c)>E) {
		printf("\nRaznostranicni");
	}
	
	if(stepen1>=stepen2 && stepen1>=stepen3){
			max=stepen1;
			maxMin=min1;
			maxSec=sec1;}
	if(stepen2>=stepen1 && stepen2>=stepen3){
			max=stepen2;
			maxMin=min2;
			maxSec=sec2;}
	if(stepen3>=stepen1 && stepen3>=stepen2){
			max=stepen3;
			maxMin=min3;
			maxSec=sec3;}
	
	
	if(max==0 && stepen1==stepen2){
		if(min1>min2){
			max=stepen1;
			maxMin=min1;
			maxSec=sec1;
	}
	else{
		max=stepen2;
		maxMin=min2;
		maxSec=sec2;
	}
	if(min1==min2){     /*provjeriti zagradu*/
		if(sec1>sec2){
			max=stepen1;
			maxMin=min1;
			maxSec=sec1;
	}
	else{
		max=stepen2;
		maxMin=min2;
		maxSec=sec2;
		}
	  }
	}
	if(max==0 && stepen2==stepen3){
		if(min2>min3){
			max=stepen2;
			maxMin=min2;
			maxSec=sec2;
		}
	else{
		max=stepen3;
		maxMin=min3;
		maxSec=sec3;
	}
	if(min2==min3){
		if(sec2>sec3){
			max=stepen2;
			maxMin=min2;
			maxSec=sec2;
	}
	else{
		max=stepen3;
		maxMin=min3;
		maxSec=sec3;
		 }	
		}
	}
	if(max==0 && stepen1==stepen3){
		if(min1>min3){
			max=stepen1;
			maxMin=min1;
			maxSec=sec1;
	}
	else{
		max=stepen3;
		maxMin=min3;
		maxSec=sec3;
	}
	if(min1==min3){
		if(sec1>sec3){
			max=stepen1;
			maxMin=min1;
			maxSec=sec1;
	}
	else{
		max=stepen3;
		maxMin=min3;
		maxSec=sec3;
		}	
	  }
	}
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", max, maxMin, maxSec);
	return 0;
}
