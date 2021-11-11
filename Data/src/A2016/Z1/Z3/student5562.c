#include <stdio.h>

int main() {
	
    char a;
    float br = 0;
    int crna = 0, bijela = 0, crvena = 0, siva = 0, plava = 0;
    int max = crna;
    int neispravno = 0;
    float proc;
    
    
    printf("Unesite vozila: ");
    
    do{
    
        scanf("%c",&a);
    
        if (a != 'k' && a != 'K'){
            
        
            if (a == 'v' || a == 'V'){
                crvena++;
                br++;
            }
            else if (a == 'c' || a == 'C'){
                crna++;
                br++;
            
            }
            else if (a == 'b' || a == 'B'){
                bijela++;
                br++;
            
            }
            else if (a == 's' || a == 'S'){
                siva++;
                br++;
            
            }
            else if (a == 'p' || a == 'P'){
                plava++;
                br++;
            
            }
            
            else
            {
                printf("Neispravan unos\n");
            }
        }
        
    } while (a != 'k' && a != 'K');
    
    
    
    if (bijela > max)
        max = bijela;
    
    if (crvena > max)
        max = crvena;
    
    if (siva > max)
        max = siva;
    
    if (plava > max)
        max = plava;
        
    if (crna > max)
        max = crna;
        
    
    if (br > 0)
       proc =  max/br*100;
    else
       proc = 0;
    
    
    printf("Ukupno evidentirano %g vozila.\n", br);
    
    
    if (max == crna){
        printf("Najpopularnija boja je crna (%.2f%%).", proc);
        return 0;
    }
        
    if (max == bijela){
        printf("Najpopularnija boja je bijela (%.2f%%).", proc);
        return 0;
    } 
        
    if (max == siva){
        printf("Najpopularnija boja je siva (%.2f%%).",proc);
        return 0;   
    }
        
    if (max == crvena){
        printf("Najpopularnija boja je crvena (%.2f%%).", proc);
        return 0;  
     }
        
    if (max == plava){
        printf("Najpopularnija boja je plava (%.2f%%).", proc);
    return 0;
        
    }
    
	
	return 0;
}
