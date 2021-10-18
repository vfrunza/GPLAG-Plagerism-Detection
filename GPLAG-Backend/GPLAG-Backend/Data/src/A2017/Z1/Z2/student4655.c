#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define pi 3.14159265

#define e 0.0001
int main() {
	
	double x1,y1,x2,y2,x3,y3,a,b,c,ua,ub,uc;
	double povrs,ua1,ua2,ua3,ub1,ub2,ub3,uc1;
	double uc2,uc3;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	a=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
	b=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	c=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	

	
	ua=acos((b*b+c*c-a*a)/(2*b*c))*(180./pi);
	ub=acos((a*a+c*c-b*b)/(2.*a*c))*(180./pi);
	uc=acos((b*b+a*a-c*c)/(2*b*a))*(180./pi);
	

	povrs=fabs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.);

	if(povrs<e){
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}else{
	 if((fabs(ua-ub)<=e)&&(fabs(ua-uc)<=e)&&(fabs(ub-uc)<=e)){
		printf("Jednakostranicni\n");
	}else if((fabs(90-ua)<e)||(fabs(90-ub)<e)||(fabs(90-uc)<e)){
		printf("Pravougli\n");
	}if((fabs(a-b)<e&&fabs(a-c)>e)||(fabs(b-a)>e&&fabs(b-c)<e)||(fabs(c-a)<e&&fabs(c-b)>e)){
		printf("Jednakokraki\n");
	}if(fabs(a-b)>e&&fabs(a-c)>e&&fabs(b-c)>e){
		printf("Raznostranicni\n");
	}
		
}
	if(a>=b&&a>=c){
		ua1= (int) ua;
		ua=ua-ua1;
		ua2= (int)(ua*60);
		ua=ua*60;
		ua=ua-(int)(ua);
		ua3=(int)(ua*60);
		
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ua1,ua2,ua3);
	}else if(b>=a&&b>=c){
		ub1= (int) ub;
		ub=ub-ub1;
		ub2= (int)(ub*60);
		ub=ub*60;
		ub=ub-(int)(ub);
		ub3=(int)(ub*60);
		
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",ub1,ub2,ub3);
	
	}else if(c>=a&&c>=b){
		uc1= (int) uc;
		uc=uc-uc1;
		uc2= (int)(uc*60);
		uc=uc*60;
		uc=uc-(int)(uc);
		uc3=(int)(uc*60);
		
		printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.",uc1,uc2,uc3);
	
	}
	return 0;
}
