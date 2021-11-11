#include <stdio.h>
#include <math.h>
/* c crna   67(+32) 
   b bijela 68(+32)
   s siva   83(+32)
   v crvena 86(+32) 
   p plava  80(+32) */
int main(){
    char x;                         /*x-boja koju korisnik unese*/
    int C,B,S,V,P,UKUPNO=0,max;     /*UKUPNO-broji koliko tacnih unosa smo imali*/
    int pC,pB,pS,pV,pP,pozicijaMax;
    double procenat;
    C=B=S=V=P=0;                    /*Oznacava koliko se puta odredjena boja pojavljuje*/
    pC=pB=pS=pV=pP=0;               /*Pozicija na kojoj se po prvi put pojavi neka boja*/
    
    printf("Unesite vozila: ");      
    scanf("%c", &x);
    
    while((x != 'K') && (x != 'k')){
      if((x=='C') || (x=='c')) { UKUPNO+=1; C+=1; if(pC==0) pC=UKUPNO;}
      else if((x=='B') || (x=='b')) { UKUPNO+=1; B+=1; if(pB==0) pB=UKUPNO;}    
      else if((x=='S') || (x=='s')) { UKUPNO+=1; S+=1; if(pS==0) pS=UKUPNO;}
      else if((x=='V') || (x=='v')) { UKUPNO+=1; V+=1; if(pV==0) pV=UKUPNO;}
      else if((x=='P') || (x=='p')) { UKUPNO+=1; P+=1; if(pP==0) pP=UKUPNO;}
      else if((x=='K') || (x=='k')) break;
      else if (((int)x==8) || ((int)x==13)) printf("Neispravan unos\n");
      else printf("Neispravan unos\n");
      scanf("%c", &x);
    }
    
    max=C;                                                /*postavljamo crnu kao boju koja se najvise pojavkjivala */
    pozicijaMax=pC;                                       /*pozicija prve pojave trenutnog najveceg broja je pozicija prve pojave crne boje*/
    
    if(max==B && (pozicijaMax>pB)) max=B, pozicijaMax=pB; /* trazi najveci broj pojavljivanja odedjene boje */
    if(max<B) max=B;                                      /* ako je broj pojavljivanja kod 2 boje isti uzima onaj sa MANJOM pozicijom*/
    if(max==S && (pozicijaMax>pS)) max=S, pozicijaMax=pS;
    if(max<S) max=S;
    if(max==V && (pozicijaMax>pV)) max=V, pozicijaMax=pV;
    if(max<V) max=V;
    if(max==P && (pozicijaMax>pP)) max=P, pozicijaMax=pP;
    if(max<P) max=P;
    
    printf("Ukupno evidentirano %d vozila.\n", UKUPNO);
    procenat=(double)max/UKUPNO*100;
    if (UKUPNO==0) procenat=0;
    
    if (max==C) printf("Najpopularnija boja je crna (%.2f%%).", procenat);
    else if (max==B) printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
    else if (max==S) printf("Najpopularnija boja je siva (%.2f%%)." , procenat);
    else if (max==V) printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
    else if (max==P) printf("Najpopularnija boja je plava (%.2f%%).", procenat);
    
    return 0;
}