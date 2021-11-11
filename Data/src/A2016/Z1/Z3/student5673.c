#include <stdio.h>
#include <stdlib.h>

int main() {
    /* ----- brojanje ----- */
    printf("Unesite vozila: ");
    char vozila;
    int brojac_c=0, brojac_b=0, brojac_s=0, brojac_v=0, brojac_p=0;
    while(1){
        scanf("%c", &vozila);
        if(vozila == 'C' || vozila == 'c'){
            brojac_c++;
        }
        else if(vozila == 'B' || vozila == 'b'){
            brojac_b++;
        }
        else if(vozila == 'S' || vozila == 's'){
            brojac_s++;            
        }
        else if(vozila == 'V' || vozila == 'v'){
            brojac_v++;
        }
        else if(vozila == 'P' || vozila == 'p'){
            brojac_p++;
        }
        else if(vozila == 'K' || vozila == 'k'){
            break;
        }
        else{
            printf("Neispravan unos\n");
        }
    }
    
    /* ---- ukupno vozila ----- */
    float ukupno;
    ukupno=brojac_p+brojac_v+brojac_s+brojac_b+brojac_c;
    int tmp=ukupno;
    printf("Ukupno evidentirano %d vozila.\n", tmp);
    
    /* ----- procenti ----- */
    float procenat_p, procenat_v, procenat_s, procenat_b, procenat_c;
    procenat_p = (brojac_p/ukupno) * 100;
    procenat_v = (brojac_v/ukupno) * 100;
    procenat_s = (brojac_s/ukupno) * 100;
    procenat_b = (brojac_b/ukupno) * 100;
    procenat_c = (brojac_c/ukupno) * 100;
    
    /* ----- naci maximalni ----- */
    int max_el=brojac_c;
    float crna_nula = 0;
    if(brojac_b>max_el){
        max_el=brojac_b;
    }
    if(brojac_s>max_el){
        max_el=brojac_s;
    }
    if(brojac_v>max_el){
        max_el=brojac_v;
    }
    if(brojac_p>max_el){
        max_el=brojac_p;
    }
    if(max_el==brojac_c){
        printf("Najpopularnija boja je crna (%.2f%%).", procenat_c);
        return 0;
    }
    else if(max_el==brojac_b){
        printf("Najpopularnija boja je bijela (%.2f%%).", procenat_b);
        return 0;
    }
    else if(max_el==brojac_s){
        printf("Najpopularnija boja je siva (%.2f%%).", procenat_s);
        return 0;
    }
    else if(max_el==brojac_v){
        printf("Najpopularnija boja je crvena (%.2f%%).", procenat_v);
        return 0;
    }
    else if(max_el==brojac_p){
        printf("Najpopularnija boja je plava (%.2f%%).", procenat_p);
        return 0;
    }
    else{
        printf("Najpopularnija boja je crna (%.2f%%).", procenat_c);
        return 0;        
    }
    
	return 0;
}
