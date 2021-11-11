#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.14159265

int main() {
	double x1,x2,x3,y1,y2,y3,t1t2,t1t3,t2t3,A=0,B=0,C=0,najveciugao;
	double stepeni,minute,sekunde;
		printf("Unesite koordinate tacke t1: ");
		scanf("%lf %lf2",&x1,&y1);
		printf("Unesite koordinate tacke t2: ");
		scanf("%lf %lf",&x2,&y2);
		printf("Unesite koordinate tacke t3: ");
		scanf("%lf %lf",&x3,&y3);
			
		t1t2=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		t1t3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
		t2t3=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		
			if(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))<E){
				printf("Linija\n");	
			 }
			else if(fabs(t1t2-t1t3)<E&&fabs(t1t2-t2t3)<E){
				printf("Jednakostranicni\n");
			}else{
			
				if(fabs((t1t2*t1t2)-(t1t3*t1t3+ t2t3*t2t3))<E||(fabs((t2t3*t2t3)-(t1t3*t1t3+ t1t2*t1t2))<E)||fabs((t1t3*t1t3)-(t1t2*t1t2+ t2t3*t2t3))<E)
				printf("Pravougli\n");
				
				if(fabs(t1t2-t1t3)>E&&fabs(t1t2-t2t3)>E&&fabs(t1t3-t2t3)>E)
				printf("Raznostranicni\n");

				if((fabs(t1t2-t2t3)<E&&fabs(t1t2-t1t3)>E&&fabs(t2t3-t1t3)>E)||(fabs(t1t3-t2t3)<E&&fabs(t1t3-t1t2)>E&&(t1t2-t2t3)>E)||(fabs(t1t2-t2t3)>E&&fabs(t1t2-t1t3)<E&&fabs(t2t3-t1t3)>E))
				printf("Jednakokraki\n");
			}
		
		
		A=acos((t1t3*t1t3+t1t2*t1t2-t2t3*t2t3)/(2*t1t3*t1t2));
		B=acos((t2t3*t2t3+t1t2*t1t2-t1t3*t1t3)/(2*t2t3*t1t2));
		C=acos((t1t3*t1t3+t2t3*t2t3-t1t2*t1t2)/(2*t1t3*t2t3));
			
			najveciugao=A;
			if(A<B){
				najveciugao=B;
			}else if(B<C){
				najveciugao=C;
			}
		najveciugao=najveciugao*(180/PI);
		
		stepeni=(int)najveciugao;
		najveciugao=najveciugao-(int)najveciugao;
		najveciugao=najveciugao*60;
		minute=(int)najveciugao;
		najveciugao=najveciugao-(int)najveciugao;
		najveciugao=najveciugao*60;
		sekunde=(int)najveciugao;
	
		
		
		
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",stepeni,minute,sekunde);
			
		return 0;
	}
