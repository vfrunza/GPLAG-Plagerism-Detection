#include <stdio.h>
#define PI 3.1415926

int main() {
	int n, i, cijeli, sekunde, uglovi_st[500][3];
	float decimalni, minute, sekunde_f, sekunde_z;
	double uglovi[500][2];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%lf", &uglovi[i][0]);
		uglovi[i][1]=uglovi[i][0]/PI*180; /* Uglovi u decimalnom broju */
		cijeli=uglovi[i][1];
		decimalni=uglovi[i][1]-cijeli;
		uglovi_st[i][0]=cijeli;				/* Stepeni ugla */
		minute=decimalni*60;				
		cijeli=minute;
		uglovi_st[i][1]=cijeli;				/* Minute ugla */
		decimalni=minute-cijeli;
		sekunde=decimalni*60;
		sekunde_f=decimalni*60;
		sekunde_z=sekunde_f-sekunde;
		if(sekunde_z>0.5) sekunde++;
		if(sekunde_z<=-0.5) sekunde--;
		if(sekunde==60) {sekunde=0;
						 uglovi_st[i][1]++;}
		if(sekunde==-60) {sekunde=0;
						 uglovi_st[i][1]--;}
		if(uglovi_st[i][1]==60) { uglovi_st[i][0]++;
								  uglovi_st[i][1]=0; }
		if(uglovi_st[i][1]==-60) { uglovi_st[i][0]--;
								  uglovi_st[i][1]=0; }
		uglovi_st[i][2]=sekunde;			/* Sekunde ugla */
		if(uglovi_st[i][1]<0) uglovi_st[i][1]*=-1;
		if(uglovi_st[i][2]<0) uglovi_st[i][2]*=-1;
	}
	printf("Uglovi su: ");
	for(i=0; i<n; i++) {
		if(uglovi_st[i][2]<31)
		         printf("\n%d stepeni %d minuta %d sekundi", 
		         uglovi_st[i][0], uglovi_st[i][1], uglovi_st[i][2]);
	}
	return 0;
}