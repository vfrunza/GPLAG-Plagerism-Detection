#include <stdio.h>
#include <math.h>
#define PI 3.14
#define epsilon  0.0001

int main()
		{
			double a,b,c,x1,x2,x3,y1,y2,y3,k1,k2,k3,UGAO1,UGAO2,UGAO3,MAX;
			int MS,stepeni,minute,sekunde,T=1;
			
			
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);

	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);

	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
			
			k1=(fabs((x1-x2)*(x1-x2)) + fabs((y1-y2)*(y1-y2)));
			k2=(fabs((x2-x3)*(x2-x3)) + fabs((y2-y3)*(y2-y3)));
			k3=(fabs((x3-x1)*(x3-x1)) + fabs((y3-y1)*(y3-y1)));
			
			a=sqrt(k1);
			b=sqrt(k2);
			c=sqrt(k3);
			
			
			
			
			
			UGAO1=acos((b*b+c*c-a*a)/(2*b*c));
	
			UGAO2=acos((a*a+c*c-b*b)/(2*c*a));
			UGAO3=acos((a*a+b*b-c*c)/(2*a*b));
			
			
			
			
			if(fabs((b*b+c*c)-a*a)<epsilon || fabs((a*a+c*c)-b*b)<epsilon || fabs((a*a+b*b)-c*c)<epsilon) {
				printf("Pravougli \n");
			}
			
			
			
			
			
			if(fabs(b-a)<epsilon && fabs(b-c)<epsilon) {
				printf("Jednakostranicni \n");
			}
			
			if(fabs((a+c)-b)<epsilon || fabs((a+b)-c)<epsilon || fabs((b+c)-a)<epsilon) {
				T=0;
				printf("Linija \n");
			}
			
			
			
			if(((fabs(a-b)<epsilon && fabs(a-c)>epsilon && fabs(b-c)>epsilon) || (fabs(a-c)<epsilon && fabs(a-b)>epsilon && fabs(b-c)>epsilon) || (fabs(b-c)<epsilon && fabs(a-c)>epsilon && fabs(a-b)>epsilon)) && (T==1)) {
				printf("Jednakokraki \n");
				
			}
			
			if(fabs(b-c)>epsilon && fabs(a-c)>epsilon && fabs(a-b)>epsilon) { 
				printf("Raznostranicni \n");
			}
			
			if((UGAO3>UGAO1) && (UGAO3>UGAO2)) {
				MAX=UGAO3;
			}
			if((UGAO2>UGAO1) && (UGAO2>UGAO3)) {
				MAX=UGAO2;
			}
			if((UGAO1>UGAO2) && (UGAO1>UGAO3)) {
				MAX=UGAO1;
			}
			
				MS = (MAX * 360 * 60 * 60 / (2 *M_PI));
	sekunde = MS % 60;
	minute = (MS / 60) % 60;
	stepeni = MS / (60 * 60);

			
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", stepeni,minute,sekunde);
			return 0;
		}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			