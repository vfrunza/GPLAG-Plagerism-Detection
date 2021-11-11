#include <stdio.h>
#define delta 0.001

int main() {
    float brc=0,brb=0,brs=0,brv=0,brp=0,c,b,s,v,p;
     int prvi=0,br=0;
     char boja='a';
    
    
    printf("Unesite vozila: ");
    
    
    while(boja!='k' && boja!='K') {
      
        scanf("%c", &boja);
        
        if(boja=='c' || boja=='C') brc++;
        else if(boja=='b' || boja=='B') brb++;
        else if(boja=='s' || boja=='S') brs++;
        else if(boja=='v' || boja=='V') brv++;
        else if(boja=='p' || boja=='P') brp++;
        
        if(brc==1 && brb==0 && brs==0 && brv==0 && brp==0) prvi=1;
        else if(brb==1 && brc==0 && brs==0 && brv==0 && brp==0) prvi=2;
        else if(brs==1 && brb==0 && brc==0 && brv==0 && brp==0) prvi=3;
        else if(brv==1 && brb==0 && brs==0 && brc==0 && brp==0) prvi=4;
        else if(brp==1 && brb==0 && brs==0 && brv==0 && brc==0) prvi=5;
        
         if(boja!='c' && boja!='C' && boja!='b' && boja!='B' && boja!='s' && boja!='S' 
         && boja!='v' && boja!='V' && boja!='p' && boja!='P' && boja!='k' && boja!='K') 
    printf ("Neispravan unos\n"); 
      }
   
    
    br=brc+brb+brs+brv+brp;
    
    printf("Ukupno evidentirano %d vozila.\n",br);
   
    
    c=(brc/br)*100;
    b=(brb/br)*100;
    s=(brs/br)*100;
    v=(brv/br)*100;
    p=(brp/br)*100;
    
    
    if(br==0) printf("Najpopularnija boja je crna (0.00%%).");
    
    
     if((c-b>delta) && (c-s>delta) && (c-v>delta) && (c-p>delta)) printf("Najpopularnija boja je crna (%.2f%%).",c);
    else if ((b-c>delta) && (b-s>delta) && (b-v>delta) && (b-p>delta)) printf("Najpopularnija boja je bijela (%.2f%%).",b);
    else if ((s-c>delta) && (s-b>delta) && (s-v>delta) && (s-p>delta)) printf("Najpopularnija boja je siva (%.2f%%).",s);
    else if ((v-c>delta) && (v-b>delta) && (v-s>delta) && (v-p>delta)) printf("Najpopularnija boja je crvena (%.2f%%).",v);
    else if ((p-c>delta) && (p-s>delta) && (p-v>delta) && (p-b>delta)) printf("Najpopularnija boja je plava (%.2f%%).",p);
    else { 
        if(prvi==1) printf("Najpopularnija boja je crna (%.2f%%).",c);
        else if(prvi==2) printf("Najpopularnija boja je bijela (%.2f%%).",b);
        else if(prvi==3) printf("Najpopularnija boja je siva (%.2f%%).",s);
        else if(prvi==3) printf("Najpopularnija boja je crvena (%.2f%%).",v);
        else if(prvi==5) printf("Najpopularnija boja je plava (%.2f%%).",p); }
    
   
    
    
    
	return 0;
}
