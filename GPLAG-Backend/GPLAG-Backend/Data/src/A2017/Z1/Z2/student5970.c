#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define EPSILON 0.0001
int main()
{ 
	double a,b,c,x1,x2,x3,y1,y2,y3,alfa,u,i,m,s;
	double alfa1,beta2,gama3;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lg""%lg",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lg""%lg",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lg""%lg",&x3,&y3);
	
	a=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	b=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	c=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	
if  ((a+b)>c || (b+c)>a || (a+c)>b)
{	
	if (c<a && b<a){
	alfa=acos((b*b+c*c-a*a)/2*b*c);
	u=alfa*(180/PI);

	if (fabs(u-90)<=EPSILON)
	{
		u=90;
		printf ("Pravougli \n");
		i=u;
		m=0;
		s=0;
	}
	else{//zaokruzivanje za stepen //
	i=u-(int)u; 
	//zaokruzivanje u min//
	m=(int)i*60;
	i=i*60-(int)i*60;
	// ostatak za sec//
	s=(int)m*60;
 	//uslovi1 //
 	alfa1=fabs(a-b);
 	beta2=fabs(b-c);
 	gama3=fabs(a-c);
 	
 	if (a==b && b==c && a==c){
     	    printf ("Linija");}
	else if (alfa1<=EPSILON && beta2<= EPSILON){
	        printf("Jednakostranicni\n");}
	//else if ((alfa1 < EPSILON) || ( beta2 < EPSILON)) || (gama3<EPSILON)
    // 	{printf("Jednakokraki");}
    else printf("Raznostranicni\n");
    printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",u,m,s);
	}
		
	}
	else if (a<b && b>c)
    {
		alfa=acos((b*b+c*c-a*a)/2*b*c);
	u=alfa*(180/PI); 

	if (fabs(u-90)<=EPSILON)
	{
		u=90;
		printf ("Pravougli \n");
		i=u;
		m=0;
		s=0;

	}
	else{
	//zaokruzivanje za stepen //
		i=u-(int)u; 
	//zaokruzivanje u min//
		m=(int)i*60;
		i=i*60-(int)i*60;
	// ostatak za sec//
		s=(int)m*60;
 	//uslovi2 //
 	    if (a==b && b==c && a==c)
    	    printf ("Linija");
	    else if (fabs(a-b)<=EPSILON && fabs(b-c)<= EPSILON)
	    	printf("Jednakostranicni\n");
	    else if ((fabs(a-b)<=EPSILON) || (fabs(b-c)<= EPSILON) || (fabs(a-c)<=EPSILON))
         	printf("Jednakokraki\n");
       	else printf("Raznostranicni\n");
     
    printf("Najveci ugao ima %.lf stepeni, %.lf minuta i %.lf sekundi.",u,m,s);
	}
    	
    }
}
return 0;
}
