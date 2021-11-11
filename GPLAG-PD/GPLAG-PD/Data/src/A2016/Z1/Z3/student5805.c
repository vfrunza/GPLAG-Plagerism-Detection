#include <stdio.h>
int main(){
    char n;
    int brojac_c=0,brojac_b=0,brojac_s=0,brojac_v=0,brojac_p=0,uk,max;
    double rez;
    printf("Unesite vozila: ");
    do{ 
        scanf("%c",&n);
        if(n=='c'||n=='C')
            brojac_c++;
        else if(n=='b'||n=='B')
            brojac_b++;
        else if(n=='s'||n=='S')
            brojac_s++;
        else if(n=='v'||n=='V')
            brojac_v++;
        else if(n=='p'||n=='P')
           brojac_p++;
        else if(n=='k'||n=='K');
        else printf("Neispravan unos\n");
    }
        while(n!='k' && n!='K');
        uk=brojac_c+brojac_b+brojac_s+brojac_v+brojac_p;
        if(uk==0){
            printf("Ukupno evidentirano 0 vozila.\n");
            rez=(float)uk*100;
            printf("Najpopularnija boja je crna (%.2f%%).",rez);
        }
        else if(brojac_c>=brojac_b && brojac_c>=brojac_s && brojac_c>=brojac_v && brojac_c>=brojac_p){
            max=brojac_c;
            printf("Ukupno evidentirano %d vozila.\n",uk);
            if(max==brojac_p){
                rez=(float)brojac_c/uk*100; 
                printf("Najpopularnija boja je crna (%.2f%%).",rez);
            }
            else if(max==brojac_b){
                rez=(float)brojac_c/uk*100;
                printf("Najpopularnija boja je crna (%.2f%%).",rez);
            }
            else if(max==brojac_s){
                rez=(float)brojac_c/uk*100;
                printf("Najpopularnija boja je crna (%.2f%%).",rez);
            }
            else if(max==brojac_v){
                rez=(float)brojac_c/uk*100;
                printf("Najpopularnija boja je crna (%.2f%%).",rez);
            }
            else{
                rez=(float)brojac_c/uk*100; 
                printf("Najpopularnija boja je crna (%.2f%%).",rez);
            }
        }
        else if(brojac_b>=brojac_c && brojac_b>=brojac_s && brojac_b>=brojac_v && brojac_b>=brojac_p){
            printf("Ukupno evidentirano %d vozila.\n",uk);
            max=brojac_b;
            if(max==brojac_c){
                rez=(float)brojac_c/uk*100; 
                printf("Najpopularnija boja je crna (%.2f%%).",rez);
            }
            else if(max==brojac_p){
                rez=(float)brojac_b/uk*100;
                printf("Najpopularnija boja je bijela (%.2f%%).",rez);
            }
            else if(max==brojac_s){
                rez=(float)brojac_b/uk*100;
                printf("Najpopularnija boja je bijela (%.2f%%).",rez);
            }
            else if(max==brojac_v){
                rez=(float)brojac_b/uk*100;
                printf("Najpopularnija boja je bijela (%.2f%%).",rez);
            }
            else{
                rez=(float)brojac_b/uk*100; 
                printf("Najpopularnija boja je bijela (%.2f%%).",rez);
            }
        }
        else if(brojac_s>=brojac_c && brojac_s>=brojac_b && brojac_s>=brojac_v && brojac_s>=brojac_p){
            max=brojac_s;
            printf("Ukupno evidentirano %d vozila.\n",uk);
            if(max==brojac_c){
                rez=(float)brojac_c/uk*100; 
                printf("Najpopularnija boja je crna (%.2f%%).",rez);
            }
            else if(max==brojac_b){
                rez=(float)brojac_b/uk*100;
                printf("Najpopularnija boja je bijela (%.2f%%).",rez);
            }
            else if(max==brojac_p){
                rez=(float)brojac_s/uk*100;
                printf("Najpopularnija boja je siva (%.2f%%).",rez);
            }
            else if(max==brojac_v){
                rez=(float)brojac_s/uk*100;
                printf("Najpopularnija boja je siva (%.2f%%).",rez);
            }
            else{
                rez=(float)brojac_s/uk*100; 
                printf("Najpopularnija boja je siva (%.2f%%).",rez);
            }
        }  
        else if(brojac_v>=brojac_c && brojac_v>=brojac_s && brojac_v>=brojac_b && brojac_v>=brojac_p){
            max=brojac_v;
            printf("Ukupno evidentirano %d vozila.\n",uk);
            if(max==brojac_c){
                rez=(float)brojac_c/uk*100; 
                printf("Najpopularnija boja je crna (%.2f%%).",rez);
            }
            else if(max==brojac_b){
                rez=(float)brojac_b/uk*100;
                printf("Najpopularnija boja je bijela (%.2f%%).",rez);
            }
            else if(max==brojac_s){
                rez=(float)brojac_s/uk*100;
                printf("Najpopularnija boja je siva (%.2f%%).",rez);
            }
            else if(max==brojac_p){
                rez=(float)brojac_v/uk*100;
                printf("Najpopularnija boja je crvena (%.2f%%).",rez);
            }
            else{
                rez=(float)brojac_v/uk*100; 
                printf("Najpopularnija boja je crvena (%.2f%%).",rez);
            }
        }
        else if(brojac_p>=brojac_c && brojac_p>=brojac_s && brojac_p>=brojac_v && brojac_p>=brojac_b){
            max=brojac_p;
            printf("Ukupno evidentirano %d vozila.\n",uk);
            
            if(max==brojac_c){
                rez=(float)brojac_c/uk*100; 
                printf("Najpopularnija boja je crna (%.2f%%).",rez);
            }
            else if(max==brojac_b){
                rez=(float)brojac_b/uk*100;
                printf("Najpopularnija boja je bijela (%.2f%%).",rez);
            }
            else if(max==brojac_s){
                rez=(float)brojac_s/uk*100;
                printf("Najpopularnija boja je siva (%.2f%%).",rez);
            }
            else if(max==brojac_v){
                rez=(float)brojac_v/uk*100;
                printf("Najpopularnija boja je crvena (%.2f%%).",rez);
            }
            else{
                rez=(float)brojac_p/uk*100; 
            printf("Najpopularnija boja je plava (%.2f%%).",rez);
            }
        } 
        
    return 0;
}