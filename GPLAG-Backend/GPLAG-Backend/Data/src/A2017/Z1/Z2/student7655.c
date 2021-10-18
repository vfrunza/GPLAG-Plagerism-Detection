#include <stdio.h>
#include <math.h>
#define step 57.295827908 
#define epsilon 0.0001

int main() {
	double xt1,xt2,xt3,yt1,yt2,yt3;
	double xa,xb,xc,ya,yb,yc;
	double a,b,c;
	double kosinus1, kosinus2, kosinus3, alfa, beta, gama;
	double minute, sekunde;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf%lf",&xt1,&yt1);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf%lf",&xt2,&yt2);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf%lf",&xt3,&yt3);
	
	/* izracunavanje duzina stranica */
	xa=xt2-xt1; 	ya=yt2-yt1;  	xb=xt1-xt3;
	yb=yt1-yt3;     xc=xt2-xt3;    	yc=yt2-yt3;
	a=sqrt(xa*xa+ya*ya);
	b=sqrt(xb*xb+yb*yb);
	c=sqrt(xc*xc+yc*yc);
	
	/* provjeravanje da li tacke pripadaju istom pravcu */
	 if (fabs(a-b-c)<epsilon || fabs(b-a-c)<epsilon || fabs(c-a-b)<epsilon) {
      printf ("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
      return 1;
	 }
	
	/* izracunavanje i pretvaranje uglova */
	kosinus1= (b*b+c*c-a*a)/(2*b*c);
	kosinus2=(a*a+c*c-b*b)/(2*a*c);
	kosinus3=(a*a+b*b-c*c)/(2*a*b);
	alfa=acos(kosinus1)*step;
	beta=acos(kosinus2)*step;
	gama=acos(kosinus3)*step;
	
	if(fabs(alfa-90)<epsilon || fabs(beta-90)<epsilon || fabs(gama-90)<epsilon) printf("Pravougli\n");
	
	/* ispitivanje vrste trougla prema stranicama */
	if (fabs(a-b)<epsilon && fabs(b-c)<epsilon && fabs(a-c)<epsilon) printf("Jednakostranicni\n");
	else if ((fabs(a-b)<epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon) || (fabs(a-b)>epsilon && fabs(a-c)>epsilon && fabs(b-c)<epsilon) || (fabs(a-b)>epsilon && fabs(a-c)<epsilon && fabs(b-c)>epsilon)) printf ("Jednakokraki\n");
	else if (fabs(a-b)>epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon) printf ("Raznostranicni\n");
	
	
	/* odredjivanje najveceg ugla */
	if(alfa>=beta && alfa>=gama){
		minute=(alfa-(int)alfa)*60;
		sekunde=(minute-(int)minute)*60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)alfa,(int)minute,(int)sekunde);
	}
	else if (beta>=alfa && beta>=gama){
		minute=(beta-(int)beta)*60;
		sekunde=(minute-(int)minute)*60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)beta,(int)minute,(int)sekunde);
	}
	else if (gama>=alfa && gama>=beta){
		minute=(gama-(int)gama)*60;
		sekunde=(minute-(int)minute)*60;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)gama, (int)minute, (int)sekunde);
	}
	
	return 0;
}
