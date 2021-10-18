#include <stdio.h>
int main() {
	char a,b,c,nr;
	float p1=5.30,p2=6.80,p3=8.00,h1=3.00,h2=3.30,h3=5.00,c1=3.90,c2=5.00,c3=6.00;
	float x=0.00,y=0.00,z=0.00,y2=0.00,y3=0.00,yp=0.00,yh=0.00,yc=0.00;
	int pb=0,hb=0,cb=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&a);
	if(a=='P')
		pb=pb+1;
	else if(a=='H')
		hb=hb+1;
	else if(a=='C')
		cb=cb+1;
	scanf("%c",&nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	if(b=='P')
		pb=pb+1;
	else if(b=='H')
		hb=hb+1;
	else if(b=='C')
		cb=cb+1;
	scanf("%c",&nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&c);
	if(c=='P')
		pb=pb+1;
	else if(c=='H')
		hb=hb+1;
	else if(c=='C')
		cb=cb+1;
	yp=pb*p2;
	yh=hb*h2;
	yc=cb*c2;
	if(yp>=yh && yp>=yc)
	y2=yp;
	if(yh>=yp && yh>=yc)
	y2=yh;
	if(yc>=yp && yc>=yh)
	y2=yc;
	x=(pb*p1)+(hb*h3)+(cb*c3);
	y=(pb*p2)+(hb*h2)+(cb*c2);
	y3=y-(y2*0.10);
	z=(pb*p3)+(hb*h1)+(cb*c1);
	if(y<x && y<z)
	{
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",y);
		return 1;
	}
	if(x>z)
	{
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). \n",z);
		if(y3<z-0.001)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y3);
			return 0;
		}
		
		return 0;
	}
	else if(x<z)
	{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM). \n",x);
		if(y3<x-0.001)
		{
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",y3);
			return 0;
		}
		return 0;
	}
	return 0;
}
