#include <stdio.h>
#define kraj k

int main() {
char boja;
int crna=0,bijela=0,siva=0,crvena=0,plava=0,max=0;
float IZNOS,ZBIR;
printf("Unesite vozila: ");
do 
{
	scanf("%c", &boja);
	if(boja=='c' || boja=='C' || boja=='b' || boja=='B' || boja=='s' || boja=='S' || boja=='v' || boja=='V' || boja=='k' || boja=='K' || boja=='p' || boja=='P')
{
	 if (boja=='c' || boja=='C')
		{
			crna++;
		}
		else if(boja=='b' || boja=='B')
		{
			bijela++;
		}
		else if(boja=='s' || boja=='S')
		{
			siva++;
		}
		else if(boja=='v' || boja=='V')
		{
			crvena++;
		}
		else if(boja=='p' || boja=='P')
		{
			plava++;
		}
		else if(boja=='k' || boja=='K')
		{
			break;
		} 
}
		else 
		{
			printf("Neispravan unos\n");
		}
}

		  while (boja!='k' || boja!='K' ); 
		  
         ZBIR=crna+bijela+siva+crvena+plava;
         
         printf("Ukupno evidentirano %g vozila.\n",ZBIR); 
         	
         
          if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava)
          {
          	max=crna;
          }
          else if (bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava)
          {
          	max=bijela;
          }
          else if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava)
          {
          	max=siva;
          }
          else if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava)
          {
          	max=crvena;
          }
          else if(plava>=crna && plava>=bijela && plava>=siva && plava>=crvena)
          {
          	max=plava;
          } 
          
          if (ZBIR==0)
           {
          	IZNOS=0;
           } 
           else 
           {
          
           IZNOS=(max*100)/ZBIR;
           }
           
		if(max==crna)
		{
			printf("Najpopularnija boja je crna (%.2f%%).\n", IZNOS);
		}
			else if(max==bijela)
		{
			printf("Najpopularnija boja je bijela (%.2f%%).\n", IZNOS);
		}
			else if(max==siva)
		{
			printf("Najpopularnija boja je siva (%.2f%%).\n", IZNOS);
		}
			else if(max==crvena)
		{
			printf("Najpopularnija boja je crvena (%.2f%%).\n", IZNOS);
		}
			else if(max==plava)
		{
			printf("Najpopularnija boja je plava (%.2f%%).\n", IZNOS);
		}
		return 0;
} 
		
		
			
