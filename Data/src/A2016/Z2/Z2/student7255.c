#include <stdio.h>
#include<math.h>
#define PI 3.1415926
int main() {
	int sekunde;
	float radijani[500];
	int uglovi[500][3];
	int bu;
	int i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&bu);
	/*0 - stepeni
	  1 - minute
	  2 - sekunde*/
	  
	for(i=0;i<bu;i++){
		scanf("%f",&radijani[i]);
		sekunde = (int)round(radijani[i]*1296000/(2*PI));
		
		uglovi[i][2]= sekunde % 60;	uglovi[i][2]= fabs(uglovi[i][2]);
		uglovi[i][1]= (sekunde / 60) % 60; uglovi[i][1]= fabs(uglovi[i][1]);
		uglovi[i][0]= sekunde / (60*60);
	}
	
	for(i=0;i<bu;i++){
		if(uglovi[i][2]>30){
			for(j=i;j<bu;j++){
				uglovi[j][0]=uglovi[j+1][0];
				uglovi[j][1]=uglovi[j+1][1];
				uglovi[j][2]=uglovi[j+1][2];
			}
			bu--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0;i<bu;i++){
		printf("%d stepeni %d minuta %d sekundi\n",uglovi[i][0],uglovi[i][1],uglovi[i][2]);
	}
	return 0;
}
