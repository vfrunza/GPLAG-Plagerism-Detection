#include <stdio.h>
#include <string.h>

int main() 
	{
		int crna=0,bijela=0,siva=0,crvena=0,plava=0,max=0;
		float u=0,perc;
		char chc;
		char boja[10],crn[10]="crna",bijel[10]="bijela",siv[10]="siva",crven[10]="crvena",plav[10]="plava";
		printf("Unesite vozila: ");
		while(scanf("%c",&chc)!=13)
		{
			if(chc=='k' || chc=='K')
			 break;
			switch(chc)
			{
				case 'c':
				{
					crna++;
					if(crna>max)
						max=crna;
					u++;
					break;
				}
				case 'C':
				{
					crna++;
					if(crna>max)
						max=crna;
					u++;
					break;
				}
				case 'b':
				{
					bijela++;
					if(bijela>max)
						max=bijela;
					u++;
					break;
				}
				case 'B':
				{
					bijela++;
					if(bijela>max)
						max=bijela;
					u++;
					break;
				}
				case 's':
				{
					siva++;
					if(siva>max)
						max=siva;
					u++;
					break;
				}
				case 'S':
				{
					siva++;
					if(siva>max)
						max=siva;
					u++;
					break;
				}
				case 'v':
				{
					crvena++;
					if(crvena>max)
						max=crvena;
					u++;
					break;
				}
				case 'V':
				{
					crvena++;
					if(crvena>max)
						max=crvena;
					u++;
					break;
				}
				case 'p':
				{
					plava++;
					if(plava>max)
						max=plava;
					u++;
					break;
				}
				case 'P':
				{
					plava++;
					if(plava>max)
						max=plava;
					u++;
					break;
				}
				default:
				{
					printf("Neispravan unos\n");
					break;
				}
			}
		}
		if(crna==max)
			strcpy(boja,crn);
		else if(bijela==max)
			strcpy(boja,bijel);
		else if(siva==max)
			strcpy(boja,siv);
		else if(crvena==max)
			strcpy(boja,crven);
		else
			strcpy(boja,plav);
		printf("Ukupno evidentirano %g vozila.\n",u);
		if(u==0)
		{
			u++;
			strcpy(boja,crn);
		}
		perc=(100/u)*max;
		printf("Najpopularnija boja je %s (%.2f%%).",boja,perc);
		return 0;
	}