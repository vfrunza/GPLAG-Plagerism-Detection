#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define EPSILON 0.0001



int main() {
	double t1x,t1y,t2x,t2y,t3x,t3y,povrsina,a,b,c,alfa,beta,gama,max;
	int stepeni, minute, sekunde;
	const double PI=3.14159265;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &t1x, &t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &t2x, &t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &t3x, &t3y);
	povrsina=1./2.*(fabs(t1x*(t2y-t3y)+t2x*(t3y-t1y)+t3x*(t1y-t2y)));
	
	a=sqrt(pow((t3x-t2x),2)+pow((t3y-t2y),2));
	b=sqrt(pow((t3x-t1x),2)+pow((t3y-t1y),2));
	c=sqrt(pow((t2x-t1x),2)+pow((t2y-t1y),2));
	
	
	if(povrsina==0){ printf("Linija\n");}
	else if((fabs(a-b)<EPSILON) && (fabs(a-c)<EPSILON) && (fabs(b-c)<EPSILON)){ printf("Jednakostranicni\n");}
	else if( ((fabs((a*a+b*b)-c*c)<EPSILON ) || (fabs((b*b+c*c)-a*a)<EPSILON) || (fabs((a*a+c*c)-b*b)<EPSILON)) && ((fabs(a-b)<EPSILON) || (fabs(a-c)<EPSILON) || (fabs(b-c)<EPSILON))){printf("Pravougli\nJednakokraki\n");  }
	else if( ((fabs((a*a+b*b)-c*c)<EPSILON ) || (fabs((b*b+c*c)-a*a)<EPSILON) || (fabs((a*a+c*c)-b*b)<EPSILON)) && ((fabs(a-b)>EPSILON) || (fabs(a-c)>EPSILON) || (fabs(b-c)>EPSILON))){printf("Pravougli\nRaznostranicni\n");  }   
	else if( (fabs((a*a+b*b)-c*c)<EPSILON ) || (fabs((b*b+c*c)-a*a)<EPSILON) || (fabs((a*a+c*c)-b*b)<EPSILON)) {printf("Pravougli\n");}
	else if((fabs(a-b)<EPSILON) || (fabs(a-c)<EPSILON) || (fabs(b-c)<EPSILON)){ printf("Jednakokraki\n");}
	  
	else printf("Raznostranicni\n");
	
	alfa=acos( (b*b+c*c-a*a)/(2*b*c) );
	beta=acos( (a*a+c*c-b*b)/(2*a*c));
	gama=acos((a*a+b*b-c*c)/(2*a*b));
	
	if(alfa>beta && alfa>gama) max=alfa;
	else if(beta>alfa && beta>gama ) max=beta;
	else max=gama;
	
	max=max*180/PI;
	stepeni=(int)max;
	minute=(int)((max-stepeni)*3600)/60;
	sekunde=(int)((max-stepeni)*3600)%60;
	
	
	
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni, minute, sekunde);
	
	
	
	return 0;
}
