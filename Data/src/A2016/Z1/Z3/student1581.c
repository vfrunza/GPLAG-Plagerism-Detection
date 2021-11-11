#include <stdio.h>

int main() {
/*	printf("Zadaća 1, Zadatak 3");*/

int ic=0, ib=0, is=0, iv=0, ip=0, i=0;
float c,b,s,v,p;
char n;

printf("Unesite vozila: ");

do
{

    scanf("%c", &n);
    
    if(n=='k' || n=='K') break;  
        
    else if(n=='C' || n=='c') {i++; ic++;}
    else if(n=='B' || n=='b') {i++; ib++;}
    else if(n=='S' || n=='s') {i++; is++;}
    else if(n=='V' || n=='v') {i++; iv++;}
    else if(n=='P' || n=='p') {i++; ip++;}
    
    else if(n!='C' && n!='c' && n!='B' && n!='b' && n!='S' && n!='V' && n!='v' && n!='P' && n!='p' && n!='K' && n!='k')
        {printf("Neispravan unos\n");}
}

 while(n!='k');
 
 printf("Ukupno evidentirano %d vozila.\n",i);
 
 if(i!=0)
 {
     c=(float)ic*100/i;
     b=(float)ib*100/i;
     s=(float)is*100/i;
     v=(float)iv*100/i;
     p=(float)ip*100/i;
     
     if(ic>=ib && ic>=is && ic>=iv && ic>=ip) printf("Najpopularnija boja je crna (%.2f%%).",c);
   else if(ib>=is && ib>=iv && ib>=ip && ib>=ic) printf("Najpopularnija boja je bijela (%.2f%%).",b);
   else if(is>=iv && is>=ip && is>=ib && is>=ic) printf("Najpopularnija boja je siva (%.2f%%).",s);
   else if(iv>=ip && iv>=is && iv>=ib && iv>=ic) printf("Najpopularnija boja je crvena (%.2f%%).",v);
   else if(ip>=is && ip>=iv && ip>=ib && ip>=ic) printf("Najpopularnija boja je plava (%.2f%%).",p);
     
 }
 
 if(i==0)
 {
    
     if(ic>=ib && ic>=is && ic>=iv && ic>=ip) printf("Najpopularnija boja je crna (0.00%%).",c);
   else if(ib>=is && ib>=iv && ib>=ip && ib>=ic) printf("Najpopularnija boja je bijela (0.00%%).",b);
   else if(is>=iv && is>=ip && is>=ib && is>=ic) printf("Najpopularnija boja je siva (0.00%%).",s);
   else if(iv>=ip && iv>=is && iv>=ib && iv>=ic) printf("Najpopularnija boja je crvena (0.00%%).",v);
   else if(ip>=is && ip>=iv && ip>=ib && ip>=ic) printf("Najpopularnija boja je plava (0.00%%).",p);
     
 }
 
	return 0;
}
