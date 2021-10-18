#include <stdio.h>
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00
#define C2 3.90
#define C3 6.00

int main() {
	char tarik,bojan,mirza,novi_red;
	float suma1,suma2,suma3,suma4,suma5,suma6;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	if(tarik=='C' && bojan=='C' && mirza=='C')
	{ suma1=3*C1;
	  suma2=3*C2;
	  suma3=3*C3;
	  suma4=3*C1-(3*C1*0.1);
	  
	  if((suma1<suma2) && (suma1<suma3))
	      {	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1); }
	     else if ((suma2<suma1) && (suma2<suma3))
	      { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
	       if((suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  
	  
	  
	  else return 0; }
	      else if ((suma3<suma1) && (suma3<suma2))
	      { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
	       if((suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  
	  
	  
	  else return 0; }
	      
	 
	}
	
	
	
	else if (tarik=='P' && bojan=='P' && mirza=='P') 
	{ suma1=3*P1;
	  suma2=3*P2;
	  suma3=3*P3;
	  suma5=3*P1-(3*P1*0.1);
	  if((suma1<suma2) && (suma1<suma3))
	    { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1); }
	  else if ((suma2<suma1) && (suma2<suma3))
	    { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2); 
	    	 if ((suma5<suma2) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	 
	  else return 0; 
	    }
	  else if ((suma3<suma1) && (suma3<suma2))
	    {printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
	    	 if ((suma5<suma2) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	 
	  else return 0; 
	    }
	  
	 
	}
	  
	
	
	else if (tarik=='H' && bojan=='H' && mirza=='H')
	{ suma1=3*H1;
	  suma2=3*H2;
	  suma3=3*H3;
	  suma5=3*H1-(3*H1*0.1);
	  if((suma1<suma2) && (suma1<suma3))
	  { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1); }
	  else if ((suma2<suma1) && (suma2<suma3))
	  { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
	  if ((suma5<suma2) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	  
	  else return 0;
	  }
	  else if ((suma3<suma1) && (suma3<suma2))
	  { printf("Najjeftinij je Bistro \"Lorelei\" (%.2f KM).", suma3);
	  if ((suma5<suma2) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	  
	  else return 0;}
	  	
    }
	  


	else if ((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='P' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='P' && mirza=='C'))
	{  suma1=C1+C1+P1;
	   suma2=2*C2+P2;
	   suma3=2*C3+P3;
	   suma4=2*C1+P1-(P1*0.1);
	   suma5=2*C1+P1-(2*C1*0.1);
	   if((suma1<suma2) && (suma1<suma3))
	   { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1); }
	   else if ((suma2<suma1) && (suma2<suma3))
	   {printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2); 
	   	 if((suma4<suma5) && (suma4<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	   else if ((suma4<suma5) && (suma4<suma3))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	   else if ((suma5<suma4) && (suma5<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	   else if ((suma5<suma4) && (suma5<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	   else return 0; 
	   }
	   else if ((suma3<suma1) && (suma3<suma2))
	   { printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
	    if((suma4<suma5) && (suma4<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	   else if ((suma4<suma5) && (suma4<suma3))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	   else if ((suma5<suma4) && (suma5<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	   else if ((suma5<suma4) && (suma5<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	   else return 0; }
	  
	}
	
	
	else if ((tarik=='C' && bojan=='C' && mirza=='H') || (tarik=='H' && bojan=='C' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='C'))
	{ suma1=2*C1+H1;
	  suma2=2*C2+H2;
	  suma3=2*C3+H3;
	  suma4=2*C1+H1-(2*C1*0.1);
	  suma5=2*C1+H1-(H1*0.1);
	  if((suma1<suma2) && (suma1<suma3))
	  { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1); }
	  
	  
	  else if ((suma2<suma1) && (suma2<suma3))
	  { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2); 
	  	if((suma4<suma5) && (suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  
	  else if ((suma5<suma4) && (suma5<suma2) && (suma5<suma3))
	  { printf("\n\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	  else return 0;
	  }
	  
	  
	  else if ((suma3<suma1) && (suma3<suma2))
	  { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3); 
	  if((suma4<suma5) && (suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  
	  else if ((suma5<suma4) && (suma5<suma2) && (suma5<suma3))
	  { printf("\n\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	  else return 0;}
	  
	}
	
	
	else if ((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P'))
	{ suma1=P1+P1+C1;
	  suma2=2*P2+C2;
	  suma3=2*P3+C3;
	  suma4=2*P1+C1-(2*P1*0.1);
	  suma5=2*P1+C1-(C1*0.1);
	  if ((suma1<suma2) && (suma1<suma3))
	  { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1); }
	  
	  
	  if ((suma2<suma1) && (suma2<suma3))
	  { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2); 
	  	if((suma4<suma5) && (suma4<suma2))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  else if ((suma4<suma5) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  else if ((suma5<suma4) && (suma5<suma2))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  else if((suma5<suma4) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  else return 0;
	  }
	  
	  else if ((suma3<suma1) && (suma3<suma2))
	  { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
	  if((suma4<suma5) && (suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  
	  else if ((suma5<suma4) && (suma5<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	  else return 0;}
	 
	}
	
	else if ((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='P'))
	{ suma1=P1+P1+H1;
	  suma2=2*P2+H2;
	  suma3=2*P3+H3;
	  suma4=2*P1+H1-(H1*0.1);
	  suma5=2*P1+H1-(2*P1*0.1);
	  if ((suma1<suma2) && (suma2<suma3))
	  { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1); }
	  
	  
	  else if((suma2<suma1) && (suma2<suma3))
	  { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
	  if((suma4<suma5) && (suma4<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	   else if ((suma4<suma5) && (suma4<suma3))
	   { printf("vSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	   else if ((suma5<suma4) && (suma5<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	   else if ((suma5<suma4) && (suma5<suma3))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	   else return 0; }
	  else if ((suma3<suma1) && (suma3<suma2))
	   {printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
	   if((suma4<suma5) && (suma4<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	   else if ((suma4<suma5) && (suma4<suma3))
	   { printf("vSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	   else if ((suma5<suma4) && (suma5<suma2))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	   else if ((suma5<suma4) && (suma5<suma3))
	   { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	   else return 0; }
	   
	  }
	  
	  else if((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='H'))
	{ suma1=2*H1+C1;
	  suma2=2*H2+C2;
	  suma3=2*H3+C3;
	  suma4=2*H1+C1-(C1*0.1);
	  suma5=2*H1+C1-(2*H1*0.1);
	  if ((suma1<suma2) && (suma1<suma3))
	  { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1); }
	  
	  
	  else if ((suma2<suma1) && (suma2<suma3))
	  { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
	   if ((suma4<suma5) && (suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	 
	  else if((suma5<suma4) && (suma5<suma2) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	  else return 0; }
	  
	  
	  else if ((suma3<suma1) && (suma3<suma2))
	  { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
	  if ((suma4<suma5) && (suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  
	  else if((suma5<suma4) && (suma5<suma2) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	  else return 0; }
	}
	
	else if ((tarik=='H' && bojan=='H' && mirza=='P') || (tarik='H' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='H'))
	{ suma1=H1+H1+P1;
	  suma2=2*H2+P2;
	  suma3=2*H3+P3;
	  suma4=2*H1+P1-(2*H1*0.1);
	  suma5=2*H1+P1-(P1*0.1);
	  if ((suma1<suma2) && (suma1<suma3))
	  { printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1); }
	  
	  else if ((suma2<suma1) && (suma2<suma3))
	  { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2); 
	     if((suma4<suma5) && (suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  
	  else if ((suma5<suma4) && (suma5<suma2) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	  else return 0;} 
	  
	  else if ((suma3<suma1) && (suma3<suma2))
	  { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
	  if ((suma4<suma5) && (suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  
	  else if ((suma5<suma4) && (suma5<suma2) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  
	  else return 0;}

	}
	

	

	
	
	
	
	 else  
    { suma1=C1+H1+P1;
      suma2=C2+H2+P2;
      suma3=C3+H3+P3;
      suma4=C1+H1+P1-(H1*0.1);
      suma5=C1+H1+P1-(P1*0.1);
      suma6=C1+H1+P1-(C1*0.1);
      if ((suma1<suma2) && (suma1<suma3))
      { printf("Najjeftiniji je Restoran \"kod konja i konjusara\" (%.2f KM).", suma1); }
      
      
      else if ((suma2<suma1) && (suma2<suma3))
	  { printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
	    if ((suma4<suma5) && (suma4<suma2) && (suma4<suma3) && (suma4<suma6))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  else if ((suma5<suma4) && (suma5<suma2) && (suma5<suma3) && (suma5<suma6))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  else if ((suma6<suma5) && (suma6<suma4) && (suma6<suma3) && (suma6<suma2))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma6); }
	  	else return 0;
	  }
	  
	  
	  else if ((suma3<suma1) && (suma3<suma2))
	  { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3); 
	   if ((suma4<suma5) && (suma4<suma6) && (suma4<suma2) && (suma4<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma4); }
	  else if ((suma5<suma4) && (suma5<suma6) && (suma5<suma2) && (suma5<suma3))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma5); }
	  else if ((suma6<suma5) && (suma6<suma4) && (suma6<suma3) && (suma6<suma2))
	  { printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma6); }
	  else return 0;
	  }
	  
	  
    }

	
	return 0;
}

