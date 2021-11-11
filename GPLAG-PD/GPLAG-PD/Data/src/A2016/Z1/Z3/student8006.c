#include <stdio.h>
#include <math.h>
#define eps 0.00001


int main() {
	char a;
	int i=0, j=0, k=0, x=0, y=0, u;
	float p1, p2, p3, p4, p5, max=-9999999999;
	printf("Unesite vozila: ");
	do
	{
		scanf("%c", &a);
		if(a!='c' && a!='C' && a!='p' && a!='P' && a!='v' && a!='V' && a!='s' && a!='S' && a!='b' && a!='B' && a!='k' && a!='K')
		{
			printf("Neispravan unos\n");
				}
		else
		{
			if(a=='c' || a=='C')
			{i=i+1;}
			if(a=='b' || a=='B')
			{j=j+1;}
			if(a=='p' || a=='P')
			{k=k+1;}
			if(a=='v' || a=='V')
			{x=x+1;}
			if(a=='s' || a=='S')
			{y=y+1;}
		}
		
		}
		while(a!='k' && a!='K');
	
	u=i+j+k+x+y;
	p1=((float)i/u)*100.0;
	p2=((float)j/u)*100.0;
	p3=((float)k/u)*100.0;
	p4=((float)x/u)*100.0;
	p5=((float)y/u)*100.0;
	
	if(p1>max)
	{max=p1;}
	if(p2>max)
	{max=p2;}
	if(p3>max)
	{max=p3;}
	if(p4>max)
	{max=p4;}
	if(p5>max)
	{max=p5;}
	
	
	printf("Ukupno evidentirano %i vozila.\n", u);
	
	if(u==0)
	{printf("Najpopularnija boja je crna (0.00%%).");}
	if(fabs(p1-max)<eps )
	{printf("Najpopularnija boja je crna (%.2f%%).", p1);}
	else if(fabs(p2-max)<eps)
	{printf("Najpopularnija boja je bijela (%.2f%%).", p2);}
	else if(fabs(p5-max)<eps)
	{printf("Najpopularnija boja je siva (%.2f%%).", p5);}
	else if(fabs(p4-max)<eps)
	{printf("Najpopularnija boja je crvena (%.2f%%).", p4);}
	else if(fabs(p3-max)<eps)
	{printf("Najpopularnija boja je plava (%.2f%%).", p3);}
	
	return 0;
}
