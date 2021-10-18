#include <stdio.h>
#include<math.h>
#define PI 3.14159
#define EPSILON 0.001

int main() {
	int Stepen,Minuta,Sekunda;
	double x1,y1,x2,y2,x3,y3,d1,d2,d3,A,pomocna1,Ostatak1,Ostatak2,pomocna2;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
    printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	d1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	d3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	if (((d1+d2)<=d3) || ((d2+d3)<=d1) || ((d1+d3)<=d2))
	{
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}

  else if ((fabs(d1-d2)<EPSILON) && (fabs(d1-d3)<EPSILON) && (fabs(d2-d3)<EPSILON))
	{
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}

else if( ( fabs((d1*d1)-(d2*d2+d3*d3))<EPSILON || fabs((d2*d2)-(d3*d3+d1*d1))<EPSILON  || fabs((d3*d3)-(d1*d1+d2*d2))<EPSILON) && ( fabs(d1-d2)<EPSILON || fabs(d2-d3)<EPSILON || fabs(d3-d1)<EPSILON )  )
	{  
		printf("Pravougli\n");
		printf("Jednakokraki\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	}
	
  else if ((fabs(d1-d2)<EPSILON) || (fabs(d2-d3)<EPSILON) || (fabs(d1-d3)<EPSILON))
	{
		printf("Jednakokraki\n");
		if ((d1>=d2) && (d1>=d3))
		{
			A=acos((d1*d1-d2*d2-d3*d3)/(-2*d2*d3));
			pomocna1=A*180/PI;
			Stepen=pomocna1;
			Ostatak1=pomocna1-Stepen;
			pomocna2=Ostatak1*60;
			Minuta=Ostatak1*60;
			Ostatak2=pomocna2-Minuta;
			Sekunda=Ostatak2*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",Stepen,Minuta,Sekunda);
		}
		else if ((d2>=d1) && (d2>=d3))
		{
			A=acos((d2*d2-d1*d1-d3*d3)/(-2*d1*d3));
			pomocna1=A*180/PI;
			Stepen=pomocna1;
			Ostatak1=pomocna1-Stepen;
			pomocna2=Ostatak1*60;
			Minuta=Ostatak1*60;
			Ostatak2=pomocna2-Minuta;
			Sekunda=Ostatak2*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",Stepen,Minuta,Sekunda);
		}
		else if ((d3>=d1) && (d3>=d2))
		{
			A=acos((d3*d3-d1*d1-d2*d2)/(-2*d1*d2));
			pomocna1=A*180/PI;
			Stepen=pomocna1;
			Ostatak1=pomocna1-Stepen;
			pomocna2=Ostatak1*60;
			Minuta=Ostatak1*60;
			Ostatak2=pomocna2-Minuta;
			Sekunda=Ostatak2*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",Stepen,Minuta,Sekunda);	
		}
	}

	
		else if (((fabs((d1*d1)-(d3*d3+d2*d2))<EPSILON) || (fabs((d2*d2)-(d1*d1+d3*d3))<EPSILON) || (fabs((d3*d3)-(d1*d1+d2*d2)))<EPSILON) && (fabs(d1-d2)>EPSILON) && (fabs(d1-d3)>EPSILON) && (fabs(d2-d3)>EPSILON))
	{
		printf("Pravougli\n");
		printf("Raznostranicni\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	}
		else if ((fabs((d1*d1)-(d3*d3+d2*d2))<EPSILON) || (fabs((d2*d2)-(d1*d1+d3*d3))<EPSILON) || (fabs((d3*d3)-(d1*d1+d2*d2))<EPSILON))
	{
		printf("Pravougli\n");
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	}
	
	
	else if (fabs(d1-d2)>EPSILON && fabs(d1-d3)>EPSILON && fabs(d2-d3)>EPSILON)
	{
		printf("Raznostranicni\n");
		if((d1>d2)&&(d1>d3))
		{
			A=acos((d1*d1-d2*d2-d3*d3)/(-2*d2*d3));
			pomocna1=A*180/PI;
			Stepen=pomocna1;
			Ostatak1=pomocna1-Stepen;
			pomocna2=Ostatak1*60;
			Minuta=Ostatak1*60;
			Ostatak2=pomocna2-Minuta;
			Sekunda=Ostatak2*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",Stepen,Minuta,Sekunda);
		}
		else if ((d2>d1)&&(d2>d3))
		{
			A=acos((d2*d2-d1*d1-d3*d3)/(-2*d1*d3));
			pomocna1=A*180/PI;
			Stepen=pomocna1;
			Ostatak1=pomocna1-Stepen;
			pomocna2=Ostatak1*60;
			Minuta=Ostatak1*60;
			Ostatak2=pomocna2-Minuta;
			Sekunda=Ostatak2*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",Stepen,Minuta,Sekunda);
		}
		else if ((d3>d2)&&(d3>d1))
		{
			A=acos((d3*d3-d2*d2-d1*d1)/(-2*d2*d1));
			pomocna1=A*180/PI;
			Stepen=pomocna1;
			Ostatak1=pomocna1-Stepen;
			pomocna2=Ostatak1*60;
			Minuta=Ostatak1*60;
			Ostatak2=pomocna2-Minuta;
			Sekunda=Ostatak2*60;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",Stepen,Minuta,Sekunda);
		}
	}
	return 0;
}
