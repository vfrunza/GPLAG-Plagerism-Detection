#include <stdio.h>
#define rp 6.80
#define rh 3.30
#define rc 5.00
#define ffp 8.00
#define ffh 3.00
#define ffc 3.90
#define bp 5.30
#define bh 5.00
#define bc 6.00
#define pp 0.10

int main () {
    char P,H,C,T,B,M,novi_red;
    float s=0,s1=0,s2=0;
    printf("Unesite jelo za Tarika: ");
    scanf("%c",&T);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c",&B);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&M);
    scanf("%c", &novi_red);
  
  
  if(T=='P'&& B=='P' && M=='P'){
        printf("Najjeftiniji je Bistro \"Lorelei\"");
        s=s+3*bp;
        printf(" (%.2f KM).",s);
        return 0;
    }else if(T=='H' && B=='H' && M=='H'){
        printf("Najjeftiniji je Fast-food \"Trovac\"");
        s=s+3*ffh;
        s1=s-s*pp;
        printf(" (%.2f KM).",s);
        printf("\nSa popustom bi Restoran bio jeftiniji");
        printf(" (%.2f KM).", s1);
        return 0;
            
    } else if(T=='C' && B=='C' && M=='C'){
        printf("Najjeftiniji je Fast-food \"Trovac\"");
        s=s+3*ffc;
        printf(" (%.2f KM).",s);
        return 0;
        
    } else if((T=='P'&&B=='H'&&M=='C') || (T=='P'&&B=='C'&&M=='H') || (T=='H'&&B=='C'&&M=='P') || (T=='H'&&B=='P'&&M=='C') || (T=='C'&&B=='P'&&M=='H') || (T=='C'&&B=='H'&&M=='P')){
        printf("Najjeftiniji je Fast-food \"Trovac\"");
        s=s+(ffp+ffh+ffc);
        s2=rp*pp;
        s1=s-s2;
        printf(" (%.2f KM).",s);
        printf("\nSa popustom bi Restoran bio jeftiniji");
        printf(" (%.2f KM).",s1);
        return 0;
    
    }else if((T=='P'&&B=='P' &&M=='H') || (T=='P'&&M=='P'&&B=='H') || (T=='H'&&B=='P'&&M=='P')){
        printf("Najjeftiniji je Bistro \"Lorelei\"");
        s=s+2*bp+bh;
        s2=2*rp*pp;
        s1=s-s2;
        printf(" (%.2f KM).",s);
        printf("\nSa popustom bi Restoran bio jeftiniji");
        printf(" (%.2f KM).",s1);
        return 0;
    
    }else if((T=='P'&&B=='P'&&M=='C') || (T=='P'&&M=='P'&&B=='C') || (M=='P'&&B=='P'&&T=='C')){
        printf("Najjeftiniji je Bistro \"Lorelei\"");
        s=s+2*bp+bc;
        printf(" (%.2f KM).",s);
        return 0;
        
    }else if((T=='H'&&B=='H'&&M=='P') || (T=='H'&&M=='H'&&B=='P') || (T=='P'&&B=='H'&&M=='H')){
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\"");
        s=s+2*rh+rp;
        printf(" (%.2f KM).",s);
        return 0;
    
    }else if((T=='H'&&B=='H'&&M=='C') || (T=='H'&&M=='H'&&B=='C') || (T=='C'&&B=='H'&&M=='H')){
        printf("Najjeftiniji je Fast-food \"Trovac\"");
        s=s+2*ffh+ffc;
        printf(" (%.2f KM).",s);
        return 0;
        
    }else if((T=='C'&&B=='C'&&M=='H') || (T=='C'&&M=='C'&&B=='H') || (T=='H'&&M=='C'&&B=='C')){
        printf("Najjeftiniji je Fast-food \"Trovac\"");
        s=s+2*ffc+ffh;
        printf(" (%.2f KM).",s);
        return 0;
        
    }else if((T=='C'&&B=='C'&&M=='P') || (T=='C'&&M=='C'&&B=='P') || (T=='P'&&M=='C'&&B=='C')){
        printf("Najjeftiniji je Fast-food \"Trovac\"");
        s=s+2*ffc+ffp;
        printf(" (%.2f KM).", s);
        return 0;
    }
    return 0;
    
    
    
}