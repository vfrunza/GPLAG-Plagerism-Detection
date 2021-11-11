#include <stdio.h>

int main(){
    char x;
    int C=0, B=0, S=0, V=0, P=0, br=0, max=-1 ;
    printf("Unesite vozila: ");
    do{
        scanf("%c", &x);
        if(x=='k' || x=='K') continue;
        else if(x=='c' || x=='C'){
            C++;
            br++;
        }else if(x=='B' || x=='b'){
            B++;
            br++;
        }else if(x=='S' || x=='s'){
            S++;
            br++;
        }else if(x=='v' || x=='V'){
            V++;
            br++;
        }else if(x=='P' || x=='p'){
            P++;
            br++;
        }else printf("Neispravan unos\n");
    }while(x!='k' && x!='K');
    if(P>max) max=P;
    if(V>max) max=V;
    if(S>max) max=S;
    if(B>max) max=B;
    if(C>max) max=C;
    printf("Ukupno evidentirano %d vozila.\n",br);
    if (br==0) printf("Najpopularnija boja je crna (%.2f%%).", 1.*br);
    else if(max==C) printf("Najpopularnija boja je crna (%.2f%%).", 100.*max/br);
    else if(max==B) printf("Najpopularnija boja je bijela (%.2f%%).", 100.*max/br);
    else if(max==S) printf("Najpopularnija boja je siva (%.2f%%).", 100.*max/br);
    else if(max==V) printf("Najpopularnija boja je crvena (%.2f%%).", 100.*max/br);
    else if(max==P) printf("Najpopularnija boja je plava (%.2f%%).", 100.*max/br);
    return 0;
}