#include <stdio.h>

int main() {
  char a;
  int bijela=0,crvena=0,siva=0,plava=0,suma,crna=0;
  float p;
  printf("Unesite vozila: ");
	do{
		scanf("%c", &a);
		
    	if(a!='c' && a!='C' && a!='b' && a!='B' && a!='v' && a!='V' && a!='S' && a!='s' && a!='p' && a!='P' && a!='k'&& a!='K')
	      printf("Neispravan unos\n");
		else
		{ 
		if(a=='C' || a=='c')
		 crna++;
		else if(a=='B' || a=='b')
		 bijela++;
		else if(a=='S' || a=='s')
		 siva++;
		else if(a=='V' || a=='v')
		 crvena++;
		else if(a=='P' || a=='p')
		 plava++;
	}
	}	
   while(a!='k' && a!='K');


  suma=crna+crvena+plava+bijela+siva;	


 if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
   if(suma==0)
      p=100*crna;
    else
     p=(float)100*crna/suma;
    printf("Ukupno evidentirano %d vozila.\n",suma);
	printf("Najpopularnija boja je crna (%.2f%%).",p);
	
}
 else if(bijela>=siva && bijela>=crna && bijela>=crvena && bijela>=plava){
	if(suma==0)
	 p=100*bijela;
	else
	 p=(float)100*bijela/suma;
	 printf("Ukupno evidentirano %d vozila.\n",suma);
     printf("Najpopularnija boja je bijela (%.2f%%).",p);
}
 else if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava){
	if(suma==0)
	 p=100*siva;
	else
	 p=(float)100*siva/suma;
	 printf("Ukupno evidentirano %d vozila.\n",suma);
     printf("Najpopularnija boja je siva (%.2f%%).",p);
 }
 
 else if(crvena>=crna && crvena>=siva && crvena>=plava && crvena>=bijela){
 	if(suma==0)
 	 p=100*crvena;
 	else
 	 p=(float)100*crvena/suma;
 	printf("Ukupno evidentirano %d vozila.\n",suma);
 	printf("Najpopularnija boja je crvena (%.2f%%).",p);
 }
 
 else if(plava>=crvena && plava>=bijela && plava>=siva && plava>=crna){
	if(suma==0)
	 p=100*plava;
	else
	 p=(float)100*plava/suma;
	 printf("Ukupno evidentirano %d vozila.\n",suma);
     printf("Najpopularnija boja je plava (%.2f%%).",p);
	
}
	return 0;
}
