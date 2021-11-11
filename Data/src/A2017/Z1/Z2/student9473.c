#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265
int main() {
	int UGA,UGB,UGC,minA2,sekA2,minB2,sekB2,minC2,sekC2,UGD,UGF,minD2,sekD2,minF2,sekF2;
	double x1,y1,x2,y2,x3,y3,a,b,c,d1,d2,d3,e,f,A,B,C,cA,cB,cC,UA,UB,UC,minA,minA1,sekA,sekA1,minB,minB1,sekB,sekB1,minC,minC1,sekC,sekC1,minD,minD1,sekD,sekD1,minF,minF1,sekF,sekF1;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	b=sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
	c=sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
	d1=a*a + b*b;
	d2=a*a+c*c;
	d3=b*b+c*c;
	e=((x2-x1)*(y3-y1));
	f=((y2-y1)*(x3-x1));
	
	if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON) printf("Jednakostranicni\n");
	if(fabs(d1-c*c)<EPSILON || fabs(d2-b*b)<EPSILON || fabs(d3-a*a)<EPSILON) printf("Pravougli\n");
    if ((fabs(a-b)<EPSILON && (fabs(b-c)>EPSILON)) || ((fabs(b-c)<EPSILON) && (fabs(b-a)>EPSILON)) || (((fabs(a-c)<EPSILON) && (fabs(a-b)>EPSILON )) && (fabs(e-f)>EPSILON))) printf("Jednakokraki\n");
	if (fabs(e-f)<EPSILON) printf("Linija\n");
	if(fabs(a-b)>EPSILON && fabs(b-c)>EPSILON && fabs(a-c)>EPSILON) printf("Raznostranicni\n");
	A=(c*c+b*b-a*a)/(2*b*c);
	B=(a*a+c*c-b*b)/(2*a*c);
	C=(a*a+b*b-c*c)/(2*a*b);
	cA=acos(A);
	cB=acos(B);
	cC=acos(C);
	UA=(cA*180.0)/(PI);
	UB=(cB*180.0)/(PI);
	UC=(cC*180.0)/(PI);
	if(fabs(UA-UB)<EPSILON && fabs(UA-UC)<EPSILON) printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	else if (fabs(UA-UB)>EPSILON && (UA-UB)>0 && fabs(UA-UC)>EPSILON && (UA-UC)>0)
	{ 
		UGA=UA;
		minA=UA-UGA;
		minA1=minA*60;
		minA2=minA1;
		sekA=minA1-minA2;
		sekA1=sekA*60;
		sekA2=sekA1;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",UGA,minA2,sekA2);
		}
	else if (fabs(UB-UA)>EPSILON && (UB-UA)>0 && fabs(UB-UC)>EPSILON && (UB-UC)>0)
	{
		UGB=UB;
		minB=UB-UGB;
		minB1=minB*60;
		minB2=minB1;
		sekB=minB1-minB2;
		sekB1=sekB*60;
		sekB2=sekB1;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",UGB,minB2,sekB2);
	}
	else if(fabs(UC-UA)>EPSILON && (UC-UA)>0 && fabs(UC-UB)>EPSILON && (UC-UB)>0)
	{
		UGC=UC;
		minC=UC-UGC;
		minC1=minC*60;
		minC2=minC1;
		sekC=minC1-minC2;
		sekC1=sekC*60;
		sekC2=sekC1;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",UGC,minC2,sekC2);
	}
	else if((fabs(UA-UC)<EPSILON) || (fabs(UA-UB)<EPSILON))
    {
    	UGD=UA;
    	minD=UA-UGD;
    	minD1=minD*60;
    	minD2=minD1;
    	sekD=minD1-minD2;
    	sekD1=sekD*60;
    	sekD2=sekD1;
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",UGD,minD2,sekD2);
    }
    else if(fabs(UB-UC)<EPSILON)
    {
    	UGF=UB;
    	minF=UB-UGF;
    	minF1=minF*60;
		minF2=minF1;
		sekF=minF1-minF2;
		sekF1=sekF*60;
		sekF2=sekF1;
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",UGF,minF2,sekF2);
    }

	return 0;
}
