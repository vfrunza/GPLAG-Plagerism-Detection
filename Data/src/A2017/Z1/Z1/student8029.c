#include <stdio.h>
#define a 6.80
#define d 3.30
#define g 5.00
#define b 8.00
#define e 3.00
#define h 3.90
#define c 5.30
#define f 5.00
#define i 6.00
int main() {
	char ta,bo,mi,novi_red;
	double pm1,pt1,pb1,pm2,pm3,pb2,pb3,pt2,pt3,ukupno1,ukupno2,ukupno3;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&ta);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bo);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mi);
	scanf("%c",&novi_red);
	switch(ta)
	{
		case 'P':
			pt1=a;
			pt2=b;
			pt3=c;
		break;
		case 'H':
			pt1=d;
			pt2=e;
			pt3=f;
		break;
		case 'C':
			pt1=g;
			pt2=h;
			pt3=i;
		break;
	}	
	switch(mi)
	{
		case 'P':
			pm1=a;
			pm2=b;
			pm3=c;
		break;
		case 'H':
			pm1=d;
			pm2=e;
			pm3=f;
		break;
		case 'C':
			pm1=g;
			pm2=h;
			pm3=i;
		break;
	}	
	switch(bo)
	{
		case 'P':
			pb1=a;
			pb2=b;
			pb3=c;
		break;
		case 'H':
			pb1=d;
			pb2=e;
			pb3=f;
		break;
		case 'C':
			pb1=g;
			pb2=h;
			pb3=i;
		break;
	}
	double max=0,max1=25;
	int br=0;
	ukupno1=pt1+pm1+pb1;
	if(pt1>max) max=pt1;
	if(pm1>=max) max=pm1;
	if(pb1>=max) max=pb1;
	if(max==pt1) br++;
	if(max==pm1) br++;
	if(max==pb1) br++;
	ukupno2=pt2+pm2+pb2;
	ukupno3=pt3+pm3+pb3;
	if(ukupno1<max1) max1=ukupno1;
	if(ukupno2<max1) max1=ukupno2;
	if(ukupno3<max1) max1=ukupno3;
	if(max1==ukupno1)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n",ukupno1);
	if(max1==ukupno2)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). \n",ukupno2);
	if(max1==ukupno3)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",ukupno3);
	if(ukupno1>ukupno2||ukupno1>ukupno3)
	{
		ukupno1=ukupno1-max*br*0.1;
		if(ukupno1<ukupno2&&ukupno1<ukupno3)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",ukupno1);
	}	
	return 0;
}
