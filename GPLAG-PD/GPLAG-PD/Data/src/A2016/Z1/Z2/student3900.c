#include <stdio.h>

int main() {
	float a1,b1,a2,b2,r,p;
	printf("Unesi a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
	if(a1==a2){printf("Paralelne su");}
	else if(a1==a2 && b1==b2){printf("Poklapaju se");}
	else{
		r=(p*a1)+b1;
		p=((b2-b1)/(a1-a2));
		printf("Prave se sijeku u tacci (%.1f,%.1f)", p,r);
	}
	return 0;
}
