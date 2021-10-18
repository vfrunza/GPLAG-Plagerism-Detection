#include <stdio.h>

int main() {
char a;
char n;
int br1=0;
int br2=0;
int br3=0;
int br4=0;
int br5=0;
int ukupno=0;
float procent;
float najboja;
printf("Unesite vozila: ");


do {
	
scanf("%c", &a);

	if (a=='c' || a=='C') {
		br1++;
	}
	if (a=='b' || a=='B') {
		br2++;
	}
	if (a=='s' || a=='S'){
		br3++;
	}
	if(a=='v' || a=='V'){
		br4++;
	}
	if(a=='p' || a=='P'){
	br5++;
    }
    
    
   
    
     if (br1>br2 && br1>br3 && br1>br4 && br1>br5 )
    n='c';
    
    if (br2>br1 && br2>br3 && br2>br4 && br2>br5 )
    n='b';
    
    if (br3>br1 && br3>br2 && br3>br4 && br3>br5 )
    n='s';
    
    if (br4>br1 && br4>br2 && br4>br3 && br4>br5 )
    n='v';
    
    if (br5>br1 && br5>br2 && br5>br3 && br5>br4 )
    n='p';
    
    
    	if(a!='c' && a!='C' && a!='b' && a!='B' && a!='s' && a!='s' && a!='S' && a!='v' && a!='V' && a!='p' && a!='P' && a!='k' && a!='K'){

		printf("Neispravan unos\n");
		scanf("%c", &a);
	}
	
		
	
	
}
while (a!='k' && a!='K') ;
    ukupno=br1+br2+br3+br4+br5;
    
     if(ukupno==0){
   printf("Neispravan unos\n");
   printf("Neispravan unos\n");

   printf("Ukupno evidentirano 0 vozila.\n");
   printf("Najpopularnija boja je crna (0.00%%).");
   return 0;
   }
   
   
    printf("Ukupno evidentirano %d vozila.\n", ukupno);
    
    
  
    if( n=='c') {
    	najboja=br1;
    	procent=((najboja/ukupno)*100);
    	
    
    printf("Najpopularnija boja je crna (%.2f%%).", procent) ;
}
   if( n=='b') {
    	najboja=br2;
    	procent=((najboja/ukupno)*100);
    	
    
    printf("Najpopularnija boja je bijela (%.2f%%).", procent) ;
}
   if( n=='s') {
    	najboja=br3;
    	procent=((najboja/ukupno)*100);
    	
    
    printf("Najpopularnija boja je siva (%.2f%%).", procent) ;
}

   if( n=='v') {
    	najboja=br4;
    	procent=((najboja/ukupno)*100);
    	
    
    printf("Najpopularnija boja je crvena (%.2f%%).", procent) ;
}

   if( n=='p') {
    	najboja=br5;
    	procent=((najboja/ukupno)*100);
    	
    
    printf("Najpopularnija boja je plava (%.2f%%).", procent) ;
}


	return 0;
}
