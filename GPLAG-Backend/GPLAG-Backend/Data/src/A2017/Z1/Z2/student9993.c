#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.14159265359
int main() {
	double x1, y1, x2, y2, x3, y3, alfa, beta, gama, alfas, betas, gamas, a, b, c;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &x1, &y1 );
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &x2, &y2 );
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &x3, &y3 );
	
	c=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	b=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	a=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	
	alfa=acos((c*c+b*b-a*a)/(2*b*c));
	beta=acos((a*a+c*c-b*b)/(2*a*c));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	alfas=(180*alfa)/PI;
	betas=(180*beta)/PI;
	gamas=(180*gama)/PI;
	
    if ((fabs(alfas-90)<=E && fabs(b-c)<=E) || (fabs(betas-90)<=E && fabs(a-c)<=E) || (fabs(gamas-90)<=E && fabs(a-b)<=E)){
	    printf("Pravougli\n");
	    printf("Jednakokraki\n");
	    printf ("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
	    return 1;
    }
	else if(fabs(alfas-90)<=E || fabs(betas-90)<=E || fabs(gamas-90)<=E){
	    printf ("Pravougli\n");
	    printf ("Raznostranicni\n");
	    printf ("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
	    return 1;
	}
	else if(fabs(alfas-180)<=E || fabs(betas-180)<=E || fabs(gamas-180)<=E){
	    printf ("Linija\n");
	    printf ("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
	    return 1;
	}
	else if(fabs(a-b)<=E && fabs(a-c)<=E && fabs(b-c)<=E && (alfas-betas)<=E && (betas-gamas)<=E && (alfas-gamas)<=E){
	    printf("Jednakostranicni\n");
	    printf ("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
	    return 1;
	}
	else if((fabs(a-b)<=E && c!=a) || (fabs(a-c)<=E && b!=a) || (fabs(b-c)<=E && a!=b)){
	    printf("Jednakokraki\n");
	}
	else if ((fabs(alfas-90)<=E && fabs(b-c)<=E) || (fabs(betas-90)<=E && fabs(a-c)<=E) || (fabs(gamas-90)<=E && fabs(a-b)<=E)){
	    printf("Pravougli\n");
	    printf("Jednakokraki\n");
	    printf ("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.\n");
	    return 1;
	}
	else if(fabs(alfas-gamas)>E && fabs(alfas-betas)>E && fabs(betas-gamas)>E){
	    printf("Raznostranicni\n");
	}
	
	int sec, min, deg, x;
	double maxugao;
	if(alfas>betas && alfas>gamas){
	maxugao=alfas;	
	} 
	
	else if(betas>alfas && betas>gamas)
	{
		maxugao=betas;
	}
	else maxugao=gamas;
	
	x=maxugao*3600;
	int ukupnesec=(x);
	sec=ukupnesec%60;
	ukupnesec/=60;
	min=ukupnesec%60;
	ukupnesec/=60;
	deg=ukupnesec;
	
	printf ("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", deg, min, sec);
	
	return 0;
	
}
