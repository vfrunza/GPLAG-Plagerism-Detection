#include <stdio.h>

int main() 
{
	char u;
	float crna=0,bijela=0,siva=0,crvena=0,plava=0,UkV=0,poscrn=0.0,poscrv=0.0,posbij=0.0,possiv=0.0,pospl=0.0,pos=0;
	printf("Unesite vozila: ");
    do{
    	scanf("%c",&u);
    
    	if((u=='C')||(u=='c'))
    	{
    	    crna++;continue;
    	}
    	if((u=='B')||(u=='b'))
    	{
    		bijela++;
    		continue;
    	}
    	if((u=='S')||(u=='s'))
    	{
    		siva++;
    		continue;
    	}
        if((u=='V')||(u=='v'))
    	{
    		crvena++;
    		continue;
    	}
    	if((u=='P')||(u=='p'))
    	{
    		plava++;
    		continue;
    	}
    	if(((u!='C')&&(u!='c'))&&((u!='B')&&(u!='b'))&&((u!='S')&&(u!='s'))&&((u!='V')&&(u!='v'))&&((u!='P')&&(u!='p'))&&((u!='k')&&(u!='K')))
    {
        printf("Neispravan unos\n");
        
    }
    }
    while((u!='K')&&(u!='k'));
    UkV=crna+crvena+bijela+siva+plava;
    printf("Ukupno evidentirano %g vozila.",UkV);
    if(UkV!=0)
    {
        poscrn=(crna*100)/UkV;
        posbij=(bijela*100)/UkV;
        possiv=(siva*100)/UkV;
        poscrv=(crvena*100)/UkV;
        pospl=(plava*100)/UkV;
        
    }
    if((crna>=bijela)&&(crna>=siva)&&(crna>=crvena)&&(crna>=plava))
    {
        printf("\nNajpopularnija boja je crna (%.2f%%).",poscrn);
        return 0;
    }
    if((bijela>=crna)&&(bijela>=siva)&&(bijela>=crvena)&&(bijela>=plava))
    {
        printf("\nNajpopularnija boja je bijela (%.2f%%).",posbij);
        return 0;
    }
    if((siva>=crna)&&(siva>=bijela)&&(siva>=crvena)&&(siva>=plava))
    {
        printf("\nNajpopularnija boja je siva (%.2f%%).",possiv);
        return 0;
    }
    if((crvena>=crna)&&(crvena>=bijela)&&(crvena>=siva)&&(crvena>=plava))
    {
        printf("\nNajpopularnija boja je crvena (%.2f%%).",poscrv);
        return 0;
    }
    if((plava>=crna)&&(plava>=bijela)&&(plava>=siva)&&(plava>=crvena))
    {
        printf("\nNajpopularnija boja je plava (%.2f%%).",pospl);
        return 0;
    }
    return 0;
}
