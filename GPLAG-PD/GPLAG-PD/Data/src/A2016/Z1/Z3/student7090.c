#include <stdio.h>

int main()
{
	char z;
	int i, crna=0, bijela=0, siva=0, crvena=0, plava=0, NAJPOP_BOJA=0;
	float PROCENAT_BOJA;
	printf("Unesite vozila: ");
	for(i=0;;i++){
		scanf("%c", &z);
		if(z=='K' || z=='k') break;
		else if (z==' ') {printf("Neispravan unos\n");i--;}
		else if(z!='c'&& z!='C' && z!='b' && z!='B' && z!='s' && z!='S' && z!='v' && z!='V' && z!='p' && z!='P')
		{
			printf("Neispravan unos\n");
			i--;
			continue;
	}
	    else if(z=='c' || z=='C')
	    {
	    	crna++;
	    	if(crna>NAJPOP_BOJA)
	    	NAJPOP_BOJA=crna;
	    }
	    else if(z=='b' || z=='B')
	    {
	    	bijela++;
	    	if(bijela>NAJPOP_BOJA)
	    	NAJPOP_BOJA=bijela;
	    }
	    else if(z=='s' || z=='S')
	    {
	    	siva++;
	    	if(siva>NAJPOP_BOJA)
	    	NAJPOP_BOJA=siva;
	    }
	    else if(z=='v' || z=='V')
	    {
	    	crvena++;
	    	if(crvena>NAJPOP_BOJA)
	    	NAJPOP_BOJA=crvena;
	    }
	    else if(z=='p' || z=='P')
	    {
	    	plava++;
	    	if(plava>NAJPOP_BOJA)
	    	NAJPOP_BOJA=plava;
	    }
}
      
      if(i==0) PROCENAT_BOJA=0;
      else
         PROCENAT_BOJA=(float)(NAJPOP_BOJA*100)/i;
         
      if(crna==NAJPOP_BOJA)
           printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crna (%.2f%%).", i, PROCENAT_BOJA);
      else if(bijela==NAJPOP_BOJA)
           printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je bijela (%.2f%%).", i, PROCENAT_BOJA);
      else if(siva==NAJPOP_BOJA)
           printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je siva (%.2f%%).", i, PROCENAT_BOJA);
      else if(crvena==NAJPOP_BOJA)
           printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crvena (%.2f%%).", i, PROCENAT_BOJA);
      else if(plava==NAJPOP_BOJA)
           printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je plava (%.2f%%).", i, PROCENAT_BOJA);
           
return 0;
}
           