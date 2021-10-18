#include <stdio.h>
#include <math.h>
#define PI 3.1415
#define e 0.0001

int main() {
	double x1, y1, x2, y2, x3, y3, a, b, c, ugao1, ugao2, ugao3, najveci_ugao;
	int stepeni, minute, sekunde;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3);
	
	a=sqrt(((x2*x2)-(x1*x1))+((y2*y2)-(y1*y1)));
	b=sqrt(((x3*x3)-(x2*x2))+((y3*y3)-(y2*y2)));
	c=sqrt(((x1*x1)-(x3*x3))+((y1*y1)-(y3*y3)));
	
	if (a==b && b==c ){
		printf ("\nLinija");
	}
	else if (a==b && b==c && a==c){
		printf ("\nJednakostranicni");
	}
	else if (a!=b && b!=c && a!=c){
		printf ("\nRaznostranicni");
	}
	else if ((a==b && a!=c) || (a==c && a!=b) || (b==c && b!=a)){
		printf ("\nJednakokraki");
	}
	
	
	ugao1=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
	ugao2=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
	ugao3=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
	
	ugao1=ugao1*(180/PI);
	ugao2=ugao2*(180/PI);
	ugao3=ugao3*(180/PI);
	
	if (ugao1>=ugao2 && ugao2>=ugao3){
		najveci_ugao=ugao1;
	}
	else if (ugao2>=ugao3 && ugao3>=ugao1){
		najveci_ugao=ugao2;
	}
	else if (ugao3>=ugao1 && ugao1>=ugao2){
		najveci_ugao=ugao3;
	}
	stepeni=(int)(najveci_ugao);
	minute=(int)((najveci_ugao-stepeni)*60);
	sekunde=(int)(((najveci_ugao-stepeni)*60-minute)*60);
	printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	
	
	return 0;
}
