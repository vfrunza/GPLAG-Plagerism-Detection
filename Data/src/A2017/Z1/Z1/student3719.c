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
	float x1,x2,x3,y1,y2,y3;
	 
   	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza );
	scanf("%c",&novi_red);
   
   if (tarik=='H' && bojan=='H' && mirza=='H'){
   	x1=3*H1; x2=3*H2; x3=3*H3;
   	y1=3*H1-3*H1/10;  
   	  if (x1<x2 && x1<x3){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2f KM).",x1);}
   	  
     else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
       if(y1<x2 ){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
 
     
        else return 0;}
             
       else if(x3<x1 && x3<x2){
       printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
       if( y1<x3){
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
        
        else return 0;}
     }
       
       else  if  ( (tarik=='H' && bojan=='P' && mirza=='P') ||(tarik=='P' && bojan=='H' && mirza=='P') ||(tarik=='P' && bojan=='P' && mirza=='H')){
          x1=H1+P1*2; x2=H2+2*P2; x3=H3+2*P3;
          y1=(H1+2*P1)-2*P1/10; y2=(H1+2*P1)-H1/10;
          
           if (x1<x2 && x1<x3){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2f KM).\n",x1);}
   	  
     else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
       if(y1<y2 && y1<x2){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
 
      else if(y2<y1 && y2<x2) {       
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);} 
        else return 0;}
             
       else if(x3<x1 && x3<x2){
       printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
       if(y1<y2 && y1<x3){
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
         else if(y2<y1 && y2<x3)        {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);}
        else return 0;}}
     
      
       
      else if((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H'&& bojan=='P' && mirza=='H') ||(tarik=='P' && bojan=='H' && mirza=='H')){
           x1=2*H1+P1;   x2=2*H2+P2; x3=2*H3+P3;
          y1=(2*H1+P1)-2*H1/10; y2=(2*H1+P1)-P1/10;
   if (x1<x2 && x1<x2){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",x1);}
   	  
     else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
       if(y1<x2 && y1<y2){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
 
      else if(y2<y1 && y2<x2) {       
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);} 
        else return 0;}
             
       else if(x3<x1 && x3<x2){
       printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
       if(y1<y2 && y1<x3){
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
         else if(y2<y1 && y2<x3)        {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);}
        else return 0;} }
        
       
       else if(tarik=='C' && bojan=='C' && mirza=='C'){
       x1=3*C1; x2=3*C2; x3=3*C3;
       y1=3*C1-3*C1/10; 
       if (x1<x2 && x1<x2){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",x1);}
   	  
       else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);}
       if(y1<x2){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
  else
        return 0;}
        
        else if((tarik=='C' && bojan=='H' && mirza=='P')||(tarik=='P' && bojan=='C' && mirza=='H')||(tarik=='H' && bojan=='P' && mirza=='C')){
        x1=C1+P1+H1; x2=P2+H2+C2; x3=P3+H3+C3;
        y1=(C1+H1+P1)-C1/10; y2=(C1+P1+H1)-H1/10; y3=(C1+H1+P1)-P1/10;
        if (x1<x2 && x1<x2){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",x1);}
   	  
        else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
         if(y1<x2 && y1<y2 && y1<y3){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
         
 
      else if(y2<y1 && y2<x2 && y2<y3) {       
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);} 
        else if(y3<y1 && y3<x2 && y3<y2){
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y3);} }
             
       else if(x3<x1 && x3<x2){
       printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
       if(y1<y2 && y1<x3){
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
         else if(y2<y1 && y2<x3)        {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);}
        else if(y3<y1 && y3<x2 && y3<y2){
     printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y3);} }
     
     else
      return 0;}
      
      else if(tarik=='P' && bojan=='P' && mirza=='P'){
      x1=3*P1; x2=3*P2; x3=3*P3;
      y1=3*P1-3*P1/10;
      if (x1<x2 && x1<x3){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2f KM).",x1);}
   	  
     else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
       if(y1<x2 ){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
 
     
        else return 0;}
             
       else if(x3<x1 && x3<x2){
       printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
       if( y1<x3){
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}}
         
        else return 0;}
        
        else if((tarik=='C'&& bojan=='C' && mirza=='P')||(tarik=='C' && bojan=='P' && mirza=='C')||(tarik=='P' && bojan=='C' && mirza=='C')){
            x1=2*C1+P1; x2=2*C2+P2; x3=2*C3+P3;
            y1=(2*C1+P1)-2*C1/10; y2=(2*C1+P1)-P1/10;
         if (x1<x2 && x1<x2){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",x1);}
   	  
     else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
       if(y1<x2 && y1<y2){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
 
      else if(y2<y1 && y2<x2) {       
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);} 
        else return 0;}
             
       else if(x3<x1 && x3<x2){
       printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
       if(y1<y2 && y1<x3){
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
         else if(y2<y1 && y2<x3)        {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);}
        else return 0;} }
        
        
        else if((tarik=='P' && bojan=='P' && mirza=='C')|| (tarik=='P' && bojan=='C' && mirza=='P')){
            x1=2*P1+C1; x2=2*P2+C2; x3=2*P3+C3;
            y1=(2*P1+C1)-2*P1/10; y2=(2*P1+C1)-C1/10;
            if (x1<x2 && x1<x3){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",x1);}
   	  
     else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
       if(y1<x2 && y1<y2){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
 
      else if(y2<y1 && y2<x2) {       
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);} 
        else return 0;}
             
       else if(x3<x1 && x3<x2){
       printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
       if(y1<y2 && y1<x3){
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
         else if(y2<y1 && y2<x3)        {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);}
        else return 0;} }
        
        else if((tarik=='H' && bojan=='C'&& mirza=='C')||(tarik=='C' && bojan=='H' && mirza=='C')||(tarik=='C' && bojan=='C' && mirza=='H')){
          x1=2*C1+H1; x2=2*C2+H2; x3=2*C3+H3;
          y1=(2*C1+H1)-2*C1/10; y2=(2*C1+H1)-H1/10;
           if (x1<x2 && x1<x3){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",x1);}
   	  
     else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
       if(y1<x2 && y1<y2){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
 
      else if(y2<y1 && y2<x2) {       
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);} 
        else return 0;}
             
       else if(x3<x1 && x3<x2){
       printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
       if(y1<y2 && y1<x3){
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
         else if(y2<y1 && y2<x3)        {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);}
        else return 0;} }
        
        else if((tarik=='H' && bojan=='C' && mirza=='H')||(tarik=='H' && bojan=='H' && mirza=='C')||(tarik=='C' && bojan=='H'&& mirza=='H')){
        x1=2*H1+C1; x2=2*H2+C2; x3=2*H3+C3;
        y1=(2*H1+C1)-C1/10; y2=(2*H1+C1)-2*H1/10;
          if (x1<x2 && x1<x3){
   	     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",x1);}
   	  
     else  if(x2<x1 && x2<x3){
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",x2);
       if(y1<x2 && y1<y2){
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
 
      else if(y2<y1 && y2<x2) {       
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);} 
        else return 0;}
             
       else if(x3<x1 && x3<x2){
       printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",x3);
       if(y1<y2 && y1<x3){
       printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y1);}
         else if(y2<y1 && y2<x3)        {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",y2);}
        else return 0;} }
        
        
        return 0;}
     
      
           
        
        

    
  