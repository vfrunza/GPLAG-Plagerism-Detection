#include <stdio.h>
#include <math.h>
#define e 0.0001
#define stepeni 57.295779513

int main()
{
	double x1, x2, x3, y1, y2, y3, AB, BC, AC;
	double ugao, uab,uac,ubc, min, sec;
	int st, min1, sec1;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	AB=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	BC=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
	AC=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
	uab=acos((pow(BC,2)+pow(AC,2)-pow(AB,2))/(2*BC*AC))*stepeni;
	ubc=acos((pow(AB,2)+pow(AC,2)-pow(BC,2))/(2*AB*AC))*stepeni;
	uac=acos((pow(BC,2)+pow(AB,2)-pow(AC,2))/(2*BC*AB))*stepeni;
	if(fabs(uab)<=e || fabs(ubc)<=e || fabs(uac)<=e){
		printf("Linija\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	if(fabs(AB-BC)<=e && fabs(BC-AC)<=e && fabs(AB-AC)<=e) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}
	if((fabs(AB-BC)<=e && fabs(BC-AC)>e) || (fabs(AB-AC)<=e && fabs(BC-AC)>e) || (fabs(AC-BC)<=e && fabs(AB-AC)>e)) {
		if(fabs(uab-90)<=e || fabs(ubc-90)<=e || fabs(uac-90)<=e) {
			printf("Pravougli\n");
		}
		printf("Jednakokraki\n");
		if(fabs(uab-90)<=e || fabs(ubc-90)<=e || fabs(uac-90)<=e) {
			printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		}
		if(fabs(uab-90)>e && fabs(ubc-90)>e && fabs(uac-90)>e){
			if(uab-uac>e && uab-ubc>e){
				ugao=uab;
			}
			if(fabs(uab-uac)<=e || fabs(uab-ubc)<=e){
				ugao=uab;
			}
			if(uac-ubc>e && uac-uab>e){
				ugao=uac;
			}
			if(fabs(uab-ubc)<=e || fabs(uac-ubc)<=e){
				ugao=ubc;
			}
			if(ubc-uac>e && ubc-uab>e){
				ugao=ubc;
			}
			if(fabs(uab-uac)<=e || fabs(uac-ubc)<=e){
				ugao=uac;
			}
			st=(int)ugao;
			min=(ugao-st)*60;
			min1=(int) min;
			sec=(min-min1)*60;
			sec1=(int) sec;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", st,min1,sec1);
		}
	}
	if(fabs(AB-BC)>e && fabs(BC-AC)>e && fabs(AB-AC)>e) {
		if(fabs(uab-90)<=e || fabs(ubc-90)<=e || fabs(uac-90)<=e) {
			printf("Pravougli\n");
		}
		printf("Raznostranicni\n");
		if(fabs(uab-90)<=e || fabs(ubc-90)<=e || fabs(uac-90)<=e) {
			printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		}
		if(fabs(uab-90)>e && fabs(ubc-90)>e && fabs(uac-90)>e){
			if(uab-uac>e && uab-ubc>e){
				ugao=uab;
			}
			if(fabs(uab-uac)<=e || fabs(uab-ubc)<=e){
				ugao=uab;
			}
			if(uac-ubc>e && uac-uab>e){
				ugao=uac;
			}
			if(fabs(uab-ubc)<=e || fabs(uac-ubc)<=e){
				ugao=ubc;
			}
			if(ubc-uac>e && ubc-uab>e){
				ugao=ubc;
			}
			if(fabs(uab-uac)<=e || fabs(uac-ubc)<=e){
				ugao=uac;
			}
			st=(int)ugao;
			min=(ugao-st)*60;
			min1=(int) min;
			sec=(min-min1)*60;
			sec1=(int) sec;
			printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", st,min1,sec1);
		}
	}

	return 0;
}
