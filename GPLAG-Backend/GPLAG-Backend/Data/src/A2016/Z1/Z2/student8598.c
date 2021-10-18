#include <stdio.h>

int main() {
	float x1,y1,x2,y2,x,y;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&x1,&y1,&x2,&y2);
	x=(y2-y1)/(x1-x2);
	y=x1*x+y1;
	if(x2==x1 && y1==y2)
	{
		printf("Poklapaju se");
	}
if(x1==x2 && y1!=y2)
	{
		printf("Paralelne su");
	}
if(x1!=x2 && y1!=y2){
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
}

	return 0;
}