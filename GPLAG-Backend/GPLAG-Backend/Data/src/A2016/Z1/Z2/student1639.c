#include <stdio.h>
#include <math.h>
#define EPS 0.0001

int main() {
	float a1,a2,b1,b2,y1=0;
	float y=0;
	float x=0;
	float y2=0;
		printf("Unesite a1,b1,a2,b2: ");
		scanf("%f, %f, %f, %f", &a1, &b1 , &a2, &b2);
		x=1;
	y1=a1*x+b1;
	y2=a2*x+b2;
		if (fabs(y1-y2)<EPS){printf("Poklapaju se");}
		else{if(fabs(a1-a2)<EPS){printf("Paralelne su");}
			 else{x=(b2-b1)/(a1-a2);
			 	  y=(a1*(b2-b1)/(a1-a2)+b1);
			 	printf ("Prave se sijeku u tacci (%.1f,%.1f)", x, y);
			 }
		}
	return 0; 
}
