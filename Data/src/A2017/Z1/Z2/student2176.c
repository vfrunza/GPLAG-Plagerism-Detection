#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001
#define PI 3.14159265359

int main() {
	double x1,x2,x3,y1,y2,y3,s1,s2,s3,max,min,sr,p,ugao;
	int stranica=0,stepeni,minuta,sekundi;
	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	s1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	s2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	s3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	max=s1;
	min=s3;
	sr=s2;
//	printf("s1 je %.30f",s1);
//	printf("\ns2 je %.30f",s2);
//	printf("\ns3 je %.30f",s3);
	if(s2>max && fabs(s2-max)>EPSILON) max=s2;
	if(s3>max && fabs(s3-max)>EPSILON) max=s3;
	if(s1<min && fabs(s1-min)>EPSILON) min=s1;
	if(s2<min && fabs(s2-min)>EPSILON) min=s2;
	
	if((s1>=s2 && fabs(s1-s2)>EPSILON && s1<=s3 && fabs(s1-s3)>EPSILON) || (s1>=s3 && fabs(s1-s3)>EPSILON && s1<=s2 && fabs(s1-s2)>EPSILON)) sr=s1;
	if((s3>=s2 && fabs(s3-s2)>EPSILON && s3<=s1 && fabs(s3-s1)>EPSILON) || (s3>=s1 && fabs(s3-s1)>EPSILON && s3<=s2 && fabs(s3-s2)>EPSILON)) sr=s3;
	
	if(fabs(s1-s2)>EPSILON) stranica++;
	if(fabs(s1-s3)>EPSILON) stranica++;
	if(fabs(s2-s3)>EPSILON) stranica++;
	if(stranica==0) stranica++;
//	printf("\nnajmanja je: %.30f\n",min);
//	printf("srednja je: %.30f",sr);
//	printf("\nnajveca je: %.30f\n",max);
	p=fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
//	printf("povrsina %.30f\n",p);
//	printf("Stranica: %d\n",stranica);
ugao=acos((min*min+sr*sr-max*max)/(2*min*sr))*(180.0/PI);
//printf("Ugao je: %f\n",ugao);

if(fabs(ugao-90)<EPSILON){
	stepeni=90;
	minuta=0;
	sekundi=0;
}
else {
	stepeni=(int)ugao;
	ugao=ugao-stepeni;
	minuta=(int)(ugao*60);
	ugao=ugao*60-minuta;
	sekundi=(int)(ugao*60);
	}
//	printf("Stepeni: %d minuta: %d sekundi: %d",stepeni,minuta,sekundi);
	if(fabs(p-0)<EPSILON){
		printf("Linija");
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	
	if(stranica==1){
		printf("Jednakostranicni");
		printf("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	
	if(stepeni==90) printf("Pravougli\n");
	if(stranica==2) printf("Jednakokraki");
	if(stranica==3) printf("Raznostranicni");
	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minuta,sekundi);
	
	
	return 0;
}
