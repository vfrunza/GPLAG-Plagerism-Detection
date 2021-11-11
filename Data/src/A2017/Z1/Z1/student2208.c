#include <stdio.h>
#define R1P 6.80
#define R1H 3.30
#define R1C 5.00
#define R2P 8.00
#define R2H 3.00
#define R2C 3.90
#define R3P 5.30
#define R3H 5.00
#define R3C 6.00

int main() 

{  char T, B, M, novi_red ;
     double cR=0, cFF=0, cBL=0, pr=0, hr=0, cr=0,  pb=0, hb=0, cb=0, pff=0, hff=0, cff=0; 
     novi_red="\n";
    printf("Unesite jelo za Tarika: ");
	  scanf("%c", &T);
	 scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
      scanf("%c", &B);
	  scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
      scanf("%c", &M);
	  scanf("%c", &novi_red);
	
         if (T=='P')
              { pr=pr+R1P;
                pb=pb+R3P;
                pff=pff+R2P;
                
              }
                
         if (T=='H')
            {
                hr=hr+R1H;
                hb=hb+R3H;
                hff=hff+R2H;
            }
                
          if (T=='C')
            
               { 
                cr=cr+R1C;
                cb=cb+R3C;
                cff=cff+R2C;
    
              }
              
              
              
    if (B =='P')
                
              { pr=pr+R1P;
                pb=pb+R3P;
                pff=pff+R2P;
                
              }
                
         if (B =='H')
            {
                hr=hr+R1H;
                hb=hb+R3H;
                hff=hff+R2H;
            }
                
          if (B=='C')
            {
                cr=cr+R1C;
                cb=cb+R3C;
                cff=cff+R2C;
    
                
              }
              
              
        if (M=='P')
                
              { pr=pr+R1P;
                pb=pb+R3P;
                pff=pff+R2P;
                
              }
                
         if (M=='H')
            {
                hr=hr+R1H;
                hb=hb+R3H;
                hff=hff+R2H;
            }
                
          if (M=='C')
            
             {   cr=cr+R1C;
                cff=cff+R2C;
                cb=cb+R3C;
    
                
              }   
              
     cR=pr+hr+cr;         
     cFF=pff+hff+cff; 
     cBL=pb+hb+cb; 
     
    if ((cR < cFF) && (cR < cBL)) 
        {
         printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n", cR);
           return 0;
        }    
        
     else if ((cFF < cR) && (cFF < cBL)) 
        {
         printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", cFF);
          
        }     
        
     
     else if ((cBL < cFF) && (cBL < cR)) 
        {
         printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", cBL);
           
        }  
     
      if (((cBL < cFF) && (cBL < cR)) || ((cFF < cR) && (cFF < cBL)))
     
        {
            
            if (T =='P' && B =='P' && M =='P')  {cR=0;
                                                     cR= pr - ((pr*10)/100.);
                                                     
                                                      if ((cR < cFF) && (cR < cBL)) 
                                                           {
                                                                printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", cR);
                                                                    
                                                                }
                                                    
            
                                                }
                                                
             if (T =='H' && B =='H' && M =='H')  {cR=0;
                                                     cR=  hr - ((hr*10)/100.);
                                                     
                                                      if ((cR < cFF) && (cR < cBL)) 
                                                           {
                                                                printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", cR);
                                                                    
                                                                }                                  
                                                
                                                 }
           if (T =='C' && B =='C' && M =='C')  {cR=0;
                                                     cR= cr - ((cr*10)/100.);
                                                     
                                                      if ((cR < cFF) && (cR < cBL)) 
                                                           {
                                                                printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", cR);
                                                                    
                                                                }                                           
                                                 }
          if (T =='P' || B =='P' || M =='P')  {cR=0;
                                                     cR=hr+cr+(pr - (pr*10)/100.);
                                                      
                                                        if ((cR < cFF) && (cR < cBL)) 
                                                           {
                                                                printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", cR);
                                                                    
                                                                }     
                                                                
          if ((T !='P' && B !='P' && M !='P') && (T =='H' || B =='H' || M =='H')) 
                                                    
                                                {cR=0;
                                                     cR=cr+(hr - (hr*10)/100.);
                                                      
                                                     
                                                      if ((cR < cFF) && (cR < cBL)) 
                                                           {
                                                                printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", cR);
                                                                    
                                                                }                                                         
                                                                
                                                }           
                                                                
          }
                                                
                                                
        }
        
	return 0;
}