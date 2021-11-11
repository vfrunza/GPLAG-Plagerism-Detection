#include <stdio.h>

int main() {
    
    int broj=0, c=0, b=0, s=0, v=0, p=0, best, isti=0, rc=0, rb=1, rs=2, rv=3, rp=4, najpopularniji;
    double procenat;
    char cha='s';
    printf("Unesite vozila: ");
    
    do {
       
        scanf("%c", &cha);
        
        if((cha!='k') && (cha!='K') && (cha!='c') && (cha!='C') && (cha!='b') && (cha!='B') && (cha!='v') && (cha!='V') && (cha!='s') && (cha!='S') && (cha!='p') && (cha!='P')) {
        printf("Neispravan unos\n");
        continue; }
        if((cha=='k') || (cha=='K')) break;
        else {
        broj++;
        if((cha=='c') || (cha=='C'))  c++; 
        else if((cha=='p') || (cha=='P')) p++; 
        else if((cha=='v') || (cha=='V')) v++;
        else if((cha=='b') || (cha=='B')) b++; 
        else s++; 
        
        } } while((cha!='k') && (cha!='K')) ;
        best=c; najpopularniji=rc;
        if(p>best) { best=p; najpopularniji=rp; }
        if(v>best) { best=v; najpopularniji=rv; }
        if(b>best) { best=b; najpopularniji=rb; }
        if(s>best) { best=s; najpopularniji=rs; }
        
        if(best==c) { isti++; if(rc<najpopularniji) najpopularniji=rc; }
        if(best==p) { isti++; if(rp<najpopularniji) najpopularniji=rp; }
        if(best==v) { isti++; if(rv<najpopularniji) najpopularniji=rv; }
        if(best==b) { isti++; if(rb<najpopularniji) najpopularniji=rb; }
        if(best==s) { isti++; if(rs<najpopularniji) najpopularniji=rs; }
        
        
    if(broj>0) procenat=((double)best/broj)*100;
    else procenat=0;
    
    if(isti==1) {

    if(best==c) {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je crna (%.2f%%).", procenat);
    } 
    
    else if(best==b) {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
    } 
    
    else if(best==s) {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je siva (%.2f%%).", procenat);
    } 
    
    else if(best==v) {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
    } 
    
    else {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je plava (%.2f%%).", procenat);
    } 
    }
    else {
        
        if(najpopularniji==rc) {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je crna (%.2f%%).", procenat);
    } 
    
    else if(najpopularniji==rb) {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
    } 
    
    else if(najpopularniji==rs) {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je siva (%.2f%%).", procenat);
    } 
    
    else if(najpopularniji==rv) {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
    } 
    
    else {
    printf("Ukupno evidentirano %i vozila.\n", broj);
    printf("Najpopularnija boja je plava (%.2f%%).", procenat);
    } 
        
    }
    return 0;
    
}


