#include <stdio.h>

int main() 
	{
		float ppt,dpt,prt,zit,ppb,dpb,prb,zib,ppm,dpm,prm,zim,zat,zab,zam,bot=0,bob=0,bom=0;
		int oct,ocb,ocm,i=3;
		printf("Unesite bodove za Tarika:\n");
		printf("I parcijalni ispit: ");
		scanf("%f",&ppt);
		if(ppt<0 || ppt>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("II parcijalni ispit: ");
		scanf("%f",&dpt);
		if(dpt<0 || dpt>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("Prisustvo: ");
		scanf("%f",&prt);
		if(prt<0 || prt>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("Zadace: ");
		scanf("%f",&zat);
		if(zat<0 || zat>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("Zavrsni ispit: ");
		scanf("%f",&zit);
		if(zit<0 || zit>40)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		bot=ppt+dpt+prt+zat+zit;
		printf("Unesite bodove za Bojana:\n");
		printf("I parcijalni ispit: ");
		scanf("%f",&ppb);
		if(ppb<0 || ppb>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("II parcijalni ispit: ");
		scanf("%f",&dpb);
		if(dpb<0 || dpb>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("Prisustvo: ");
		scanf("%f",&prb);
		if(prb<0 || prb>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("Zadace: ");
		scanf("%f",&zab);
		if(zab<0 || zab>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("Zavrsni ispit: ");
		scanf("%f",&zib);
		if(zib<0 || zib>40)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		bob=ppb+dpb+prb+zab+zib;
		printf("Unesite bodove za Mirzu:\n");
		printf("I parcijalni ispit: ");
		scanf("%f",&ppm);
		if(ppm<0 || ppm>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("II parcijalni ispit: ");
		scanf("%f",&dpm);
		if(dpm<0 || dpm>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("Prisustvo: ");
		scanf("%f",&prm);
		if(prm<0 || prm>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("Zadace: ");
		scanf("%f",&zam);
		if(zam<0 || zam>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		printf("Zavrsni ispit: ");
		scanf("%f",&zim);
		if(zim<0 || zim>40)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		bom=ppm+dpm+prm+zam+zim;
		if(bot>=54.9999 && bot<65)
			oct=6;
		else if(bot>=65 && bot<75)
			oct=7;
		else if(bot>=75 && bot<85)
			oct=8;
		else if(bot>=85 && bot<92)
			oct=9;
		else if(bot>=92 && bot<=100)
			oct=10;
		else
			{
				oct=5;
				i--;
			}
		if(bob>=54.9999 && bob<65)
			ocb=6;
		else if(bob>=65 && bob<75)
			ocb=7;
		else if(bob>=75 && bob<85)
			ocb=8;
		else if(bob>=85 && bob<92)
			ocb=9;
		else if(bob>=92 && bob<=100)
			ocb=10;
		else
			{
				oct=5;
				i--;
			}
		if(bom>=54.9999 && bom<65)
			ocm=6;
		else if(bom>=65 && bom<75)
			ocm=7;
		else if(bom>=75 && bom<85)
			ocm=8;
		else if(bom>=85 && bom<92)
			ocm=9;
		else if(bom>=92 && bom<=100)
			ocm=10;
		else
			{
				oct=5;
				i--;
			}
		if(i==3)
			{
				printf("Sva tri studenta su polozila.\n");
				if(oct==ocb && ocb==ocm)
					printf("Sva tri studenta imaju istu ocjenu.\n");
				else if(oct==ocb || oct==ocm || ocb==ocm)
					printf("Dva od tri studenta imaju istu ocjenu.\n");
				else
					printf("Svaki student ima razlicitu ocjenu.\n");
			}
		else if(i==2)
			printf("Dva studenta su polozila.\n");
		else if(i==1)
			printf("Jedan student je polozio.\n");
		else if(i==0)
			printf("Nijedan student nije polozio.\n");
		return 0;
	}