#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.14159265359

int main() {
	double x1,x2,x3,y1,y2,y3;
	double P,a,b,c,A,B,C,MAXUgao;
	int minute,sekunde,stepeni,ukupnosekundi;
 	int alfa,beta,gama;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	P=(1./2)*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	//fabs funckija koja racuna apsolutnu vrijednost
	a=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	b=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
	c=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
	A=acos((b*b+c*c-a*a)/(2*b*c));
	B=acos((a*a+c*c-b*b)/(2*a*c));
	C=acos((a*a+b*b-c*c)/(2*b*a));
	A=A*180./PI;
	B=B*180./PI; 
	C=C*180./PI;
	if(A>B && A>C) MAXUgao=A;
	else if(B>A && B>C) MAXUgao=B; 
	else if(C>A && C>B) MAXUgao=C;
	alfa=(int)round(A*1000)/1000;
	beta=(int)round(B*1000)/1000;
	gama=(int)round(C*1000)/1000;
	
	if ((P+e)>=0 && (P-e)<=0)
	{
		printf("Linija\n");
	
		ukupnosekundi=(int)round(MAXUgao*(3600)*1000)/1000;
	
		sekunde=ukupnosekundi%60;
		minute=(ukupnosekundi/60)%60;
		stepeni=ukupnosekundi/(3600);
		
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	}
	else
	{
		//((a>=(b+e) && a<=(b-e)) || (a>=(c+e) && a<=(c-e)) || (b>=(c+e) && b<=(c-e))) raznostranicni
		if((MAXUgao+e)>=90 && (MAXUgao-e)<=90 ) printf("Pravougli\n");
		if (alfa!=beta && alfa!=gama) printf("Raznostranicni\n");
		//else if(((a+e)>=b &&(a-e)<=b )&& ((a+e)>=c && (a-e)<=c)) printf("Jednakostranicni\n");
		else if(alfa==beta && alfa==gama) printf("Jednakostranicni\n");
		else printf("Jednakokraki\n");
		
		ukupnosekundi=(int)round(MAXUgao*(3600)*1000)/1000;
	
		sekunde=ukupnosekundi%60;
		minute=(ukupnosekundi/60)%60;
		stepeni=ukupnosekundi/(60*60);
		
		
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	}
	return 0;
}
