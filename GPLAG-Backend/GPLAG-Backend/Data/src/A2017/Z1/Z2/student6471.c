#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265

int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,aa,a1,a2,a3,ba,b1,b2,b3,g,g1,g2,g3;
	int stepen_a,stepen_b,stepen_g,minuta_a,minuta_b,minuta_g,sekundi_a,sekundi_b,sekundi_g;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	
	a=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
	b=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	c=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	aa=acos((b*b+c*c-a*a)/(2*b*c)); a1=((aa*180)/PI);  
	ba=acos((a*a+c*c-b*b)/(2*a*c)); b1=((ba*180)/PI);
	g=acos((a*a+b*b-c*c)/(2*a*b)); g1=((g*180)/PI);
	
	
	stepen_a=(int)a1; a2=((a1-stepen_a)*60);
	minuta_a=(int)a2; a3=((a2-minuta_a)*60);
	sekundi_a=(int)a3;
	stepen_b=(int)b1; b2=((b1-stepen_b)*60);
	minuta_b=(int)b2; b3=((b2-minuta_b)*60);
	sekundi_b=(int)b3;
	stepen_g=(int)g1; g2=((g1-stepen_g)*60);
	minuta_g=(int)g2; g3=((g2-minuta_g)*60);
	sekundi_g=(int)g3;

	if(fabs(a-c)<EPSILON && fabs(b-c)<EPSILON && fabs(a-b)<EPSILON){
		printf("Jednakostranicni\n");
		if(a1>b1 && a1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_a,minuta_a,sekundi_a); 
		}
		else if(b1>a1 && b1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_b,minuta_b,sekundi_b); 
		}
		else if(g1>a1 && g1>b1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_g,minuta_g,sekundi_g); 
		}
	}
	else if((c>a && c>b && fabs(c*c-(a*a+b*b))<EPSILON && a!=b)||(b>a && b>c && fabs(b*b-(a*a+c*c))<EPSILON && a!=c)||(a>b && a>c && fabs(a*a-(b*b+c*c))<EPSILON && b!=c)){
		printf("Pravougli\n");
		printf("Raznostranicni\n");
		if(a1>b1 && a1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_a,minuta_a,sekundi_a); 
		}
		else if(b1>a1 && b1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_b,minuta_b,sekundi_b); 
		}
		else if(g>a1 && g1>b1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_g,minuta_g,sekundi_g); 
		}
	}
	else if(fabs(c*c-(a*a+b*b)<EPSILON && fabs(a*a-b*b)<EPSILON)||(fabs(b*b-(a*a+c*c))<EPSILON && fabs(a-c)<EPSILON)||(fabs(a*a-(b*b+c*c)<EPSILON) && fabs(b*b-c*c)<EPSILON)){
		printf("Pravougli\n");
		printf("Jednakokraki\n");
		if(a1>b1 && a1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_a,minuta_a,sekundi_a); 
		}
		else if(b1>a1 && b1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_b,minuta_b,sekundi_b); 
		}
		else if(g1>a1 && g1>b1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_g,minuta_g,sekundi_g); 
		}
	}
	else if((fabs(a-b)<EPSILON && b!=c && stepen_a!=180 && stepen_b!=180 && stepen_g!=180)||(fabs(a-c)<EPSILON && c!=b && stepen_a!=180 && stepen_b!=180 && stepen_g!=180)||(fabs(b-c)<EPSILON && c!=a && stepen_a!=180 && stepen_b!=180 && stepen_g!=180)){
		printf("Jednakokraki\n");
		if(a1>b1 && a1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_a,minuta_a,sekundi_a); 
		}
		else if(b1>a1 && b1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_b,minuta_b,sekundi_b); 
		}
		else if(g1>a1 && g1>b1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_g,minuta_g,sekundi_g); 
		}
	}
		else if(a!=b && b!=c && a!=c && stepen_a!=180 && stepen_b!=180 && stepen_g!=180){
			printf("Raznostranicni\n");
				if(a1>b1 && a1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_a,minuta_a,sekundi_a); 
		}
		else if(b1>a1 && b1>g1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_b,minuta_b,sekundi_b); 
		}
		else if(g1>a1 && g1>b1){
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_g,minuta_g,sekundi_g); 
		}
		}
		else if(fabs(a1-180)<=EPSILON){
			printf("Linija\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_a,minuta_a,sekundi_a); 
		}
		else if(fabs(b1-180)<=EPSILON){
			printf("Linija\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_b,minuta_b,sekundi_b); 
		}
		else if(fabs(g1-180)<=EPSILON){
			printf("Linija\n");
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepen_g,minuta_g,sekundi_g); 
		}
		else 
		return 0;
		}
	
