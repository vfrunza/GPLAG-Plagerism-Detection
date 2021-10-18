#include <stdio.h>
int main() {
	
    char boja;
    int  max=0, br=0, brC=0, brB=0, brS=0, brV=0, brP=0;
    printf("Unesite vozila: ");
    do{
        scanf("%c", &boja);
            if(boja=='C' || boja=='c'){
                brC++;
                br++;
            }
            
            else if(boja=='B' || boja=='b'){
                brB++;
                br++;
            }
            else if(boja=='S' || boja=='s'){
                brS++;
                br++;
            }
            else if(boja=='V' || boja=='v'){
                brV++;
                br++;
            }
            else if(boja=='P' || boja=='p'){
                brP++;
                br++;
            }
            else if(boja=='K' || boja=='k'){
                break;}
        else{
            printf("Neispravan unos\n");
        }
        
        
    }while(1==1);
    max=br/5;
    if (brC>max && brC>=brB && brC>=brS && brC>=brV && brC>=brP) {max=brC;}
    else if (brB>max && brB>brC && brB>=brS && brB>=brV && brB>=brP) {max=brB;}
    else if (brS>max && brS>brC && brS>brB && brS>=brV && brS>=brP) {max=brS;}
    else if (brV>max && brV>brC && brV>brB && brV>brS && brV>=brP) {max=brV;}
    else  {max=brP;}
    printf("Ukupno evidentirano %d vozila.\n", br);
    if(brC==max){printf("Najpopularnija boja je crna ");}
    else if(brB==max){printf("Najpopularnija boja je bijela ");}
    else if(brS==max){printf("Najpopularnija boja je siva ");}
    else if(brV==max){printf("Najpopularnija boja je crvena ");}
    else if(brP==max){printf("Najpopularnija boja je plava ");}
    double brojac, procenat;
    brojac=br;
    procenat=(max*100)/brojac;
    if(br==0){printf("(0.00%).");}
    else{printf("(%.2lf%).", procenat);}
	return 0;
}
