#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main() {
	double t1x, t1y, t2x, t2y, t3x, t3y, d12, d23, d13, angle, minutes, seconds;
	int angleint, minutesint, secondsint;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &t1x, &t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &t2x, &t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &t3x, &t3y);
	
	d12=sqrt(pow(t2x-t1x,2)+pow(t2y-t1y,2));
	d13=sqrt(pow(t3x-t1x,2)+pow(t3y-t1y,2));
	d23=sqrt(pow(t3x-t2x,2)+pow(t3y-t2y,2));
	
	if (d12+d13==d23 || d12+d23==d13 || d13+d23==d12)
	    printf("Linija\n");
	else if ((d12>=d13*0.9999 && d12<=d13*1.0001) && (d23>=d13*0.9999 && d23<=d13*1.0001) && (d12>=d23*0.9999 && d12<=d23*1.0001))
	    printf("Jednakostranicni\n");
	else if ((pow(d12,2)+pow(d13,2)>=pow(d23,2)*0.9999 && pow(d12,2)+pow(d13,2)<=pow(d23,2)*1.0001)  || (pow(d12,2)+pow(d23,2)>=pow(d13,2)*0.9999 && pow(d12,2)+pow(d23,2)<=pow(d13,2)*1.0001) || (pow(d13,2)+pow(d23,2)>=pow(d12,2)*0.9999 && pow(d13,2)+pow(d23,2)<=pow(d12,2)*1.0001)) {
	    printf("Pravougli\n"); 
	    if ((d12>=d13*0.9999 && d12<=d13*1.0001) || (d23>=d13*0.9999 && d23<=d13*1.0001) || (d12>=d23*0.9999 && d12<=d23*1.0001))
	        printf("Jednakokraki\n");
	    else 
	    	printf("Raznostranicni\n");
	}
	else if ((d12>=d13*0.9999 && d12<=d13*1.0001) || (d23>=d13*0.9999 && d23<=d13*1.0001) || (d12>=d23*0.9999 && d12<=d23*1.0001))
	    printf("Jednakokraki\n");
	else 
	    printf("Raznostranicni\n");
	    
    if (d12>=d13 && d12>=d23) {
    	angle=(acos((pow(d13,2)+pow(d23,2)-pow(d12,2))/(2*d13*d23)))*180/(PI);
    	angleint=(int)angle;
    	minutes=(angle-angleint)*60;
    	minutesint=(int)minutes;
    	seconds=(minutes-minutesint)*60;
    	secondsint=(int)seconds;
    	
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", angleint, minutesint, secondsint);
    }
    else if (d13>=d12 && d13>=d23) {
    	angle=(acos((pow(d12,2)+pow(d23,2)-pow(d13,2))/(2*d12*d23)))*180/(PI);
    	angleint=(int)angle;
    	minutes=(angle-angleint)*60;
    	minutesint=(int)minutes;
    	seconds=(minutes-minutesint)*60;
    	secondsint=(int)seconds;
    	
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", angleint, minutesint, secondsint);
    }
    else {
    	angle=(acos((pow(d13,2)+pow(d12,2)-pow(d23,2))/(2*d13*d12)))*180/(PI);
    	angleint=(int)angle;
    	minutes=(angle-angleint)*60;
    	minutesint=(int)minutes;
    	seconds=(minutes-minutesint)*60;
    	secondsint=(int)seconds;
    	
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", angleint, minutesint, secondsint);
    }
	return 0;
}
