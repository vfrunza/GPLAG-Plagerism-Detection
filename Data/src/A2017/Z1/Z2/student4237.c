#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.1415926

int main() {
	
	double x1,x2,x3,y1,y2,y3,d1,d2,d3,u1,u2,u3,stepen,minuta,sekunda;

	
		printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	
	 	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	
		printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	d1=sqrt(fabs((x2-x1)*(x2-x1))+fabs((y2-y1)*(y2-y1)));
	
	d2=sqrt(fabs((x3-x1)*(x3-x1))+fabs((y3-y1)*(y3-y1)));
	
	d3=sqrt(fabs((x3-x2)*(x3-x2))+fabs((y3-y2)*(y3-y2)));
	
	u1=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2))*(180/PI);
	
	u2=acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3))*(180/PI);
	
	u3=acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3))*(180/PI);
	

	if((fabs(x1-x2)<e && fabs(x2-x3)<e && fabs(x3-x1)<e) || (fabs(y1-y2)<e && fabs(y2-y3)<e && fabs(y1-y3)<e)  || (fabs((x2-x1)-(x3-x2))<e && fabs((y2-y1)-(y3-y2))<e)) {
	    	printf("Linija");
	    	printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	    }
	else if (fabs(d1-d2)<e && fabs(d1-d3)<e && fabs(d2-d3)<e) {
		printf("Jednakostranicni");
		printf("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	     }
   	else if((fabs(d1-d2)<e) || (fabs(d2-d3)<e) || (fabs(d3-d1)<e)) {
			if(fabs(d1*d1+d2*d2-d3*d2)<e || fabs(d2*d2+d3*d3-d1*d1)<e || fabs(d3*d3+d1*d1-d2*d2)<e ) {
				printf("Pravougli");
				printf("\nJednakokraki");
				printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
			}
			
			else {
				printf("Jednakokraki");
				 
				 
				 if(u1>=u2 && u1>=u3) {
				 	   stepen = (int)(u1);
	                   minuta=(int)((u1-(int)(u1))*60);
	                   sekunda=(int)((u1-(int)(u1)-minuta/60)*3600);
				 	printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",stepen,minuta,sekunda);
				 }
				 	else if(u2>=u3 && u2>=u1) {
				 	   stepen = (int)(u2);
	                    minuta=(int)((u2-(int)(u2))*60);
	                   sekunda=(int)((u2-(int)(u2)-minuta/60)*3600);
				 		printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",stepen,minuta,sekunda);
				 }
				 	else if(u3>=u1 && u3>=u2) {
				 		   stepen = (int)(u3);
	                   minuta=(int)((u3-(int)(u3))*60);
	                   sekunda=(int)((u3-(int)(u3)-minuta/60)*3600);
				 		printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",stepen,minuta,sekunda);
				 }
			 }
		}
			
	else if((fabs(d1-d2)>e) && (fabs(d2-d3)>e) && (fabs(d3-d1)>e)) {
		  	if(fabs(d1*d1+d2*d2-d3*d2)<e || fabs(d2*d2+d3*d3-d1*d1)<e || fabs(d3*d3+d1*d1-d2*d2)<e) {
				printf("Pravougli");
				printf("\nRaznostranicni");
				printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
			}
			else {
				printf("Raznostranicni");
				 if(u1>=u2 && u1>=u3) {
				 	 stepen = (int)(u1);
	                   minuta=(int)((u1-(int)(u1))*60);
	                   sekunda=(int)((u1-(int)(u1)-minuta/60)*3600);
				 	printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",stepen,minuta,sekunda);
				 }
				 	else if(u2>=u3 && u2>=u1) {
				 		 stepen = (int)(u2);
	                   minuta=(int)((u2-(int)(u2))*60);
	                   sekunda=(int)((u2-(int)(u2)-minuta/60)*3600);
				 		printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",stepen,minuta,sekunda);
				 }
				 	else if(u3>=u1 && u3>=u2) {
				 		 stepen = (int)(u3);
	                   minuta=(int)((u3-(int)(u3))*60);
	                   sekunda=(int)((u3-(int)(u3)-minuta/60)*3600);
				 		printf("\nNajveci ugao ima %.f stepeni, %.f minuta i %.f sekundi.",stepen,minuta,sekunda);
				 }
			}
		}
		
	else if(fabs(d1*d1+d2*d2-d3*d2)<e || fabs(d2*d2+d3*d3-d1*d1)<e || fabs(d3*d3+d1*d1-d2*d2)<e) {
		 printf("Pravougli");
		 printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	}

	return 0;
}
