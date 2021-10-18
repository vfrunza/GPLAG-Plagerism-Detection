#include <stdio.h>
#include <math.h>
#define PI 3.14159265358
#define EPSILON 0.0001
int main() {
	double t1x,t1y,t2x,t2y,t3x,t3y,a,b,c,alfa,beta,gama,minutaA,minutaB,minutaG,sekundaA,sekundaB,sekundaG;
	int stepenA,stepenB,stepenG,minutaAA,minutaBB,minutaGG,sekundaAA,sekundaBB,sekundaGG;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&t1x,&t1y);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&t2x,&t2y);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&t3x,&t3y);
	a=sqrt(fabs((t2x-t1x)*(t2x-t1x)+(t2y-t1y)*(t2y-t1y)));
	b=sqrt(fabs((t3x-t1x)*(t3x-t1x)+(t3y-t1y)*(t3y-t1y)));
	c=sqrt(fabs((t2x-t3x)*(t2x-t3x)+(t2y-t3y)*(t2y-t3y)));
	if(t1x*t2y+t1y*t3x+t3y*t2x-t1x*t3y-t2x*t1y-t3x*t2y==0) {
	     printf("Linija\n");
	     printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.\n");
	     return 0;
	}
	if(fabs(a-b)<EPSILON && fabs(b-c)<EPSILON) printf("Jednakostranicni\n");
	if(fabs(a*a+b*b-c*c)<EPSILON || fabs(a*a+c*c-b*b)<EPSILON || fabs(b*b+c*c-a*a)<EPSILON) printf("Pravougli\n");
	if((fabs(a-b)<EPSILON && fabs(b-c)>EPSILON)||(fabs(a-c)<EPSILON && fabs(c-b)>EPSILON)|| (fabs(c-b)<EPSILON && fabs(b-a)>EPSILON)) { 
		printf("Jednakokraki\n");
	}
	if(fabs(b-c)>EPSILON && fabs(b-a)>EPSILON && fabs(a-c)>EPSILON) printf("Raznostranicni\n");
	alfa = acos( (b*b+c*c-a*a) / (2*b*c) ); 
    beta = acos( (c*c+a*a-b*b) / (2*c*a) ); 
    gama = acos( (a*a+b*b-c*c) / (2*a*b) );
    alfa *= 180/PI;
    beta *= 180/PI;
    gama *= 180/PI;
    stepenA=(int)alfa;
    stepenB=(int)beta;
    stepenG=(int)gama;
    minutaA=(alfa-stepenA)*60;
    minutaB=(beta-stepenB)*60;
    minutaG=(gama-stepenG)*60;
    minutaAA=(int)minutaA;
    minutaBB=(int)minutaB;
    minutaGG=(int)minutaG;
    sekundaA=(minutaA-minutaAA)*60;
    sekundaB=(minutaB-minutaBB)*60;
    sekundaG=(minutaG-minutaGG)*60;
    sekundaAA=(int)sekundaA;
    sekundaBB=(int)sekundaB;
    sekundaGG=(int)sekundaG;
    if(alfa>beta && alfa>gama) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepenA,minutaAA,sekundaAA);
    if(alfa<beta && beta>gama) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepenB,minutaBB,sekundaBB);
    if(gama>beta && alfa<gama) printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepenG,minutaGG,sekundaGG);
	return 0;
}
