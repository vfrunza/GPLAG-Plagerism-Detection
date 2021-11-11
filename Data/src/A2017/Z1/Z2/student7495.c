#include <stdio.h>
#include <math.h>
#define E 0001
#define PI 3.14

int main() {
	double x1=0,x2=0,x3=0,y1=0,y2=0,y3=0,a,b,c;
    int  ugao1,ugao2,ugao3;
    int stepeni1=0,stepeni2=0,stepeni3=0,minute1=0,minute2=0,minute3=0,sekunde1=0,sekunde2=0,sekunde3=0,max=0;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1,&x2);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3,&y3);
	
	
	    a=sqrt((pow(x2-x1,2)+pow(y2-y1,2)));
		b=sqrt((pow(x3-x1,2)+pow(y3-y1,2)));
	    c=sqrt((pow(x3-x2,2)+pow(y3-y2,2)));
	    
	    ugao1=(pow(a,2)-pow(b,2)-pow(c,2))/(2*b*c);
	    ugao2=(pow(b,20)-pow(a,2)-pow(c,2))/(2*a*c);
	    ugao3=(pow(c,2)-pow(a,2)-pow(b,2))/(2*a*c);
	    
	    
	if((a-b)<E || (b-a)<E || (a-c)<E || (b-c)<E || (c-a)<E || (c-b)<E) {
	
		printf("Linija\n");
        printf("Najvecija ugao ima %d stepeni, %d minuta i %d sekundi.");
	}
	 else if ((a-b)<E && (b-a)<E && (c-a)>E && (c-b)>E) {
		
		stepeni1=(fabs(ugao1*180/PI)*(int)60);
	    stepeni2=(fabs(ugao2*180/PI)*(int)60);
	    stepeni3=(fabs(ugao3*180/PI)*(int)60);
		minute1=(fabs(stepeni1*180/PI)*(int)60);
		minute2=(fabs(stepeni2*180/PI)*(int)60);
	    minute3=(fabs(stepeni3*180/PI)*(int)60);
		sekunde1=(fabs(minute1*180/PI)*(int)60);
		sekunde2=(fabs(minute2*180/PI)*(int)60);
		sekunde3=(fabs(minute3*180/PI)*(int)60);
		printf("Jednakokraki");
		printf("Najveci ugao ima %d stepeni, %d  minute i %d sekundi\n", stepeni1, minute1, sekunde1);
	    }
	    else if(stepeni2>max) {
			printf("Najveci ugao ima %d stepeni, %d minute i %d sekundi\n", stepeni2, minute2, sekunde2);
		}
		else if(stepeni3>max){
			printf("Najveci ugao ima %d stepeni, %d minute i %d sekundi\n", stepeni3, minute3, sekunde3);
		
		
		}
	    else if((c>a) || (b>a) || (b>c) || (a>c) || (a>b) || (c>b)) {
    
    	stepeni1=(fabs(ugao1*180/PI)*(int)60);
	    stepeni2=(fabs(ugao2*180/PI)*(int)60);
	    stepeni3=(fabs(ugao3*180/PI)*(int)60);
		minute1=(fabs(stepeni1*180/PI)*(int)60);
		minute2=(fabs(stepeni2*180/PI)*(int)60);
	    minute3=(fabs(stepeni3*180/PI)*(int)60);
		sekunde1=(fabs(minute1*180/PI)*(int)60);
		sekunde2=(fabs(minute2*180/PI)*(int)60);
		sekunde3=(fabs(minute3*180/PI)*(int)60);
		max=(ugao1>E || ugao2>E || ugao3>E);
    	printf("Raznostranicni");
    	printf("Najveci ugao ima %d stepeni, %d minute i %d sekundi\n", stepeni1, minute1, sekunde1);
    }
    	 else if(stepeni2>max) {
			printf("Najveci ugao ima %d stepeni, %d minute i %d sekundi\n", stepeni2, minute2, sekunde2);
		}
		else if(stepeni3>max){
			printf("Najveci ugao ima %d stepeni, %d minute i %d sekundi\n", stepeni3, minute3, sekunde3);
		}
    
     else if ((a>b && a>c) || (b>c && b>a) || (c>a && c>b)) {
    	
        ugao1=90;
		stepeni1=(fabs(ugao1*180/PI)*(int)60);
		minute1=(fabs(stepeni1*180/PI)*(int)60);
		sekunde1=(fabs(minute1*180/PI)*(int)60);
    	printf("Pravougli");
    	printf("Najveci ugao ima %d stepeni, %d minute i %d sekundi\n ",ugao1, minute1, sekunde1);
    }
    
    
    else if((a>=a) && (b>=c)) {
       ugao1=60;
       stepeni1=(fabs(ugao1*180/PI)*(int)60);
       minute1=(fabs(stepeni1*180/PI)*(int)60);
	   sekunde1=(fabs(minute1*180/PI)*(int)60);
       printf("Jednakostranicni");
       printf("Najveci ugao ima %d stepeni, %d minute i %d sekundi\n", ugao1, minute1,sekunde1);
 
    
       }
    
    if (((a>b && a>c) || (b>c && b>a) || (c>a && c>b))  && ((a-b)<E && (b-a)<E && (c-a)>E && (c-b)>E)){
        ugao1=90;
        ugao2=60;
    	stepeni1=(fabs(ugao1*180/PI)*(int)60);
	    stepeni2=(fabs(ugao2*180/PI)*(int)60);
		minute1=(fabs(stepeni1*180/PI)*(int)60);
		minute2=(fabs(stepeni2*180/PI)*(int)60);
		sekunde1=(fabs(minute1*180/PI)*(int)60);
		sekunde2=(fabs(minute2*180/PI)*(int)60);
    	printf("Pravougli\n");
    	printf("Jednakokraki\n");
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi\n", ugao1, minute1, sekunde1);
        printf("Najveci ugao ima %d stepeni, %d minute i %d sekundi\n", ugao2, minute2, sekunde2);
		}

 
	return 0;
}
