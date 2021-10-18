#include <stdio.h>

int main() {
	char tarik;
	char bojan;
	char mirza;
	float Restoran, FastFood, Bistro;
   float Restoran2;
	char novired;
	float popustP;
   float popustH;
   float popustC;
   
	
	Restoran=0.00;
	FastFood=0.00;
	Bistro=0.00;
	popustC=0.00;
	popustH=0.00;
	popustP=0.00;
	
	
	printf ("Unesite jelo za Tarika: "); scanf ("%c" ,&tarik);
	scanf ("%c", &novired);
	printf ("Unesite jelo za Bojana: "); scanf ("%c" ,&bojan);
	scanf ("%c", &novired);
	printf ("Unesite jelo za Mirzu: "); scanf ("%c" ,&mirza);

	switch (tarik) {

   	case 'H' :
      Restoran = Restoran + 3.30;
      FastFood+=3.00;
      Bistro+=5.00;
      break;
		   
		case 'P':
      Restoran+=6.80;
      FastFood+=8.00;
      Bistro+=5.30;
      break;
      
      	case 'C'  :
      Restoran+=5.00;
      FastFood+=3.90;
      Bistro+=6.00;
      break;
	}
	
	switch(bojan) {

   	case 'H'  :
      Restoran=Restoran + 3.30;
      FastFood+=3.00;
      Bistro+=5.00;
      break;
		
		case 'P'  :
      Restoran+=6.80;
      FastFood+=8.00;
      Bistro+=5.30;
      break;
      
      	case 'C'  :
      Restoran+=5.00;
      FastFood+=3.90;
      Bistro+=6.00;
      break;
	}
	
	switch(mirza) {

   	case 'H'  :
      Restoran=Restoran + 3.30;
      FastFood+=3.00;
      Bistro+=5.00;
      break;
		
		case 'P'  :
      Restoran+=6.80;
      FastFood+=8.00;
      Bistro+=5.30;
      break;
      
      	case 'C'  :
      Restoran+=5.00;
      FastFood+=3.90;
      Bistro+=6.00;
      break;
	}
	if (Restoran<Bistro && Restoran<FastFood) printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",Restoran);
   else if (Bistro<Restoran && Bistro<FastFood) printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM). ",Bistro);
   else printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",FastFood);
   
   if (Restoran > Bistro || Restoran > FastFood){
     if (tarik=='P' || bojan=='P'||mirza=='P'){
        popustP=0.68;
      if (tarik==mirza && tarik==bojan) popustP=2.04;
      else if ((tarik=='P' && mirza=='P' )||( tarik =='P' && bojan=='P' )|| (bojan=='P' && mirza=='P')) popustP=1.36;
     }
     
     if (tarik=='C' || bojan=='C'||mirza=='C'){
        popustC=0.50;
        if (tarik==mirza && tarik==bojan) popustC=1.50;
      else if ((tarik=='C' && mirza=='C')+ || (tarik =='C' && bojan=='C' )||( bojan=='C' && mirza=='C')) popustC=1.00;
      
     }
     
     if (tarik=='H' || bojan=='H'||mirza=='H'){
        popustH=0.33;
     
      if (tarik==mirza && tarik==bojan) popustH=0.99;
      else if ((tarik=='H' && mirza=='H') ||( tarik =='H' && bojan=='H' )|| (bojan=='H' && mirza=='H')) popustH=0.66;
      Restoran2=0.00;
     }
if (popustH>popustC && popustH >popustP) Restoran2=Restoran-popustH;
else if (popustP>popustH && popustP>popustC) Restoran2=Restoran-popustP;
else Restoran2=Restoran-popustC;
   
   }
   if (FastFood<Restoran || Bistro<Restoran){
  if (Restoran2<Bistro && Restoran2<FastFood ){
      printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", Restoran2);
      
   }
   }
   	return 0;
}
 