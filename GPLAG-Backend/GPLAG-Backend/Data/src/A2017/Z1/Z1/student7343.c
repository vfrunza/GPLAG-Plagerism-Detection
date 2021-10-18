#include <stdio.h>
#define RP 6.80
#define RH 3.30
#define RC 5.00
#define FP 8.00
#define FH 3.00
#define FC 3.90
#define BP 5.30
#define BH 5.00
#define BC 6.00

int main() {
	float CR,CB,CF,P1,P2,P3,P4,P5,P6,CSP1,CSP2,CSP3,CSP4,CSP5,CSP6;
	char Tarik,Bojan,Mirza,novi_red;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);
	

   if((Tarik=='P' && Bojan=='P' && Mirza=='P') || (Tarik=='H' && Bojan=='H' && Mirza=='H') || (Tarik=='C' && Bojan=='C' && Mirza=='C')
   || (Tarik=='P' && Bojan=='H' && Mirza=='H') || (Tarik=='H' && Bojan=='H' && Mirza=='P') || (Tarik=='C' && Bojan=='C' && Mirza=='H')
   || (Tarik=='P' && Bojan=='C' && Mirza=='C') || (Tarik=='H' && Bojan=='H' && Mirza=='C') || (Tarik=='C' && Bojan=='C' && Mirza=='P')
   || (Tarik=='P' && Bojan=='H' && Mirza=='C') || (Tarik=='H' && Bojan=='P' && Mirza=='P') || (Tarik=='C' && Bojan=='H' && Mirza=='P')
   || (Tarik=='P' && Bojan=='C' && Mirza=='H') || (Tarik=='H' && Bojan=='P' && Mirza=='C') || (Tarik=='C' && Bojan=='H' && Mirza=='C')
   || (Tarik=='P' && Bojan=='H' && Mirza=='P') || (Tarik=='H' && Bojan=='C' && Mirza=='C') || (Tarik=='C' && Bojan=='H' && Mirza=='H')
   || (Tarik=='P' && Bojan=='C' && Mirza=='P') || (Tarik=='H' && Bojan=='C' && Mirza=='H') || (Tarik=='C' && Bojan=='P' && Mirza=='H')
   || (Tarik=='P' && Bojan=='P' && Mirza=='H') || (Tarik=='H' && Bojan=='P' && Mirza=='H') || (Tarik=='C' && Bojan=='P' && Mirza=='C')
   || (Tarik=='P' && Bojan=='P' && Mirza=='C') || (Tarik=='H' && Bojan=='C' && Mirza=='P') || (Tarik=='C' && Bojan=='P' && Mirza=='P'))
       
       if((3*RP)<(3*FP) && (3*RP)<(3*BP)) {
       CR=3*RP;   printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);
       }
       else if ((3*BP)<(3*RP) && (3*BP)<(3*FP)) {
       CB=3*BP;  printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CB);
        if(CSP1 < CB)  { CSP1=CR-P1; CR=3*RP; P1=(RP/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1);  } }}
           
       
            
       else if((FP*3) < (RP*3) && (FP*3) < (BP*3)) {
       CF=3*FP;  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CF);
            if( CSP1< CF) { CSP1=CR-P1 ; CR=3*RP; P1=(CR/100)*10;  {printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP1); } }}
            
        
       
        if((3*RH)<(3*FH) && (3*RH)<(3*BH)) {
       CR=3*RH;   printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);
       }
       else if ((3*BH)<(3*RH) && (3*BH)<(3*FH)) {
       CB=3*BH;   printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CB);
            if(CSP5 < CB) { CSP5=CR-P5;CR=3*RP; P5=(RH/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP5); } }}
           
       
            
       else if ((FP*3) < (RP*3) && (FP*3) < (BP*3)) {
       CF=3*FP;  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CF);
            if(CSP5 < CF) { CSP5=CR-P5; CR=3*RH; P5=(CR/100)*10;  { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP5); } }}
            
          
            
        if((3*RC)<(3*FC) && (3*RC)<(3*BC)) {
       CR=3*RC;    printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);
       }
       else if((3*BC)<(3*RC) && (3*BC)<(3*FC)) {
       CB=3*BC;   printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CB);
            if((CSP6=CR-P6) < CB) { CSP6=CR-P6;CR=3*RC; P6=(RH/100)*10; {printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP6); } }}
            
       else if((FC*3) < (RC*3) && (FC*3) < (BC*3)) {
       CF=3*FC;  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CF);
            if((CSP6=CR-P6) < CF)  {CSP6=CR-P6; CR=3*RC; P6=(CR/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP6); } }}
            
         
            
        if((RH+RH+RP)<(BH+BH+BP) && (RH+RH+RP)<(FH+FH+FP)) {
       CR=RH+RH+RP;   printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);}
       
       else if((BH+BH+BP)<(RH+RH+RP) && (BH+BH+BP)<(FH+FH+FP)) {
       CB=BH+BH+BP;  printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CB);
            if(CSP2 < CB)  {CSP2=CR-P2; CB=BH+BH+BP; P2=(2*RH)/100*10;{ printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2); }}} 
            
       else if((FH+FH+FP) < (RH+RH+RP) && (FH+FH+FP) < (BH+BH+BP)) {
       CF=FH+FH+FP;  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CF);
            if(CSP2 < CF)  {CSP2=CR-P2; CB=BH+BH+BP; P2=((2*RH)/100)*10; {printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2); } }}
            
        
         
        if((RH+RH+RC)<(BH+BH+BC) && (RH+RH+RC)<(FH+FH+FC)) {
       CR=RH+RH+RC;   printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);
       }
       else if((BH+BH+BC)<(RH+RH+RC) && (BH+BH+BC)<(FH+FH+FC)) {
       CB=BH+BH+BC;  printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CB);
            if(CSP2 < CB) {CSP2=CR-P2; CR=RH+RH+RC; P2=((2*RH)/100)*10;  {printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2); } }}
            
       else if((FH+FH+FC) < (RH+RH+RC) && (FH+FH+FC) < (BH+BH+BC)) {
       CF=FH+FH+FC;  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CF);}
            if(CSP2 < CF)  {CSP2=CR-P2; CR=RH+RH+RC; P2=((2*RH)/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP2); } }
        
            
         if((RP+RP+RH)<(BP+BP+BH) && (RP+RP+RH)<(FP+FP+FH)) {
       CR=RP+RP+RH;   printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);
       }
       else if((BP+BP+BH)<(RP+RP+RH) && (BP+BP+BH)<(FP+FP+FH)) {
       CB=BP+BP+BH;  printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", CB);
            if(CSP3 < CB)  {CSP3=CR-P3; CR=RP+RP+RH; P3=((2*RP)/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3); } }}
            
       else if((FP+FH+FP) < (RP+RH+RP) && (FP+FH+FP) < (BP+BH+BP)) {
       CF=FP+FH+FP;  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CF );
            if(CSP3 < CF)  {CSP3=CR-P3; CR=RP+RP+RH; P3=((2*RP)/100)*10; {printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3); } }}
             
        
         if((RP+RP+RC)<(BP+BP+BC) && (RP+RP+RC)<(FP+FP+FC)) {
       CR=RP+RP+RC;   printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);
       }
       else if((BP+BP+BC)<(RP+RP+RC) && (BP+BP+BC)<(FP+FP+FC)) {
       CB=BP+BP+BC;  printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM) .\n",CB);
            if(CSP3 < CB)  {CSP3=CR-P3; CR=RP+RP+RC; P3=((2*RP)/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3); } }}
            
       else if((FP+FP+FC) < (RP+RC+RP) && (FP+FC+FP) < (BP+BC+BP)) {
       CF=FP+FC+FP;  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CF);
            if(CSP3 < CF)  {CSP3=CR-P3; CR=RP+RP+RC; P3=((2*RP)/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP3); } }}
            
                
          if((RP+RC+RC)<(BP+BC+BC) && (RP+RC+RC)<(FP+FC+FC)) {
       CR=RP+RC+RC;   printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);
       }
       else if((BP+BC+BC)<(RP+RC+RC) && (BP+BC+BC)<(FP+FC+FC)) {
       CB=BP+BC+BC;  printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CB);
            if(CSP4 < CB)  {CSP4=CR-P4; CR=RP+RC+RC; P4=((2*RP)/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4); } }}
            
       else if((FP+FC+FC) < (RC+RC+RP) && (FC+FC+FP) < (BC+BC+BP)) {
       CF=FC+FC+FP;  printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CF);
            if(CSP4 < CF)  {CSP4=CR-P4; CR=RP+RC+RC; P4=((2*RC)/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4); } }}
            
 
        
            
         if((RH+RC+RC)<(BH+BC+BC) && (RH+RC+RC)<(FH+FC+FC)) {
       CR=RH+RC+RC;   printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);
       }
       else if((BH+BC+BC)<(RH+RC+RC) && (BH+BC+BC)<(FH+FC+FC)) {
       CB=BH+BC+BC;  printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CB);
            if(CSP4 < CB)  {CSP4=CR-P4; CR=RH+RC+RC; P4=((2*RC)/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4); } }}
            
       else if((FH+FC+FC) < (RC+RC+RH) && (FC+FC+FH) < (BC+BC+BH)) {
       CF=FC+FC+FH; printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CF);
            if(CSP4 < CF)  {CSP4=CR-P4; CR=RH+RC+RC; P4=((2*RC)/100)*10; { printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", CSP4); } }}
         
    
         return 0;
    
}        

               
            