#include <stdio.h>
#include <math.h>

int main() {
    float Rp=6.80,Rh=3.30,Rc=5.00,FFp=8.00,FFh=3.00,FFc=3.90,BISp=5.30,BISh=5.00,BISc=6.00,UK1=0,UK2=0,UK3=0,suma=0,min;
	   char  Tar=0,Boj=0,Mir=0,novi_red,C,H,P;
	 
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &Tar);
    scanf("%c",&novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &Boj);
    scanf("%c",&novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &Mir);
    scanf("%c", &novi_red);
    
    if(Tar=='P'){  
          UK1+=Rp;
          UK2+=FFp;
          UK3+=BISp;
    }
    else if(Tar=='H'){
          UK1+=Rh;
          UK2+=FFh;
          UK3+=BISh;
     }
     else if(Tar=='C'){
          UK1+=Rc;
          UK2+=FFc;
          UK3+=BISc;
     }
    if(Boj=='P'){
          UK1+=Rp;
          UK2+=FFp;
          UK3+=BISp;
          
     }
     else if(Boj=='H'){
          UK1+=Rh;
          UK2+=FFh;
          UK3+=BISh;
     }
     else if(Boj=='C'){
          UK1+=Rc;
          UK2+=FFc;
          UK3+=BISc;
     }
     if(Mir=='P'){
          UK1+=Rp;
          UK2+=FFp;
          UK3+=BISp;
     }
     else if(Mir=='H'){
          UK1+=Rh;
          UK2+=FFh;
          UK3+=BISh;
     }
     else if(Mir=='C'){
          UK1+=Rc;
          UK2+=FFc;
          UK3+=BISc;
     }
     min=UK1;
     if(UK2<min){
      min=UK2;
      printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
   
     }
     else if(UK3<min){
      min=UK3;
      printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min);
   
     }
     else
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", min);
  
    
     /* Restoran sa popustom i bez*/
      
      if(min!=UK1){
       
       
       if(Tar!=Boj && Tar!=Mir && Boj!=Mir){
        suma=Rh+Rp+Rc+-Rp*10/100;
        if(suma<UK2)
        printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma);
       }
         if(Tar='H' && (Tar==Boj || Tar==Mir))
       if(3*FFc>(3*Rc)-3*Rc*10/100)
       printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (3*Rp)-3*Rp*0.1);
         if(Tar=='C' && (Tar==Boj || Tar==Mir))
         if(3*FFc>(3*Rc)-3*Rc*10/100)
         printf("\nSa popustom bi Restoran bo jeftiniji (%.2f KM).", (2*Rc)-3*Rc*10/100);
         
         
           if(Tar=='H' && (Tar==Boj || Tar==Mir) && (Boj=='H' || Mir=='H'))
          if(2*FFh+FFp>(2*Rh+Rp)-2*Rp*10/100)
          printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (2*Rh+Rp)-Rp*10/100);
          
          
                if(Tar=='P' && (Tar==Boj || Tar==Mir) && (Boj=='H' || Mir=='H'))
          if(2*BISp+BISh>(2*Rp+Rh)-2*Rp*10/100)
          printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (2*Rp+Rh)-Rp*10/100);
          
               
                if(Tar=='P' && (Tar==Boj || Tar==Mir) && (Boj=='C' || Mir=='C'))
          if(2*BISp+BISc>(2*Rp+Rc)-2*Rp*10/100)
          printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (2*Rp+Rc)-Rp*10/100);
          
                if(Tar=='C' && (Tar==Boj || Tar==Mir) && (Boj=='P' || Mir=='P'))
          if(2*FFc+FFp>(2*Rc+Rp)-2*Rc*10/100)
          printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (2*Rc+Rp)-2*Rc*10/100);
          
                if(Tar=='C' && (Tar==Boj || Tar==Mir) && (Boj=='H' || Mir=='H'))
          if(2*FFc+FFh>(2*Rc+Rh)-2*Rc*10/100)
          printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (2*Rc+Rh)-2*Rc*10/100);
          
                if(Tar=='H' && (Tar==Boj || Tar==Mir) && (Boj=='C' || Mir=='C'))
          if(2*FFh+FFc>(2*Rh+Rc)-2*Rh*10/100)
          printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (2*Rh+Rc)-2*Rh*10/100);
          
          
          
          
          
       }
       return 0;
     
}
