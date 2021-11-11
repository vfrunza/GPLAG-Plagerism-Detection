#include <stdio.h>
#include <math.h>

int main() {
	float a1,a2,b1,b2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
		scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
		/* y1=a1x+b1
		 y2=a2x+b2
		 x=? za y1=y2
		 y1=y2 =>  a1x+b1=a2x+b2 => x(a1-a2)=b2-b1=> x=(b2-b1)/(a1-a2) [a1!=a2 (paralelne su)]
		 y=a1x+b1 */
		 if (a1!=a2){
		x=(b2-b1)/(a1-a2);
		y=(a1*x+b1);
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
		 }
		// if((a1==a2)&&(b1==b2)) printf("Poklapaju se");
		 if (a1==a2){
		 	if(b1==b2) printf("Poklapaju se");
		 	else
		 	printf("Paralelne su");}
	return 0;
}
