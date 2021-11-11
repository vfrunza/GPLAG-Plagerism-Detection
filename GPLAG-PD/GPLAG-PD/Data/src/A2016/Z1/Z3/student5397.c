#include <stdio.h>

int main() 
{

    char vozila, crna1, crna2, bijela1, bijela2, siva1, siva2, crvena1, crvena2, plava1, plava2, kraj1, kraj2;
    int m;
    double ncrna, nbijela, nsiva, ncrvena, nplava, crnad, bijelad, sivad, crvenad, plavad, ukupno;
    
    crna1='c';
    crna2='C';
    bijela1='b';
    bijela2='B';
    siva1='s';
    siva2='S';
    crvena1='v';
    crvena2='V';
    plava1='p';
    plava2='P';
    kraj1='k';
    kraj2='K';
    crnad=0;
    bijelad=0;
    sivad=0;
    crvenad=0;
    plavad=0;
    
    
    
    m=1;
	printf ("Unesite vozila: ");
	while (m==1)
	{
	  
		scanf ("%c", &vozila);
		
		if (vozila==crna1 || vozila==crna2)
		{
		    crnad=crnad+1;
		}
		else if (vozila==bijela1 || vozila==bijela2)
		{
		    bijelad=bijelad+1;
		}
		else if (vozila==siva1 || vozila==siva2)
		{
		    sivad=sivad+1;
		}
		else if (vozila==crvena1 || vozila==crvena2)
		{
		    crvenad=crvenad+1;
		}
		else if (vozila==plava1 || vozila==plava2)
		{
		    plavad=plavad+1;
		}
		else if (vozila==kraj1 || vozila==kraj2)
		{
		    m=0;
		}
		else 
		{
			printf ("Neispravan unos\n");
		}
		
	}
	
	ukupno=crnad+bijelad+sivad+crvenad+plavad;
	printf ("Ukupno evidentirano %.0f vozila.\n", ukupno);
	
	ncrna=(crnad/ukupno)*100;
	nbijela=(bijelad/ukupno)*100;
	nsiva=(sivad/ukupno)*100;
	ncrvena=(crvenad/ukupno)*100;
	nplava=(plavad/ukupno)*100;

	
	if ((ncrna>=nbijela)&&(ncrna>=nsiva)&&(ncrna>=ncrvena)&&(ncrna>=nplava))
	{
		if ((ncrna==nbijela)||(ncrna==nsiva)||(ncrna==ncrvena)||(ncrna==nplava))
	    {printf ("Najpopularnija boja je crna (%.2f%%).\n", ncrna);}
	    
	    else 
	    {printf ("Najpopularnija boja je crna (%.2f%%).\n", ncrna);}
	    
	}
	
	else if ((nbijela>=ncrna)&&(nbijela>=nsiva)&&(nbijela>=ncrvena)&&(nbijela>=nplava))
	{
		if ((nbijela==ncrna)||(nbijela==nsiva)||(nbijela==ncrvena)||(nbijela==nplava))
	    printf ("Najpopularnija boja je bijela (%.2f%%).\n", nbijela);
	    
	     else 
	    {printf ("Najpopularnija boja je bijela (%.2f%%).\n", nbijela);}
	}
	
	else if ((nsiva>=ncrna)&&(nsiva>=nbijela)&&(nsiva>=ncrvena)&&(nsiva>=nplava))
	{
		if ((nsiva==ncrna)||(nsiva==nbijela)||(nsiva==ncrvena)||(nsiva==nplava))
	    {printf ("Najpopularnija boja je siva (%.2f%%).\n", nsiva);}
	    
	    else 
	    {printf ("Najpopularnija boja je siva (%.2f%%).\n", nsiva);}
	}
	
	else if ((ncrvena>=ncrna)&&(ncrvena>=nbijela)&&(ncrvena>=nplava)&&(ncrvena>=nsiva))
	{
		if ((ncrvena==ncrna)||(ncrvena==nbijela)||(ncrvena==nplava)||(ncrvena==nsiva))
	    {printf ("Najpopularnija boja je crvena (%.2f%%).\n", ncrvena);}
	    
	    else 
	    {printf ("Najpopularnija boja je crvena (%.2f%%).\n", ncrvena);}
	}
	
	else if ((nplava>=ncrna)&&(nplava>=nbijela)&&(nplava>=ncrvena)&&(nplava>=nsiva))
	{
		if ((nplava==ncrna)||(nplava==nbijela)||(nplava==ncrvena)||(nplava==nsiva))
	    {printf ("Najpopularnija boja je plava (%.2f%%).\n", nplava);}
	    
	    else 
	    {printf ("Najpopularnija boja je plava (%.2f%%).\n", nplava);}
	}
	
	else
	{printf ("Najpopularnija boja je crna (0.00%).\n");}
	
	
	return 0;
}
