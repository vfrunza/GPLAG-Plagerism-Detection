#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int x,y,bruglova;
	int min[500],sec[500],step[500];
	int sek;
	float rad[500];
	
	printf("Unesite broj uglova: ");
	scanf ("%d", &bruglova);
	
	for(x=0;x<bruglova;x++){
		scanf("%f",&rad[x]);
	}
	for(x=0;x<bruglova;x++){
		sek = (int)round(rad[x]*1296000/(2*PI));
		
		sec[x] = fabs((sek%60));
		min[x] = fabs((sek/60)%60);
		step[x] = sek / 3600;
	}
	/* izbacivanje clanova */
	x=0;
	while(x<bruglova){
		if(sec[x]>30){
			y=x;
			while(y<bruglova){
				sec[y]=sec[y+1];
				min[y]=min[y+1];
				step[y]=step[y+1];
				y++;
			}
			bruglova--;
			x--;
		}
		x++;
	}
	printf("Uglovi su:");
	printf("\n");
	/*ispis uglova*/
	x=0;
	while(x<bruglova){
		printf("%d stepeni %d minuta %d sekundi\n",step[x],min[x],sec[x]);
		x++;
	}
	return 0;
}
