#include <stdio.h>
#define PK 6.80
#define PT 8.0
#define PL 5.30
#define HK 3.30
#define HT 3.0
#define HL 5.0
#define CK 5.0
#define CT 3.9
#define CL 6.0
int main()
{
    char tarik,bojan,mirza,novi_red;
    float ukupnoK=0.0,ukupnoT=0.0,ukupnoL=0.0,popust;
    int brojacP=0,brojacH=0,brojacC=0;
    printf("Unesite jelo za Tarika: ");
    scanf("%c",&tarik);
    scanf("%c",&novi_red);
    switch(tarik)
    {
    	case 'P':
    	ukupnoK+=PK;
    	ukupnoT+=PT;
    	ukupnoL+=PL;
    	brojacP++;
    	break;
    	case 'H':
    	ukupnoK+=HK;
    	ukupnoT+=HT;
    	ukupnoL+=HL;
    	brojacH++;
    	break;
    	case 'C':
    	ukupnoK+=CK;
    	ukupnoT+=CT;
    	ukupnoL+=CL;
    	brojacC++;
    	break;
    }
    printf("Unesite jelo za Bojana: ");
    scanf("%c",&bojan);
    scanf("%c",&novi_red);
    switch(bojan)
    {
     	case 'P':
    	ukupnoK+=PK;
    	ukupnoT+=PT;
    	ukupnoL+=PL;
    	brojacP++;
    	break;
    	case 'H':
    	ukupnoK+=HK;
    	ukupnoT+=HT;
    	ukupnoL+=PL;
    	brojacH++;
    	break;
    	case 'C':
    	ukupnoK+=CK;
    	ukupnoT+=CT;
    	ukupnoL+=CL;
    	brojacC++;
    	break;
    }
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&mirza);
    scanf("%c",&novi_red);
    switch(mirza)
    {
        case 'P':
    	ukupnoK+=PK;
    	ukupnoT+=PT;
    	ukupnoL+=PL;
    	brojacP++;
    	break;
    	case 'H':
    	ukupnoK+=HK;
    	ukupnoT+=HT;
    	ukupnoL+=PL;
    	brojacH++;
    	break;
    	case 'C':
    	ukupnoK+=CK;
    	ukupnoT+=CT;
    	ukupnoL+=CL;
    	brojacC++;
    	break;
    }
    if(ukupnoK<ukupnoT&&ukupnoK<ukupnoL)
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM). ",ukupnoK);
     else if(ukupnoT<ukupnoK&&ukupnoT<ukupnoL)
        {
                 printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",ukupnoT);
                 if(brojacP!=0)
                 {
                 popust=ukupnoK-(PK*0.1*brojacP);
                                       if(ukupnoT>popust)
                 printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM). ",popust);
                 }
                 else if(brojacH!=0)
                 {
                 popust=ukupnoK-(HK*0.1*brojacH);
                                       if(ukupnoT>popust)
                 printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM). ",popust);
                 }
                 else
                 {
                 popust=ukupnoK-(CK*0.1*brojacC);
                                       if(ukupnoT>popust)
                 printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM), ",popust);
                 }
        }
     else if(ukupnoL<ukupnoK&&ukupnoL<ukupnoT) 
                {
                 printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM). ",ukupnoL);
                 if(brojacP!=0)
                 {
                 popust=ukupnoK-(PK*0.1*brojacP);
                                      if(ukupnoL>popust)
                 printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM). ",popust);
                 }
                 else if(brojacH!=0)
                 {
                 popust=ukupnoK-(HK*0.1*brojacH);
                                       if(ukupnoL>popust)
                 printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM). ",popust);
                 }
                 else
                 {
                 popust=ukupnoK-(CK*0.1*brojacC);
                                       if(ukupnoL>popust)
                 printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM). ",popust);
                 }
                }
	return 0;
}
