#include <stdio.h>
#include <math.h>
int main() {
	float a1=0, b1=0, a2=0, b2=0, Xpres, Ypres;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
	
	/*y1=a1*x+b1 , y2=a2*x+b2 ,x(a1-a2)=b2-b1 3.1,5.2,2.1,1.0   3.1,5.2,3.1,1.0   -123.01,123.54,45,74.24  951.12,74.458,45,857*/
	Xpres=(float)(b2-b1)/(a1-a2);
	Ypres=a1*Xpres+b1;
	if (fabs(a1-a2)<0.001 && fabs(a1-a2)>-0.001 && fabs(b1-b2)<0.001 && fabs(b1-b2)>-0.001) 
	printf("Poklapaju se");
	else if (fabs(a1-a2)<0.001 && fabs(a1-a2)>-0.001 && b1!=b2)
	printf("Paralelne su");
	else printf("Prave se sijeku u tacci (%.1f,%.1f)", Xpres, Ypres);
	return 0;
}