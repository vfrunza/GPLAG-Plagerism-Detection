#include <stdio.h>

int main () {
	char vozila;
    int a1=0,a2=0,a3=0,a4=0,a5=0,U=0;
	float NV;
	printf("Unesite vozila: ");
	scanf("%c",&vozila);
while(vozila!='k' || vozila!='K')	{
	
	
	if (vozila=='C')
	 {
	  a1++;}
	 else  if (vozila=='c')
	 { 
	  a1++;}
	  else if (vozila=='B')
	 { 
	  a2++;}
	  else if (vozila=='b')
	 { 
	  a2++;}
	  else if (vozila=='S')
	 { 
	  a3++;}
	  else if (vozila=='s')
	 {
	  a3++;}
	  else if (vozila=='V')
	 {
	  a4++;}
	  else if (vozila=='v')
	 { 
	  a4++;}
	  else if (vozila=='P')
	 { 
	  a5++;}
	  else if (vozila=='p')
	 { 
	  a5++;}
	  else if (vozila=='\n'  || vozila=='K' || vozila=='k')
	   break;
	   else printf("Neispravan unos\n"); 
	scanf("%c",&vozila);
}

     U=a1+a2+a3+a4+a5;
     if(U==0) {printf("Ukupno evidentirano 0 vozila.\n");}
      else printf("Ukupno evidentirano %.0d vozila.\n",U);
   
          if(U==0)printf("Najpopularnija boja je crna (0.00%%).");
          
        else if (a1>=a2 && a1>=a3 && a1>=a4 && a1>=a5) {
     	NV=(float)a1/U*100;
     	printf("Najpopularnija boja je crna (%.2f%%).",NV); }
     	
     	else if (a2>=a1 && a2>=a3 && a2>=a4 && a2>=a5) {
     	NV=(float)a2/U*100;
     	printf("Najpopularnija boja je bijela (%.2f%%).",NV); }
     	
     	else if (a3>=a2 && a3>=a1 && a3>=a4 && a3>=a5) {
     	NV=(float)a3/U*100;
     	printf("Najpopularnija boja je siva (%.2f%%).",NV); }
     	
     	else if (a4>=a2 && a4>=a3 && a4>=a1 && a4>=a5) {
     	NV=(float)a4/U*100;
     	printf("Najpopularnija boja je crvena (%.2f%%).",NV); }
     	
     	else if (a5>=a2 && a5>=a3 && a5>=a4 && a5>=a1) {
     	NV=(float)a5/U*100;
     	printf("Najpopularnija boja je plava (%.2f%%).",NV); }
    
    return 0; }
     
     
   
	