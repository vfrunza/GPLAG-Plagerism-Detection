#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define PI 3.141592653
#define STEPENI_UGLA_LINIJE 180.0
#define STEPENI_UGLA_PRAVOUGLOG_TROUGLA 90.0
#define STEPENI_UGLA_JEDNAKOSTRANICNOG_TROUGLA 60.0

#define MINUTE_UGLA 0.0
#define SEKUNDE_UGLA 0.0

int main() {
	       
	       double T1x=0.0, T1y=0.0, T2x=0.0, T2y=0.0, T3x=0.0, T3y=0.0, T1T2, T1T3, T2T3, s, A, najveciUgao, stepeniNajvecegUgla, minuteNajvecegugla,sekundeNajvecegUgla,alfa, beta, gama;
	       
	       int pravougli;
	       printf("Unesite koordinate tacke t1: ");
	       scanf("%lf %lf", &T1x, &T1y);
	       
	       
	       printf("Unesite koordinate tacke t2: ");
	       scanf("%lf %lf", &T2x, &T2y);
	       
	       
	       printf("Unesite koordinate tacke t3: ");
	       scanf("%lf %lf", &T3x, &T3y);
	       
	       T1T2 = sqrt(pow(T1x-T2x,2.0) + pow(T1y-T2y,2.0));
	       T1T3 = sqrt(pow(T1x-T3x,2.0) + pow(T1y-T3y,2.0));
	       T2T3 = sqrt(pow(T2x-T3x,2.0) + pow(T2y-T3y,2.0));
	       
	       /*Hornerova formula za povrsinu trougla*/
	       /* s-poluobim*/
	       /* A-povrsina trougla*/
	       
	        s= 0.5 * (T1T2 + T1T3 + T2T3);
	        A= sqrt (s * (s-T1T2) * (s-T1T3) * (s-T2T3));
	       
	       najveciUgao=0.0;
	       stepeniNajvecegUgla=0.0;
	       minuteNajvecegugla=0.0;
	       sekundeNajvecegUgla=0.0;
	       
	       if (A < EPSILON)
	      {
	      	stepeniNajvecegUgla=STEPENI_UGLA_LINIJE;
	      	minuteNajvecegugla=MINUTE_UGLA;
	      	sekundeNajvecegUgla=SEKUNDE_UGLA;
	      	printf("Linija");
	      	
	      }
	     else 
	     {
	      pravougli=0;
	      alfa=0.0;
	      beta=0.0;
	      gama=0.0;
	     	if (fabs(pow(T2T3,2.0) - pow(T1T2,2.0) - pow(T1T3,2.0))< EPSILON || fabs(pow(T1T3,2.0) - pow(T1T2,2.0)- pow(T2T3,2.0))<EPSILON || fabs(pow(T1T2,2.0) - pow(T1T3,2.0) - pow(T2T3,2.0))<EPSILON)
	    { 
	    	pravougli = 1;
	    	stepeniNajvecegUgla=STEPENI_UGLA_PRAVOUGLOG_TROUGLA;
	    	minuteNajvecegugla=MINUTE_UGLA;
	    	sekundeNajvecegUgla=SEKUNDE_UGLA;
	    	printf("Pravougli");
	    	printf("\n");
	    }
	    if ((fabs(T1T2-T1T3) < EPSILON && fabs (T1T2-T2T3) > EPSILON) || (fabs(T1T2-T2T3)<EPSILON && fabs(T1T2-T1T3) >EPSILON || (fabs(T1T3-T2T3)<EPSILON && fabs(T1T3-T1T2)>EPSILON))                                         )
	    { 
	    	if (pravougli==1)
	    	printf("\n");
	    	
	    	else 
	    	{
	    	
	    	alfa = acos((pow(T2T3,2.0) + pow(T1T3,2.0) - pow(T1T2,2.0)) / (2.0 * T2T3 *T1T3))  * (180.0/PI);
	    	beta = acos((pow(T1T2,2.0) + pow(T1T3,2.0) - pow(T2T3,2.0)) / (2.0 * T1T2 * T1T3)) * (180.0/PI);
	    	gama = acos((pow(T1T2,2.0) + pow(T2T3,2.0) - pow(T1T3,2.0)) / (2.0 * T1T2 * T2T3)) * (180.0/PI);
	    	
	    	najveciUgao=alfa;
	    	if(beta > najveciUgao)
	    	najveciUgao=beta;
	    	if (gama > najveciUgao)
	    	najveciUgao=gama;
	    	stepeniNajvecegUgla= najveciUgao;
	    	minuteNajvecegugla=(stepeniNajvecegUgla - (int)stepeniNajvecegUgla) * 60.0;
	    	sekundeNajvecegUgla= (minuteNajvecegugla- (int)minuteNajvecegugla)  * 60.0;
	    	stepeniNajvecegUgla=(int)stepeniNajvecegUgla;
	    	minuteNajvecegugla=(int)minuteNajvecegugla;
	    	sekundeNajvecegUgla=(int)sekundeNajvecegUgla;
	    		}
	    printf("Jednakokraki");
	     }
	    else if (fabs(T1T2-T1T3)<EPSILON && fabs(T1T2-T2T3)<EPSILON)
	    { 
	    	stepeniNajvecegUgla = STEPENI_UGLA_JEDNAKOSTRANICNOG_TROUGLA;
	    	minuteNajvecegugla = MINUTE_UGLA;
	    	sekundeNajvecegUgla = SEKUNDE_UGLA;
	    	printf("Jednakostranicni");
	    }
	    else
	    {
	    	alfa= acos((pow(T2T3,2.0) + pow(T1T3,2.0) - pow(T1T2,2.0)) / (2.0 * T2T3 * T1T3)) * (180.0/PI);
	    	beta=acos((pow(T1T2,2.0) + pow(T1T3,2.0) - pow(T2T3,2.0)) / (2.0 * T1T2 * T1T3)) * (180.0/PI);
	    	gama=acos((pow(T1T2,2.0) + pow(T2T3,2.0) - pow(T1T3,2.0)) / (2.0 * T1T2 * T2T3)) * (180.0/PI);
	    	najveciUgao=alfa;
	    	if(beta>najveciUgao)
	    	najveciUgao=beta;
	    	if(gama>najveciUgao)
	    	najveciUgao=gama;
	    	stepeniNajvecegUgla=najveciUgao;
	    	minuteNajvecegugla=(stepeniNajvecegUgla- (int)stepeniNajvecegUgla) * 60.0;
	    	sekundeNajvecegUgla=(minuteNajvecegugla-(int)minuteNajvecegugla) * 60.0;
	    	printf("Raznostranicni");
	    	}
	     }
	    printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", (int)stepeniNajvecegUgla, (int) minuteNajvecegugla, (int)sekundeNajvecegUgla);
	    return 0;
	     }
	
	
	
	

