#include <stdio.h>
#include <math.h>
#define e 0.0001
#define k 180/3.14159265359

int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,u1,u2,u3,P,maxugao;
	int ukupnesekunde,sekunde,minute,stepeni;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);

	c=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	b=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	a=sqrt(pow((x3-x2),2)+pow((y3-y2),2));

	u1=acos(((b*b)+(c*c)-(a*a))/((2*b*c)))*k;
	u2=acos(((a*a)+(c*c)-(b*b))/((2*a*c)))*k;
	u3=acos(((a*a)+(b*b)-(c*c))/((2*a*b)))*k;

	P=fabs(((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2))))/2;
        
    if((P-0)<e) 
	printf("Linija\n");
	
	else{
		
			if ((fabs(pow(a,2)+pow(b,2)-pow(c,2))<e)||(fabs(pow(c,2)+pow(a,2)-pow(b,2))<e)||(fabs(pow(b,2)+pow(c,2)-pow(a,2))<e))
			printf("Pravougli\n");
			
			if ((fabs(b-a)<e)&&(fabs(a-c)<e)&&(fabs(c-b)<e))
			printf("Jednakostranicni\n");
		
			else if ((fabs(b-a)<e)||(fabs(a-c)<e)||(fabs(c-b)<e))
			printf("Jednakokraki\n");
		
			else //if ((fabs(b-a)>e)&&(fabs(a-c)>e)&&(fabs(c-b)>e))
			printf("Raznostranicni\n");
			
	}
	
	if (u1>u2 && u1>u3)
		maxugao=u1;

	else if (u2>u1 && u2>u3)
		maxugao=u2;

	else if (u3>u2 && u3>u2)
		maxugao=u3;

		maxugao+=e; //dodajemo mu e da bi nadoknadili "gresku"
		ukupnesekunde=maxugao*3600; 
		sekunde=ukupnesekunde%60; //% predstavlja ostatak dijeljenja brojem
		ukupnesekunde=ukupnesekunde/60;
		minute=ukupnesekunde%60;
		ukupnesekunde=ukupnesekunde/60;
		stepeni=ukupnesekunde;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	
	
	return 0;
}
