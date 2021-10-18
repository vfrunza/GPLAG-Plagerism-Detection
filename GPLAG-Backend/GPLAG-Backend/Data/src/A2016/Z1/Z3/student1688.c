#include <stdio.h>

int main() {
	char slovo;
	int br1=0,br2=0,br3=0,br4=0,br5=0,i=0;
	float j;
	printf("Unesite vozila: ");
	do {
	   scanf("%c",&slovo);
	   while (i==0 && slovo!='K' && slovo!='k' && slovo!='C' && slovo!='c' && slovo!='B' && slovo !='b' && slovo!='S' && slovo!='s' && slovo!='V' && slovo!='v' && slovo!='P' && slovo!='p')
	   {
	   	printf("Neispravan unos\n");
	   	scanf("%c",&slovo);
	   } 
	   
	     if  (i!=0  && slovo!='K' && slovo!='k' && slovo!='C' && slovo!='c' && slovo!='B' && slovo !='b' && slovo!='S' && slovo!='s' && slovo!='V' && slovo!='v' && slovo!='P' && slovo!='p')
	  
	   { printf("Neispravan unos\n");
	   
	  
	   i--;
	   

	} 
	

	   if(slovo=='C' || slovo=='c')
	   br1++;
	   if(slovo=='B' || slovo=='b')
	   br2++;
	   if(slovo=='S' || slovo=='s')
	   br3++;
	   if(slovo=='V' || slovo=='v')
	   br4++;
	   if(slovo=='P' || slovo=='p')
	   br5++;
	  
	   i++; 
	   
	}while(slovo!='k' && slovo!='K');
	
	i=i-1;
   if(i==0)  {
   	j=i;
   printf("Ukupno evidentirano %d vozila.\n",i);
   printf("Najpopularnija boja je crna (%.2f%%).\n",j);
  }
    if(i!=0) {
    printf("Ukupno evidentirano %d vozila.\n",i);
	if(br1>=br2 && br1>=br3 && br1>=br4 && br1>=br5)
	printf("Najpopularnija boja je crna (%.2f%%).",(100./i)*br1);
	if( br2>br1 && br2>=br3 && br2>=br4 && br2>=br5)
	printf("Najpopularnija boja je bijela (%.2f%%).",(100./i)*br2);
	if( br3>br1 && br3>br2 && br3>=br4 && br3>=br5)
	printf("Najpopularnija boja je siva (%.2f%%).",(100./i)*br3);
	if(br4>br1 && br4>br2 && br4>br3 && br4>=br5)
	printf("Najpopularnija boja je crvena (%.2f%%).",(100./i)*br4);
	if( br5>br1 && br5>br2 && br5>br3 && br5>br4)
	printf("Najpopularnija boja je plava (%.2f%%).",(100./i)*br5); }
	
	return 0;
}
