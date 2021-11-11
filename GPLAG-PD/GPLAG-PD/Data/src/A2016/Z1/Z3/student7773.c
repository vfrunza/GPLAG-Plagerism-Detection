#include<stdio.h>

int main()
{
    char a=0;
    float br=0,brc=0,brb=0,brs=0,brv=0,brp=0;
    float pu;

    printf("Unesite vozila: ");
   
   
   while(a!='K' && a!='k'){
        scanf("%c",&a);
        
         if(a!='C' && a!='B' && a!='S' && a!='V' && a!='P' && a!='c' && a!='b' && a!='s' && a!='v' && a!='p' && a!='k' && a!='K'){
    printf("Neispravan unos\n");
    continue;
         }
         
   if(a!='k' && a!='K') br++;
   if(a=='C' || a=='c') brc++;
   if(a=='B' || a=='b') brb++;
   if(a=='S' || a=='s') brs++;
   if(a=='V' || a=='v') brv++;
   if(a=='P' || a=='p') brp++;
    
    }
     
     
    printf("Ukupno evidentirano %g vozila.\n",br);
    
    if(brc>brb && brc>brs && brc>brv && brc>brp)  {
      
        pu=(brc/br)*100;
        printf("Najpopularnija boja je crna (%.2f%%).",pu);
        
    } 
    if(brb>brc && brb>brs && brb>brv && brb>brp) {
        pu=(brb/br)*100;
        printf("Najpopularnija boja je bijela (%.2f%%).",pu);
        
    } 
    if(brs>brc && brs>brb && brs>brv && brs>brp) {
         
        pu=(brs/br)*100;
        printf("Najpopularnija boja je siva (%.2f%%).",pu); 
        
    }
    if(brv>brc && brv>brb && brv>brs && brv>brp) {
        
        pu=(brv/br)*100;
        printf("Najpopularnija boja je crvena (%.2f%%).",pu); 
        
    }
    if(brp>brc && brp>brb && brp>brs && brp>brv) {
      
        pu=(brp/br)*100;
        printf("Najpopularnija boja je plava (%.2f%%).",pu); 
        
    }
    
    if(brc>brb && brc>brv && brc>brp && ((brc-brs)<0.00001)){
        pu=(brc/br)*100;
        printf("Najpopularnija boja je crna (%.2f%%).",pu);
    }
    
    if(brs>brc && ((brs-brv)<0.00001) && ((brs-brp)<0.00001) && brs>brb){
        pu=(brs/br)*100;
        printf("Najpopularnija boja je siva (%.2f%%).",pu);
    }

    if((br-0)<0.00000001){
        pu=(brc/0.00001)*100;
        printf("Najpopularnija boja je crna (%.2f%%).",pu);
    }
    return 0;
}
