#include <stdio.h>
#define rp 6.80
#define rh 3.30
#define rc 5.00
#define fp 8.00
#define fh 3.00
#define fc 3.90
#define bp 5.30
#define bh 5.00
#define bc 6.00

int main() {
//	printf("Zadaća 1, Zadatak 1");
    char t, b, m, enter;
    double najniza1, cr, cf, cb, cr_pop, najniza2, n;
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &t);
    scanf("%c", &enter);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &b);
    scanf("%c", &enter);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &m);
    scanf("%c", &enter);
    
    if(t=='P' && b=='P' && m=='P'){ cr=3*rp; cf=3*fp; cb=3*bp; n=rp;}
    else if(t=='H' && b=='H' && m=='H'){ cr=3*rh; cf=3*fh; cb=3*bh; n=rh;}
    else if(t=='C' && b=='C' && m=='C'){ cr=3*rc; cf=3*fc; cb=3*bc; n=rc;}
    else if((t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P')){ cr=2*rp+rh; cf=2*fp+fh; cb=2*bp+bh; n=rp;}
    else if((t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P')){ cr=2*rp+rc; cf=2*fp+fc; cb=2*bp+bc; n=rp;}
    else if((t=='H' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='H')){ cr=2*rh+rp; cf=2*fh+fp; cb=2*bh+bp; n=rp;}
    else if((t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H')){ cr=2*rh+rc; cf=2*fh+fc; cb=2*bh+bc; n=rh;}
    else if((t=='C' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='C')){ cr=2*rc+rp; cf=2*fc+fp; cb=2*bc+bp; n=rp;}
    else if((t=='C' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='C')){ cr=2*rc+rh; cf=2*fc+fh; cb=2*bc+bh; n=rh;}
    else if((t=='P' && b=='H' && m=='C') || (t=='H' && b=='P' && m=='C') || (t=='C' && b=='P' && m=='H') || (t=='H' && b=='C' && m=='P') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='C' && m=='H')){ cr=rc+rp+rh; cf=fc+fp+fh; cb=bc+bp+bh; n=rp;}
    
    if(cr<=cf && cr<=cb) najniza1=cr;
    if(cf<=cr && cf<=cb) najniza1=cf;
    if(cb<=cr && cr<=cf) najniza1=cb;
//    printf("\nNAJNIZA %.2f\n", najniza1);
    
//    if(cr>=cf && cr>=cb) najvisa=cr;
//    if(cf>=cr && cf>=cb) najvisa=cf;
//    if(cb>=cr && cr>=cf) najvisa=cb;
    
    if(najniza1==cr){ printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", cr); return 0;}
//    cr_pop=cr-n+(n-((n*10)/100));

    if(t=='P' && b=='P' && m=='P') cr_pop=3*(rp-((rp*10)/100));
    else if(t=='H' && b=='H' && m=='H') cr_pop=3*(rh-((rh*10)/100));
    else if(t=='C' && b=='C' && m=='C') cr_pop=3*(rc-((rc*10)/100));
    else if((t=='P' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='P')) cr_pop=2*(rp-((rp*10)/100))+rh;
    else if((t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P')) cr_pop=2*(rp-((rp*10)/100))+rc;
    else if((t=='H' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='H')) cr_pop=2*rh+(rp-((rp*10)/100));
    else if((t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H')) cr_pop=2*(rh-((rh*10)/100))+rc;
    else if((t=='C' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='C')) cr_pop=2*(rc-((rc*10)/100))+rp;
    else if((t=='C' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='C')) cr_pop=2*(rc-((rc*10)/100))+rh;
    else if((t=='P' && b=='H' && m=='C') || (t=='H' && b=='P' && m=='C') || (t=='C' && b=='P' && m=='H') || (t=='H' && b=='C' && m=='P') || (t=='C' && b=='H' && m=='P') || (t=='P' && b=='C' && m=='H')) cr_pop=rc+(rp-((rp*10)/100))+rh;
    
//    printf("\nRES SA POP %.2f\n", cr_pop);
    
    if(cr_pop<cf && cr_pop<cb) najniza2=cr_pop;
    else if(cf<=cr_pop && cf<=cb){ najniza2=cf; printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", cf); return 0;}
    else if(cb<=cr_pop && cr_pop<=cf){ najniza2=cb; printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", cb); return 0;}
    
//    printf("\nNAJNIZA  OPET %.2f\n", najniza2);
    
    if(najniza1==cf) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", najniza1);
    if(najniza1==cb) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", najniza1);
    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", najniza2);
    
    
    
	return 0;
}
