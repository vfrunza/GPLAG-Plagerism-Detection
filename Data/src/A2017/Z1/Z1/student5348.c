#include <stdio.h>

int main() {
	
	char tarik,bojan,mirza;
	
	float rp=6.8,rh=3.3,rc=5.0,fp=8.0,fh=3.0,fc=3.9,bp=5.3,bh=5.0,bc=6.0;
	
	float rukupno=0,fukupno=0,bukupno=0;
	
	float pcount=0,hcount=0,ccount=0;
	
	float min;
	
	printf("Unesite jelo za Tarika: ");scanf("%c",&tarik);
	
	printf("Unesite jelo za Bojana: ");scanf(" %c",&bojan);
	
	printf("Unesite jelo za Mirzu: ");scanf(" %c",&mirza);
		
	switch(tarik)
	{
		case 'H':
		rukupno+=rh;fukupno+=fh;bukupno+=bh;hcount++;
		break;
		case 'P':
		rukupno+=rp;fukupno+=fp;bukupno+=bp;pcount++;
		break;
		case 'C':
		rukupno+=rc;fukupno+=fc;bukupno+=bc;ccount++;
		break;
		default:
		break;	}
		
	switch(bojan)
	{
		case 'H':
		rukupno+=rh;fukupno+=fh;bukupno+=bh;hcount++;
		break;
		case 'P':
		rukupno+=rp;fukupno+=fp;bukupno+=bp;pcount++;
		break;
		case 'C':
		rukupno+=rc;fukupno+=fc;bukupno+=bc;ccount++;
		break;
		default:
		break;	}
		
		switch(mirza)
	{
		case 'H':
		rukupno+=rh;fukupno+=fh;bukupno+=bh;hcount++;
		break;
		case 'P':
		rukupno+=rp;fukupno+=fp;bukupno+=bp;pcount++;
		break;
		case 'C':
		rukupno+=rc;fukupno+=fc;bukupno+=bc;ccount++;
		break;
		default:
		break;	}
	
if(rukupno<fukupno && rukupno<bukupno){printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",rukupno);return 0;}
else if(fukupno<rukupno && fukupno<bukupno)printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",fukupno);
else if(bukupno<rukupno && bukupno<fukupno)printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bukupno);

if(pcount>0 && pcount>=ccount) rukupno=rukupno-(0.1*pcount)*rp;
else if(ccount>pcount) rukupno=rukupno-(0.1*ccount)*rc;
else rukupno=rukupno-(0.1*hcount)*rh;

if(rukupno<fukupno && rukupno<bukupno)
{printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",rukupno);}
	return 0;
}
