#include <stdio.h>
#include <tgmath.h>
#define PI 3.1415926
#define e 0.0001
int main() {
	double x1,x2,x3,y1,y2,y3,ugao1,ugao2,ugao3,a,b,c;
	int stepeni,minute,sekunde,sve;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	ugao1=acos((a*a-b*b-c*c)/(-2*b*c))*180/PI;
	ugao2=acos((b*b-a*a-c*c)/(-2*a*c))*180/PI;
	ugao3=acos((c*c-a*a-b*b)/(-2*a*b))*180/PI;
	if(x1==x2 && x1==x3 || y1==y2 && y2==y3) printf("Linija");
	else if(round(ugao1)==90 || round(ugao2)==90 || round(ugao3)==90) printf("Pravougli\n");
	float a1=a,b1=b,c1=c;
	if(a1==b1 && a1==c1) printf("Jednakostranicni\n");
	else if(a1==b1 || a1==c1 || b1==a1 || b1==c1 || c1==a1 || c1==b1) printf("Jednakokraki\n");
	else if(a1!=b1 && a1!=c1 && b1!=c1) printf("Raznostranicni\n");
	if(ugao1>=ugao2 && ugao1>=ugao3){
		ugao1=(ugao1/180)*PI;
	sve=round(ugao1*360*60*60/(2*PI));
	sekunde=sve%60;
	minute=(sve/60)%60;
	stepeni=sve/(60*60);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	
		return 0;
	}
	if(ugao2>=ugao1 && ugao2>=ugao3){
		ugao2=(ugao2/180)*PI;
	sve=round(ugao2*360*60*60/(2*PI));
	sekunde=sve%60;
	minute=(sve/60)%60;
	stepeni=sve/(60*60);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	return 0;
	}
	if(ugao3>=ugao1 && ugao3>=ugao2){
	ugao3=(ugao3/180)*PI;
	sve=round(ugao3*360*60*60/(2*PI));
	sekunde=sve%60;
	minute=(sve/60)%60;
	stepeni=sve/(60*60);
	printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	return 0;
	}
	return 0;
}
