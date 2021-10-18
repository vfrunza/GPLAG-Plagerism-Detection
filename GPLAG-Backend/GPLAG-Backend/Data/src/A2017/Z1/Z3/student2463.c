#include <stdio.h>

int main() {
	
	char B; int rang=1; double crna=0,siva=0,bijela=0,crvena=0,plava=0;
	int rang_crna=0,rang_siva=0,rang_bijela=0,rang_crvena=0,rang_plava=0;
	int ukupno_boja=0;
	
	printf("Unesite vozila: ");
	
	do{
		scanf("%c",&B);
		
		if(B!='C' && B!='c' && B!='S' && B!='s' && B!='V' && B!='v' && B!='B' && B!='b' && B!='P' && B!='p' && B!='K' && B!='k')
		{
			printf("Neispravan unos\n");
			
		}
		 if(B=='C' || B=='c')
		 {
		 if(rang_crna==0)
		 	rang_crna=rang++;
		 	
		 	crna++;
		 	ukupno_boja++;
		 }
		 
		 else if(B=='S' || B=='s' )
		 {
		 	if(rang_siva==0)
		 	rang_siva=rang++;
		 	
		 	siva++;
		 	ukupno_boja++;
		 }
		 
		 else if(B=='B' || B=='b')
		 {
		 	if(rang_bijela==0)
		 	rang_bijela=rang++;
		 	
		 	bijela++;
		 	ukupno_boja++;
		 }
		 
		 else if(B=='V' || B=='v')
		 {
		 	if(rang_crvena==0)
		 	rang_crvena=rang++;
		 	
		 	crvena++;
		 	ukupno_boja++;
		 }
		 
		 else if(B=='P' || B=='p')
		 {
		 	if(rang_plava==0)
		 	rang_plava=rang++;
		 	
		 	plava++;
		 	ukupno_boja++;
		 }
	}while(B!='K' && B!='k');
	
	
	
	printf("Ukupno evidentirano %d vozila.\n",ukupno_boja);
	
	char C='C';
	int maks=crna; 
	int rangiran=rang_crna;
	
	
	if(maks<=siva)
	{
		if(maks==siva)
		{
			if(rangiran>rang_siva && rang_siva!=0)
			{
				maks=siva;
				rangiran=rang_siva;
				C='S';
			}
		}
		else 
		{
			maks=siva;
			rangiran=rang_siva;
			C='S';
		}
	}
	
	if(maks<=bijela)
	 {
	 	if(maks==bijela)
	 	{
	 		if(rangiran>rang_bijela && rang_bijela!=0)
	 		{
	 			maks=bijela;
	 			rangiran=rang_bijela;
	 			C='B';
	 		}
	 	}
	 	else
	 	{
	 		maks=bijela;
	 		rangiran=rang_bijela;
	 		C='B';
	 	}
	 }
	 
	 if(maks<=crvena)
	 {
	 	if(maks==crvena)
	 	{
	 		if(rangiran>rang_crvena && rang_crvena!=0)
	 		{
	 			maks=crvena;
	 			rangiran=rang_crvena;
	 			C='V';
	 		}
	 	}
	 	
	 	else
	 	{
	 		maks=crvena;
	 		rangiran=crvena;
	 		C='V';
	 	}
	 }
	 
	 if(maks<=plava)
	 {
	 	if(maks==plava)
	 	{
	 		if(rangiran>rang_plava && rang_plava!=0)
	 		{
	 			maks==plava;
	 			rangiran=rang_plava;
	 			C='P';
	 		}
	 	}
	 	else
	 	{
	 		maks=plava;
	 		rangiran=rang_plava;
	 		C='P';
	 	}
	 }
	 
	 
	 if(C=='C')
	 printf("Najpopularnija boja je crna (%.2f%%).",crna*100./ukupno_boja);
	 else if(C=='S')
	 printf("Najpopularnija boja je siva (%.2f%%).\n",siva*100./ukupno_boja);
	 else if(C=='B')
	 printf("Najpopularnija boja je bijela (%.2f%%).\n",bijela*100./ukupno_boja);
	 else if(C=='V')
	 printf("Najpopularnija boja je crvena (%.2f%%).\n",crvena*100./ukupno_boja);
	 else if(C=='P')
	 printf("Najpopularnija boja je plava (%.2f%%).\n",plava*100./ukupno_boja);
	return 0;
}
