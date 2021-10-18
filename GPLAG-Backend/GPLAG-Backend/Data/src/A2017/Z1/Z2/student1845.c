#include <stdio.h>
#include <math.h>
#define e 0.0001
#define pi 3.14159
int main() {
	double a,b,c,tx1,tx2,ty1,ty2,tx3,ty3,A,B,G,s,m,se,o;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &tx1, &ty1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &tx2, &ty2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &tx3,&ty3);
    a=sqrt((tx2-tx1)*(tx2-tx1)+((ty2-ty1)*(ty2-ty1)));
    b=sqrt((tx3-tx2)*(tx3-tx2)+((ty3-ty2)*(ty3-ty2)));
    c=sqrt((tx3-tx1)*(tx3-tx1)+((ty3-ty1)*(ty3-ty1)));
    if(a>=b && a>=c ) { 
    	A=acos((b*b+c*c-a*a)/(2*b*c));
    	s=A*(180/pi);
    	o=s-(int)s;
    	m=o*60;
    	o=m-(int)m;
    	se=o*60;
    	
    }
    else if(b>=c && b>=a) {
    	B=acos((a*a+c*c-b*b)/(2*a*c));
    	s=B*(180/pi);
    	o=s-(int)s;
    	m=o*60;
    	o=m-(int)m;
    	se=o*60;
    	
    }
    else if(c>=a && c>=b) {
    	G=acos((b*b+a*a-c*c)/(2*b*a));
    	s=G*(180/pi);
    	o=s-(int)s;
    	m=o*60;
    	o=m-(int)m;
    	se=o*60;
    	
    }
    if(fabs(tx1-tx2)<e && fabs(tx1-tx3)<e && fabs(tx2-tx3)<e){
    	printf("Linija\n");
    	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
    }
    else if(fabs(tx1*ty2+ty1*tx3+tx2*ty3-tx3*ty2-ty3*tx1-tx2*ty1)<e){
    	printf("Linija\n");
    	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
    }
    else if((fabs(ty1-ty2)<e) && (fabs(ty1-ty3)<e) && (fabs(ty2-ty3))<e){
    	printf("Linija\n");
    	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
    }
    
    
   
    else if((fabs(a-b)<e) && (fabs(b-c)<e) && (fabs(a-c)<e)) {
    	printf("Jednakostranicni\n");
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)s,(int)m,(int)se );
    }
    else if((fabs(c*c-a*a-b*b)<e) || (fabs(a*a-b*b-c*c)<e) || fabs(b*b-a*a-c*c)<e) {
    	printf("Pravougli\n");
    
    	if((fabs(a-b)<e) || (fabs(b-c)<e) || (fabs(a-c)<e)) {
    	printf("Jednakokraki\n");
    	}
    	else if(fabs(a-b)>e && fabs(a-c)>e){
            printf("Raznostranicni\n");
        }
        printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)s,(int)m,(int)se );
    }
    else if((fabs(a-b)<e) || (fabs(b-c)<e) || (fabs(a-c)<e)) {
    	printf("Jednakokraki\n");
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)s,(int)m,(int)se );
    }
     else if((fabs(a-b)>e)  || (fabs(a-c)>e)) {
    	printf("Raznostranicni\n");
    	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",(int)s,(int)m,(int)se );
    }
	return 0;
}




