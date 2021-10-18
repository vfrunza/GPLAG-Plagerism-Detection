#include <stdio.h>

void unesi(char *s, int duzina){
    
    int i = 0;
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    
    while (znak != '\n' && i < duzina - 1){
        
        s[i] = znak;
        i++;
        znak = getchar();
        
        
    }
    s[i] = '\0';
    
}

int izmjeri(char * p){
    
    char* p1 = p;
    char* p2;
    
    while (*p1 != ' ' && *p1 != '\0')
        p1++;
    p2 = p1;
    
    return p2 - p;
    
}

char * zamjena_rijeci (char* tekst, char**rijeci, char**zamjene, int broj_rijeci){
    
    int i, j, duzri, duzzam;
    char* p = tekst, *p2, *p2poc;
    char* ppoc, *pokpoc, * zamjpoc;
    
    while (*p != '\0'){
        
        /*Preskoci sve razmake*/
        while (*p == ' ' && *p != '\0')
            p++;
        
        for (i = 0; i < broj_rijeci; i++){
            
            /*Ako je slovo jednako prvom slovu*/
            if (*p == *rijeci[i]){
                
                ppoc = p;
                pokpoc = rijeci[i];
                
                /*Poredi dalje*/
                while (*rijeci[i] != '\0'  && *p != '\0'){
                    
                    
                    if (*p != *rijeci[i]){
                        break;
                        
                    }
                    
                    /*Ako je na kraju obje rijeci*/
                    if ((*(p + 1) == ' ' || *(p + 1) == '\0') && *(rijeci[i] + 1) == '\0'){ 
                        
                        
                        p = ppoc; /*Na pocetak rijeci*/
                        duzzam = izmjeri(zamjene[i]);
                        rijeci[i] = pokpoc; /*bitno vratiti na pocetak te rijeci zbog mjerenja*/
                        duzri = izmjeri(rijeci[i]);
                        
                        /*Po potrebi prosiri*/
                        if (duzzam > duzri){
                            
                            p2 = ppoc;
                            while (*p2 != '\0')
                                p2++;
                            
                            p2 += duzzam - duzri;    
                            
                            p2poc = p2;
                            for (j = 0; j < duzzam - duzri; j++){
                                
                                while (p2 > ppoc + duzri){
                                    *p2 = *(p2 - 1);
                                    p2--;
                                }
                                p2 = p2poc;
                                
                            }
                            
                        }
                        
                        /*Po potrebi skrati*/
                        if (duzri > duzzam){
                            
                            for (j = 0; j < duzri - duzzam; j++){
                                while(*p != '\0'){
                                    *p = *(p + 1);
                                    p++;
                                }
                                p = ppoc; /*Na pocetak rijeci*/
                            }
                        }
                        
                        /*Zamijeni*/
                        zamjpoc = zamjene[i];
                        while (*zamjene[i] != '\0'){
                            *p = *zamjene[i];
                            p++;
                            zamjene[i]++;
                        }
                        zamjene[i] = zamjpoc;
                        
                    } 
                    
                    /*prelazi na slijedeca slova*/
                    if (*p != '\0')
                        p++;
                    if (*rijeci[i] != '\0')
                        rijeci[i]++;
                }
                /*Reset pokazivaca p na pocetak rijeci*/
                p = ppoc;
                rijeci[i] = pokpoc;
                
            }
            
        } /*Kad izadje p ce biti na ppoc (na pocetku trenutne rijeci)*/
        
        /*Predji na drugu rijec, izlazi iz ove*/
        while (*p != ' ' && *p != '\0')
            p++;
    }
    
    return tekst;

}

int main(){
    
    char tekst[200];
    char rijeci[50][50];
    char zamjene[50][50];
    char* rijecip[50];
    char* zamjenep[50];
    int br_rijeci = 0, i;
    
    printf("Broj rijeci:\n");
    scanf("%d", &br_rijeci);
    
    printf("Tekst:\n");
    unesi(tekst, 200);
    
    printf("Rijeci:\n");
    for (i = 0; i < br_rijeci; i++){
        unesi(rijeci[i], 50);
        rijecip[i] = rijeci[i];
    }
    
    printf("Zamjene:\n");
    for (i = 0; i < br_rijeci; i++){
        unesi(zamjene[i], 50);
        zamjenep[i] = zamjene[i];
    }
    
    printf("%s", zamjena_rijeci(tekst, rijecip, zamjenep, br_rijeci));
    
    return 0;
}