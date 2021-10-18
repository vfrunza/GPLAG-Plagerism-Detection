#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define BE 500
#define PI 3.1415926

int main() {
	int a, i, j;
	double niz[500], ugao,dc, mc, sc,s=0, provjera=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &a);
	
	for(i=0; i<a; i++){
		scanf("%lf", &niz[i]);
		ugao= niz[i]*180/PI;
		niz[i]=ugao;
	}
	
	
	ugao=0;
	
	for(i=0; i<a; i++){
		ugao= niz[i];
		dc= (int)ugao;
		mc= fabs((int)((ugao - (int)ugao)*60));
		sc= fabs(round((((ugao - (int)ugao)*60) - (int)((ugao - (int)ugao)*60))*60));
		
		if (sc >= 60){ sc=0; mc++;}
		if (mc >= 60){ mc=0; dc++;}
		if(sc>30) niz[i]=404;
		
	}
	
	for(i=0; i<a; i++){
		if( niz[i] == 404){
			for(j=i;j<a-1;j++){
				niz[j]=niz[j+1];
				
			}
			a--;
			i--;
		}
	}
	ugao=0;
	printf("Uglovi su: \n");
	for(i=0; i<a;i++){
		ugao= niz[i];
		dc= (int)ugao;
		mc= fabs((int)((ugao - (int)ugao)*60));
		sc= fabs(round((((ugao - (int)ugao)*60) - (int)((ugao - (int)ugao)*60))*60));
		if (niz[i]>0){
		if (sc >= 60){ sc=0; mc++;}
		if (mc >= 60){ mc=0; dc++;}
		}
		else{
		if (sc >= 60){ sc=0; mc++;}
		if (mc >= 60){ mc=0; dc--;}	
		}
		if(ugao<0 && dc==0)mc*=-1;
		
	
	printf("%.lf stepeni %.lf minuta %.lf sekundi\n", ceil(dc), ceil(mc), ceil(sc));
	
	}

	return 0;
}



	/*printf("Uglovi su: \n");
	for(j=0; j<a-1;j++){
		printf
	}
	
	
	/*printf("%f\n", niz[0]);
		dc= (int)ugao;
		mc= (int)((ugao - (int)ugao)*60);
		sc= (((ugao - (int)ugao)*60) - (int)((ugao - (int)ugao)*60))*60;
		printf("%.f %.f %f", dc, mc, sc);
	*/