#include <stdio.h>

int main()
{
	float y1,y2,a1,x,a2,n1,n2;
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f",&a1,&n1,&a2,&n2);
	
	if (a1==a2 && n1==n2) { printf ("Poklapaju se"); return 0; }
	if ((a1/a2)==(n1/n2) || (a1==a2 && n1!=n2)) printf("Paralelne su\n");
	
	
	else{  
	x=(n2-n1)/(a1-a2);
	y1=a1*x+n1;
	y2=a2*x+n2;
	printf("Prave se sijeku u tacci (%1.1f,%1.1f)",x,y1);
	}
	return 0;	
}
