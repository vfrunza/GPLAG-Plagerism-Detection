#include <stdio.h>
#define epsilon 0.00000001
#include <math.h>
int main() {
	float a1,b1,a2,b2,r,p;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if((fabs(a2-a1)<epsilon) && (fabs(b2-b1)<epsilon)){printf("Poklapaju se");}
	else if(fabs(a1-a2)<epsilon){printf("Paralelne su");}
	else{
	    p=((b2-b1)/(a1-a2));
	    r=(p*a1)+b1;
	    printf("Prave se sijeku u tacci (%.1f,%.1f)", p,r);
	}
	return 0;
}
