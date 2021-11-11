#include <stdio.h>

int main() {
    char znak;
    float  pC, pB, pS, pP, pV, pO;
    int brojac=0, C=0, B=0, S=0, P=0, V=0;
    printf("Unesite vozila: ");
    do{
        scanf("%c", &znak);
        if(znak==67||znak==99){ C++; brojac++;}
        else if(znak==66||znak==98){brojac++; B++;}
        else if(znak==83||znak==115){brojac++; S++;}
        else if(znak==80||znak==112){brojac++; P++;}
        else if(znak==86||znak==118){brojac++; V++;}
        else if(znak==75||znak==107) break;
        else printf("Neispravan unos\n");
    }
    while(znak!=75&&znak!=107);
    printf("Ukupno evidentirano %d vozila.\n", brojac);
    if((C+B+S+P+V)!=0){
        pC=C*100./(C+B+S+P+V);
        pB=B*100./(C+B+S+P+V);
        pS=S*100./(C+B+S+P+V);
        pP=P*100./(C+B+S+P+V);
        pV=V*100./(C+B+S+P+V);
      if(C-B>=0&&C-S>=0&&C-P>=0&&C-V>=0) printf("Najpopularnija boja je crna (%.2f%%).", pC);
    else if(B-C>=0&&B-S>=0&&B-P>=0&&B-V>=0) printf("Najpopularnija boja je bijela (%.2f%%).", pB);
	else if(S-B>=0&&S-C>=0&&S-P>=0&&S-V>=0) printf("Najpopularnija boja je siva (%.2f%%).", pS);
	else if(P-C>=0&&P-B>=0&&P-S>=0&&P-V>=0) printf("Najpopularnija boja je plava (%.2f%%).", pP);
	else printf("Najpopularnija boja je crvena (%.2f%%).", pV);
    }
    else{ pO=0.00;
        printf("Najpopularnija boja je crna (%.2f%%).", pO);
    }
	return 0;
}
