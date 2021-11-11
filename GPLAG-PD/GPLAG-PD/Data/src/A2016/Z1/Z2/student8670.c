#include <stdio.h>

int main() {
	float k1,k2,n1,n2,x1,y1;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &k1,&n1,&k2,&n2);
	if ((k1<=k2 || k1>=k2) && n1==n2) {
		printf("Poklapaju se \n"); 
	} else 
		if(k1==k2) {
		if (n1!=n2) {
			printf("Paralelne su \n");}
		} else  {
			x1=(n2-n1)/(k1-k2);
			y1=k1*x1+n1;
			printf("Prave se sijeku u tacci (%.1f,%.1f)",x1,y1);
		}
return 0;
}