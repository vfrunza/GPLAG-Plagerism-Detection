#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#define e 0.0001
#define PI1 180

int main()
{
	double x1,x2,x3,y1,y2,y3,a,b,c,alfa,beta,gama,maksimalniugao;
	int ukupnesekunde,stepen,minute,sekunde;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf%lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf%lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf%lf", &x3,&y3);

	a=sqrt(pow(x2-x1,2) + pow(y2-y1,2));
	b=sqrt(pow(x3-x2,2) + pow(y3-y2,2));
	c=sqrt(pow(x3-x1,2) + pow(y3-y1,2));


    alfa=(acos((pow(c,2) + pow(b,2) - pow(a,2))/(2*c*b))*(180/PI));
    beta=(acos((pow(c,2) + pow(a,2) - pow(b,2))/(2*c*a))*(180/PI));
    gama=180.0-alfa-beta;
    
    if(alfa>beta && alfa>gama) maksimalniugao=alfa;
    else if(beta>alfa && beta>gama) maksimalniugao=beta;
    else maksimalniugao=gama;
    
   
    
    if(fabs(maksimalniugao-90)<e)
    printf("Pravougli\n");
    


	if(fabs(alfa-180)<e || fabs(beta-180)<e || fabs(gama-180)<e )
		printf("Linija");
		 else if (fabs(a-b)<e && fabs(b-c)>e || fabs(a-c)<e && fabs(a-b)>e || fabs(b-c)<e && fabs(a-c)>e){
		 printf("Jednakokraki");}
		 else if(fabs(a-b)<e  && (fabs(b-c)<e) && fabs(a-c)<e)
		printf("Jednakostranicni");
		else 
		printf("Raznostranicni");
		

		
		
	maksimalniugao+=e;	
    ukupnesekunde=(int)(maksimalniugao*3600);
    sekunde=ukupnesekunde%60;
    ukupnesekunde/=60;
    minute=ukupnesekunde%60;
    ukupnesekunde/=60;
    stepen=ukupnesekunde;
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen, minute ,sekunde);
		
	return 0 ;
	
	
}
