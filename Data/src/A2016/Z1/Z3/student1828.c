#include <stdio.h>
#include <stdlib.h>

int main() {
    //unos chara koji sam morao googlat prvo jer na tutu nisam mogao skontat kako se koristi// 
    int ua=0,cr=0,b=0,s=0,v=0,p=0;
    char c='0';
    float c1,b1,s1,v1,p1;
    printf ("Unesite vozila: ");
    while (c!='k' && c!='K') {
        scanf ("%c", &c); 
    if (c!='c' && c!='C' && c!='b' && c!='B' && c!='s' && c!='S' && c!='v' && c!='V' && c!='p' && c!='P' && c!='k' && c!='K' ){
        printf ("Neispravan unos\n");} 
    else {    //brojaci za broj kola i broj boja// 
  if ((c=='c') || (c=='C') ) {
    cr++;
    ua++; }
 else if ((c=='b') || (c=='B')){ b++;
        ua++;}
    if ((c=='s') || (c=='S')){
            ua++;
            s++;
        }
    if ((c=='v') || (c=='V')){
            v++;
            ua++;
        }
 if ((c=='p') || (c=='P')){
            ua++;
            p++;
        } } }  
        printf("Ukupno evidentirano %d vozila.\n", ua);
        if (ua==0) {
            printf ("Najpopularnija boja je crna (0.00%).");
        } 
        else {
    //racunanje postotaka i posto nisam znao pitao sam pa su mi rekli da (float) stavim jer ima intanih elemenata i floatanih i da je i meni i programu bolje skontat lakse je tako// 
c1=((float)cr/(float)ua);
b1=((float)b/(float)ua);
s1=((float)s/(float)ua);
v1=((float)v/(float)ua);
p1=((float)p/(float)ua);

if (c1>=s1 && c1>=v1 && c1>=p1 && c1>=b1){
    printf ("Najpopularnija boja je crna (%.2f%).", c1*100);}
    if (b1>=s1 && b1>=v1 && b1>=p1 && b1>c1){
        printf ("Najpopularnija boja je bijela (%.2f%).", b1*100);}
        if (s1>c1 && s1>b1 && s1>=v1 && s1>=p1){
            printf ("Najpopularnija boja je siva (%.2f%). ", s1*100);}
            if (v1>c1 && v1>b1 && v1>s1 && s1>= p1){
                printf ("Najpopularnija boja je crvena (%.2f%).", v1*100);}
                if (p1>c1 && p1>b1 && p1>v1 && p1>s1){ 
                    printf ("Najpopularnija boja je plava (%.2f%).", p1*100); }
        }
        return 0;}


    
        
    

