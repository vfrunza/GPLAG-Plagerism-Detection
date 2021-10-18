#include <stdio.h>
#include <math.h>
#define PI 3.14
#define e 0.0001

float duzinakvadratna(int a1,int b1, int a2, int b2)
{
    float xDiff = a1 - a2;
    float yDiff = b1 - b2;
    return xDiff*xDiff + yDiff*yDiff;
}

int main() {
	
	
	float x1, x2, x3, y1, y2, y3;
	double t1, t2, t3;
	
	 
	 
	 /*unos tacaka*/ 
	printf("Unesite koordinate tacke t1: ");
	scanf("%f %f", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%f %f", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%f %f", &x3, &y3); 
	
	
	


	 
	if(0==sqrt((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2)) {
		
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	} 
	
		t1=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
    t2=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
    t3=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	
	if ((fabs(t1-t2)<e)&&(fabs(t2-t3)<e)) {
		
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		
		return 0;
	} 
	
	
		

	 
	 
		 float a2 = duzinakvadratna(x1,y1, x2, y2);
    float b2 = duzinakvadratna(x2,y2,x3,y3);
    float c2 = duzinakvadratna(x3,y3,x1,y1);
	 
	 float alfa = acos((b2 + c2 - a2)/(2*t2*t1));
    float beta = acos((a2 + c2 - b2)/(2*t1*t3));
    float gama = acos((a2 + b2 - c2)/(2*t1*t2));
 
 
    
    alfa = alfa * 180 / PI;
    beta = beta * 180 / PI;
    gama = gama * 180 / PI;
    
    float max=alfa;
    if(alfa<beta) max=beta;
    if(alfa<gama || beta<gama) 
    
    max=gama;
    
     int pravougli =0;
    
     if((int)max==90) 
    pravougli=1;
    
    int d=0, m=0, s=0;
 float minwork=0.0, secwork=0.0; 
 d = max; 
 max = max - d; 
 minwork = max*60;
 m = minwork; 
 max = max*100;

    max = max - minwork; 
    secwork = max*60;
    s = secwork; 

    
   printf("%d %d %d", d,m,s);

	
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		