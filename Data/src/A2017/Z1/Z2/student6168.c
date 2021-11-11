#include <stdio.h>
#include <math.h>
#define eps 0.0001
#define PI 3.1415926535
int main()
{
	double x1, x2, x3, y1, y2, y3, rast12, rast13, rast23, RAZL1213, RAZL1323, RAZL1223, NVU, UGAO, ODSJECAK;
	int MIN, SEK, CBU;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);

	rast12=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	rast13=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	rast23=sqrt(pow(x2-x3,2)+pow(y2-y3,2));

	RAZL1213=fabs(rast12-rast13);
	RAZL1323=fabs(rast13-rast23);
	RAZL1223=fabs(rast12-rast23);

	if(rast12>rast13 && rast12>rast23) {
	NVU=((pow(rast13,2)+pow(rast23,2)-pow(rast12,2))/(2*rast13*rast23));
	} else if(rast13>rast12 && rast13>rast23) {
	NVU=((pow(rast12,2)+pow(rast23,2)-pow(rast13,2))/(2*rast12*rast23));
	} else if(rast23>rast12 && rast23>rast13) {
	NVU=((pow(rast12,2)+pow(rast13,2)-pow(rast23,2))/(2*rast12*rast13));
	} else {
	printf("NE ZNAM BGM");
	}
   
	
	UGAO=acos(NVU)*(180/PI); 
	CBU=(int)UGAO; 
	ODSJECAK=UGAO-CBU; 
	MIN=(int)(ODSJECAK*60); 
	SEK=(int)((ODSJECAK*60-MIN)*60);


	if((rast12+rast13)-rast23<=eps || (rast13+rast23)-rast12<=eps || (rast12+rast23)-rast13<=eps) {
		printf("Linija\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", CBU, MIN, SEK);
	}
	else if(fabs(UGAO-90)<=eps){
		printf("Pravougli\n");
		if (RAZL1213<=eps || RAZL1223<=eps || RAZL1323<=eps)
			printf("Jednakokraki\n");
		else 
			printf("Raznostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", CBU, MIN, SEK);	
	}
	else if(RAZL1213<=eps && RAZL1323<=eps && RAZL1223<=eps){
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", CBU, MIN, SEK);
	}
	else if (RAZL1213<=eps || RAZL1223<=eps || RAZL1323<=eps) {
		printf("Jednakokraki\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", CBU, MIN, SEK);
	}
	else {
		printf("Raznostranicni\n");
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.\n", CBU, MIN, SEK);
	}
	
	return 0;
}
