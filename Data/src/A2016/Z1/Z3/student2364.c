#include <stdio.h>

int main(){
    char N;
    int C=0,B=0,S=0,V=0,P=0,UV=0;
    float Pc,Pb,Ps,Pv,Pp;
    printf("Unesite vozila: ");
    do
    {
        scanf("%c", &N);
        if(N!='C' && N!='c' && N!='B' && N!='b' && N!='S' && N!='s' && N!='V' && N!='v' && N!='P' && N!='p' && N!='K' && N!='k'){
            printf("Neispravan unos\n");
        }
        else if(N=='C' || N=='c' || N=='B' || N=='b' || N=='S' || N=='s' || N=='V' || N=='v' || N=='P' || N=='p'){
        UV++;
        }
    if(N=='C' || N=='c'){
        C++;
    }
    else if(N=='B' || N=='b'){
        B++;
    }
    else if(N=='S' || N=='s'){
        S++;
    }
    else if(N=='V' || N=='v'){
        V++;
    }
    else if(N=='P' || N=='p'){
        P++;
    }
    }
    while(N!='K' && N!='k');
    printf("Ukupno evidentirano %d vozila.\n", UV);
    if(UV!=0){
    if(C>=B && C>=S && C>=V && C>=P){
        Pc = (C*100.)/UV;
        printf("Najpopularnija boja je crna (%.2f%).", Pc);
    }
    else if(B>=S && B>=V && B>=P && B>=C){
        Pb = (B*100.)/UV;
        printf("Najpopularnija boja je bijela (%.2f%).", Pb);
    }
    else if(S>=V && S>=P && S>=C && S>=B){
        Ps = (S*100.)/UV;
        printf("Najpopularnija boja je siva (%.2f%).", Ps);
    }
    else if(V>=P && V>=C && V>=B && B>=S){
        Pv = (V*100.)/UV;
        printf("Najpopularnija boja je crvena (%.2f%).", Pv);
    }
    else if(P>=C && P>=B && P>=S && P>=V){
        Pp = (P*100.)/UV;
        printf("Najpopularnija boja je plava (%.2f%).", Pp);
    }
    }
    else{
        printf("Najpopularnija boja je crna (0.00%).");
    }
    
return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    