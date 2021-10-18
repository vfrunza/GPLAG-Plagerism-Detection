#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.14159

int main() {
	double x1,y1,x2,y2,x3,y3;
	double d1,d2,d3;
	double U1,U2,U3;
	int step=0,s=0,min=0;
	double max =0;

	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	
	d1=sqrt((pow((x2-x1),2))+(pow((y2-y1),2)));
	d2=sqrt(pow((x3-x2),2)+(pow((y3-y2),2)));
	d3=sqrt(pow((x1-x3),2)+(pow((y1-y3),2)));
	
	
	U1=(180./PI)*acos((d2*d2+d3*d3-d1*d1)/(2*d2*d3));
	U2=(180./PI)*acos((d1*d1+d3*d3-d2*d2)/(2*d1*d3));
	U3=(180./PI)*acos((d2*d2+d1*d1-d3*d3)/(2*d2*d1));
	
    
    if(U1>U2 && U1>U3){
			max=U1;
		} else if(U2>U1 && U2>U3) {
		    max=U2;
		} else if(U3>U2 && U3>U1) {
			max=U3;
		}
      
      
      step=(int)max;
      min=(int)(max*60)%60;
      s=(int)(max*3600)%60;
      
        
        
        if(step==180) {
        	printf("Linija");
        } else {
	 if ((fabs(pow(d1,2)-(pow(d2,2)+pow(d3,2)))<e) || (fabs(pow(d2,2)-(pow(d1,2)+pow(d3,2)))<e) || (fabs((pow(d3,2))-(pow(d2,2)+pow(d1,2)))<e)){
		printf("Pravougli\n");  }
	if ((fabs(d1-d2)<e && fabs(d1-d3)>e) || (fabs(d1-d3)<e && fabs(d1-d2)>e) || (fabs(d2-d3)<e && fabs(d2-d1)>e)){
		printf("Jednakokraki");
	} else if(fabs(d1-d2)<e && fabs(d2-d3)<e){
		printf("Jednakostranicni");
	} else if (fabs(d1-d2)>e && fabs(d1-d3)>e && fabs(d3-d2)>e){
		printf("Raznostranicni"); 
	} }
      
 
			printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, s);
	
		 return 0; }
		
		
	
	
	
	