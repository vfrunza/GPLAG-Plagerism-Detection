# include<stdio.h>


int main() {
	
	int brojac=0;
	int brojac_C=0, brojac_B=0, brojac_S=0, brojac_V=0, brojac_P=0;
	char boja_automobila;
	printf("Unesite vozila: ");
	
	do
	{ 
	  scanf("%c", &boja_automobila);
	  
	  if(boja_automobila<65 || (boja_automobila>90 && boja_automobila<97) || boja_automobila>122) 
	  {printf("Neispravan unos\n");
	  continue;}
	  if(boja_automobila!='C' && boja_automobila!='c' && boja_automobila!='B' && boja_automobila!='b' && boja_automobila!='S' && boja_automobila!='s' && boja_automobila!='V' && boja_automobila!='v' && boja_automobila!='P' && boja_automobila!='p' && boja_automobila!='K' && boja_automobila!='k')
	  {printf("Neispravan unos\n");
	  continue;}
	  
	  if(boja_automobila=='C' || boja_automobila=='c')brojac_C++;
	  if(boja_automobila=='B' || boja_automobila=='b')brojac_B++;
	  if(boja_automobila=='S' || boja_automobila=='s')brojac_S++;
	  if(boja_automobila=='V' || boja_automobila=='v')brojac_V++;
	  if(boja_automobila=='P' || boja_automobila=='p')brojac_P++;
	  
	  if(boja_automobila=='C' || boja_automobila=='c' || boja_automobila=='B' || boja_automobila=='b' || boja_automobila=='S' || boja_automobila=='s' || boja_automobila=='V' || boja_automobila=='v' || boja_automobila=='P' || boja_automobila=='p')
	  brojac++;}  
	  while(boja_automobila!='K' && boja_automobila!='k');
	  
	  
	  printf("Ukupno evidentirano %d vozila.\n",brojac);
	  
	  /*Slucaj evidentiranja 0 vozila*/
	  
	  if(brojac==0) printf("Najpopularnija boja je crna (0.00%).");
	  

	  /*Najpopularnija boja*/
	  
	  else if(brojac_C>=brojac_B && brojac_C>=brojac_S && brojac_C>=brojac_P && brojac_C>=brojac_V)
	  
	  { printf("Najpopularnija boja je crna (%.2f%).", ((float)brojac_C/brojac)*100);} 
	  
	  
	  
	  else if(brojac_B>=brojac_C && brojac_B>=brojac_V && brojac_B>=brojac_S && brojac_B>=brojac_P && brojac!=0)
	  
	  { if(brojac_B==brojac_C)printf("Najpopularnija boja je crna (%.2f%).",((float)brojac_C/brojac)*100);
	  else printf("Najpopularnija boja je bijela (%.2f%).", ((float)brojac_B/brojac)*100);}
	  
	  
	  
	  else if(brojac_S>=brojac_C && brojac_S>=brojac_B && brojac_S>=brojac_P && brojac_S>=brojac_V && brojac!=0)
	  
	  {if(brojac_S==brojac_C)printf("Najpopularnija boja je crna (%.2f%).", ((float)brojac_C/brojac)*100);
	  else if(brojac_S==brojac_B)printf("Najpopularnija boja je bijela (%.2f%).", ((float)brojac_B/brojac)*100);
	  else printf("Najpopularnija boja je siva (%.2f%).", ((float)brojac_S/brojac)*100);}
	  
	  
	  
	  else if(brojac_V>=brojac_C && brojac_V>=brojac_B && brojac_V>=brojac_S && brojac_V>=brojac_P && brojac!=0)
	  
	  {if(brojac_V==brojac_C)printf("Najpopularnija boja je crna (%.2f%)", ((float)brojac_C/brojac)*100);
	  	else if(brojac_V==brojac_B)printf("Najpopularnija boja je bijela (%.2f%)", ((float)brojac_B/brojac)*100);
	  	else if(brojac_V==brojac_S)printf("Najpopularnija boja je siva (%.2f%)", ((float)brojac_S/brojac)*100);
	  	else
	  printf("Najpopularnija boja je crvena (%.2f%).", ((float)brojac_V/brojac)*100);
	  }
	  
	  
	  else if(brojac_P>=brojac_C && brojac_P>=brojac_V && brojac_P>=brojac_S && brojac_P>=brojac_B && brojac!=0){
	  	
	  	if(brojac_P==brojac_C)printf("Najpopularnija boja je crna (%.2f%)", ((float)brojac_C/brojac)*100);
	  	if(brojac_P==brojac_B)printf("Najpopularnija boja je bijela (%.2f%)", ((float)brojac_B/brojac)*100);
	  	if(brojac_P==brojac_S)printf("Najpopularnija boja je siva (%.2f%)", ((float)brojac_S/brojac)*100);
	  	if(brojac_P==brojac_V)printf("Najpopularnija boja je crvena (%.2f%)", ((float)brojac_V/brojac)*100);
	  	else 
	  	printf("Najpopularnija boja je plava (%.2f%).", ((float)brojac_P/brojac)*100);}
	  
	  

	
	return 0;
}
