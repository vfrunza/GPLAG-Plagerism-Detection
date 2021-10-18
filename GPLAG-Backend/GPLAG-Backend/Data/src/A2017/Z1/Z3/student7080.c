#include <stdio.h>

int main() {
    int c;
    int sC=0,sP=0,sB=0,sS=0,sV=0,EVIDENTIRANI;
    float procenatp,procenatb,procenatv,procenats,procenatc;
    printf("Unesite vozila: ");
    
    do
    {
       
        c=getchar();
       
         if(c=='C' || c=='c')
 {
     sC=sC+1;
 }
 else  if(c=='P' || c=='p')
 {
     sP=sP+1;
 }
 else if(c=='B'||c=='b')
 {
     sB=sB+1;
 }
 else if(c=='S'||c=='s')
 {
     sS=sS+1;
 }
 else if(c=='V'||c=='v')
 {
     sV=sV+1;
 }
  if( c!='C' && c!='c' && c!='s' && c!='S' && c!='p' && c!= 'P' && c!='v' && c!='V' && c!='b' && c!='B' && c!='K' && c!='k' )
{
    printf("Neispravan unos\n");
}
   
} while(c!='k' && c!='K');




     

 


  if(c=='k' || c=='K')
 {
     EVIDENTIRANI=sP+sC+sV+sS+sB;
     procenatp=((float)sP*100/EVIDENTIRANI);
     procenatb=((float)sB*100/EVIDENTIRANI);
     procenats=((float)sS*100/EVIDENTIRANI);
     procenatv=((float)sV*100/EVIDENTIRANI);
     procenatc=((float)sC*100/EVIDENTIRANI);
     printf("Ukupno evidentirano %d vozila.\n",EVIDENTIRANI);
     if(EVIDENTIRANI!=0)
     {
     
     if(  (sC>=sP) && (sC>=sB) && (sC>=sS) && (sC>=sV) )
     {
    
         printf("Najpopularnija boja je crna (%.2f%%).",procenatc);
     }
            else if((sB>=sC) && (sB>=sP) && (sB>=sS) && (sB>=sV))
             {
         
         printf("Najpopularnija boja je bijela (%.2f%%).",procenatb);
             }
               else if((sS>=sC) && (sS>=sB) && (sS>=sP) && (sS>=sV))
               {
         
         printf("Najpopularnija boja je siva (%.2f%%).",procenats);
             }
            
             
               else if((sV>sC) && (sV>sB) && (sV>sS) && (sV>sP))
               {
        
         printf("Najpopularnija boja je crvena (%.2f%%).",procenatv);
             }
             
     else if(sP>=sC && sP>=sB && sP>=sS && sP>=sV)
             {
         
         printf("Najpopularnija boja je plava (%.2f%%).",procenatp);
             }
    
 }
 
 else {
     printf("Najpopularnija boja je crna (0.00%%).");
 }
 }
 
 
 
 return 0;
}

     
     
 
    
    

	
	
	
	
	
	
	
	
	

