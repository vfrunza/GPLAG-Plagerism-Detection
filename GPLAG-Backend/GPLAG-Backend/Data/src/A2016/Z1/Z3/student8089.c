#include <stdio.h>
 
int main () {
   
    
    int bc=0, bs=0, bp=0, bb=0, bv=0, max;
    
    char A;
   
    float postotak, suma;
   
    printf("Unesite vozila: ");
    do{
        scanf("%c", &A);
       
     if(A=='b'|| A=='B'|| A=='c'|| A=='C'|| A=='P'|| A=='p'|| A=='V'|| A=='v'|| A=='S'|| A=='s'|| A=='K'|| A=='k'){
           
     if(A=='C'||A=='c'){bc=bc+1;}
        else if(A=='B'|| A=='b')
            {bb=bb+1;}
        else if(A=='P'|| A=='p')
            {bp=bp+1;}
        else if(A=='V'|| A=='v')
            {bv=bv+1;}
        else if(A=='S'|| A=='s')
            {bs=bs+1;}
           
        }
       
       
        else if((A!='b') && (A!='B') && (A!='c') && (A!='C') && (A!='P') && (A!='p') && (A!='V') && (A!='v') && (A!='S') && (A!='s') && (A!='K') && (A!='k'))
        {printf("Neispravan unos\n");}
       
        }
    while((A!='K') && (A!='k'));
   
    suma=bc+bp+bb+bv+bs;
    max=bc;
   
    if(bb>max) max=bb;
    if(bs>max) max=bs;
    if(bv>max) max=bv;
    if(bp>max) max=bp;
   
    postotak=(max*100/suma);
   
    if ((suma==0)) {printf("Ukupno evidentirano 0 vozila.\n");
    printf("Najpopularnija boja je crna (0.00%).");}
    else{printf("Ukupno evidentirano %g vozila.\n", suma);
        if(bc==max){printf("Najpopularnija boja je crna (%.2f%%).\n", postotak);}
        else if(bb==max){printf("Najpopularnija boja je bijela (%.2f%%).\n", postotak);}
        else if(bs==max){printf("Najpopularnija boja je siva (%.2f%%).\n", postotak);}
        else if(bv==max){printf("Najpopularnija boja je crvena (%.2f%%).\n", postotak);}
        else if(bp==max){printf("Najpopularnija boja je plava (%.2f%%).\n", postotak);}
    }
 
   
    return 0;
}