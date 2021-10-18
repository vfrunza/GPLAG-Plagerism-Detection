#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265
#define EPSILON  0.0001
int main() {
	
	double x1,x2,x3,y1,y2,y3,a,b,c,a1,a2,a3;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	a=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	b=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	c=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	
	a1=acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
	a2=acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
	a3=acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b)); 
/*linija*/	
	if(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))<EPSILON) {
		printf("Linija\n");

			printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}
/*jednakostranicni*/
	 if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON && fabs(a-c)<EPSILON) {
		printf("Jednakostranicni\n");
			
		if (fabs(a1-a2)<EPSILON && fabs(a1-a3)<EPSILON && fabs(a2-a3)<EPSILON){
			
		
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.\n");
	}
	}
/*pravougli*/	
 if(fabs(a*a-(b*b+c*c))<EPSILON || fabs(b*b-(a*a+c*c))<EPSILON || fabs(c*c-(a*a+b*b))<EPSILON) {
		printf("Pravougli\n");
	if(fabs(a-b)<EPSILON || fabs(a-c)<EPSILON || fabs(b-c)<EPSILON) {
		printf("Jednakokraki\n");
		if(a1>=a2 && a1>=a3) {
			double ugao,minute,sekunde,ugao1,stepeni,minute1,sekunde1;
				
			ugao=a1;
			ugao1=(ugao*180)/PI;
			stepeni=(int)ugao1;
			minute=(ugao1-stepeni)*60;
			minute1=(int)minute;
			sekunde=(minute-minute1)*60;
			sekunde1=(int)sekunde;
			
		printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.\n", stepeni,minute1,sekunde1);
	}
	
	 if(a2>=a1 && a2>=a3) {
			double ugao,minute,sekunde,ugao2,stepeni,minute1,sekunde1;
		
			ugao=a2;
			ugao2=(ugao*180)/PI;
			stepeni=(int)ugao2;
			minute=(ugao2-stepeni)*60;
			minute1=(int)minute;
			sekunde=(minute-minute1)*60;
			sekunde1=(int)sekunde;
			
		printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", stepeni,minute1,sekunde1);
	}
		 if(a3>=a2 && a3>=a1) {
			double ugao,minute,sekunde,ugao3,stepeni,minute1,sekunde1;
			ugao=a3;
			ugao3=(ugao*180)/PI;
			stepeni=(int)ugao3;
			minute=(ugao3-stepeni)*60;
			minute1=(int)minute;
			sekunde=(minute-minute1)*60;
			sekunde1=(int)sekunde;
			
		printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", stepeni,minute1,sekunde1);
		}
		}
	}

			/*Raznostranicni*/
		  if(fabs(a-b)>=EPSILON && fabs(b-c)>=EPSILON && fabs(a-c)>=EPSILON) {
			printf("Raznostranicni\n");
					if(a1>a2 && a1>a3) {
			double ugao,minute,sekunde,ugao1,stepeni,minute1,sekunde1;
				
			ugao=a1;
			ugao1=(ugao*180)/PI;
			stepeni=(int)ugao1;
			minute=(ugao1-stepeni)*60;
			minute1=(int)minute;
			sekunde=(minute-minute1)*60;
			sekunde1=(int)sekunde;
			
		printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.\n", stepeni,minute1,sekunde1);
	}
	
	 if(a2>a1 && a2>a3) {
			double ugao,minute,sekunde,ugao2,stepeni,minute1,sekunde1;
			ugao=a2;
			ugao2=(ugao*180)/PI;
			stepeni=(int)ugao2;
			minute=(ugao2-stepeni)*60;
			minute1=(int)minute;
			sekunde=(minute-minute1)*60;
			sekunde1=(int)sekunde;
			
		printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", stepeni,minute1,sekunde1);
	}
		 if(a3>a1 && a3>a2) {
			double ugao,minute,sekunde,ugao3,stepeni,minute1,sekunde1;
			ugao=a3;
			ugao3=(ugao*180)/PI;
			stepeni=(int)ugao3;
			minute=(ugao3-stepeni)*60;
			minute1=(int)minute;
			sekunde=(minute-minute1)*60;
			sekunde1=(int)sekunde;
				printf("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", stepeni,minute1,sekunde1);
		}
		 }
	return 0;
}
