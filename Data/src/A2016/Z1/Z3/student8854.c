#include <stdio.h>

int main() {
	float x6,x,max,posto1,posto;
	int x1,x2,x3,x4,x5;
	char a;
	printf ("Unesite vozila: ");
	x1=0;x2=0;x3=0;x4=0;x5=0;max=0;x6=0;
	do
	{
	
	scanf("%c",&a);
	
	if(a=='c' || a=='C')
	{x1++;}
	
	if(a=='b' || a=='B')
	{x2++;}
	
	if(a=='S' || a=='s')
	{x3++;}
	
	if(a=='V' || a=='v')
	{x4++;}
	
	if(a=='p' || a=='P')
	{x5++;}
	
	if(a!='c' && a!='C' && a!='b' && a!='B' && a!='s' && a!='S' && a!='v' && a!='V' && a!='p' && a!='P' && a!='k' && a!='K')
	printf("Neispravan unos\n");
	if(a=='k' || a=='K')
	break;
	
	
	}
	while(a!='k' && a!='K');
	if(x1>=x2 && x1>=x3 && x1>=x4 && x1>=x5)
	max=x1;
	if(x2>=x1 && x2>=x3 && x2>=x4 && x2>=x5)
	max=x2;
	if(x3>=x1 && x3>=x2 && x3>=x4 && x3>=x5)
	max=x3;
	if(x4>=x2 && x4>=x3 && x4>=x1 && x4>=x5)
	max=x4;
	if(x5>=x2 && x5>=x3 && x5>=x4 && x5>=x1)
	max=x5;
	x=x1+x2+x3+x4+x5+x6;
	posto1=max/x;
	posto=posto1*100;
	if(x==0)
	{printf("Ukupno evidentirano 0 vozila.");
	printf("\nNajpopularnija boja je crna (0.00%%).");
		
	}
	else
	{
	printf("Ukupno evidentirano %g vozila.",x);
	printf("\nNajpopularnija boja je ");
	if (max==x1)
	{printf("crna (%.2f%%).",posto);
}
	else
	{if (max==x2)
	{printf("bijela (%.2f%%).",posto);
	}
	else
	{if (max==x3)
	{printf("siva (%.2f%%).",posto);
	}
	else
	{if (max==x4)
	{printf("crvena (%.2f%%).",posto);
	}
	else
	{if (max==x5)
	{printf("plava (%.2f%%).",posto);
	}
	}}}}}	

	return 0;
}

