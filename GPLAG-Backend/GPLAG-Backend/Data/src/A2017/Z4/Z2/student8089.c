#include <stdio.h>

void unesi(char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int slovo(char s){
    if((s>='A' && s<='Z') || (s>='a' && s<='z')) return 1;
     else return 0;
}

int duzinaRijeci(char *pok){
    int duzina=0;
    while(slovo(*pok)){
        duzina++; pok++;
    }
    return duzina;
}

int provjeri_duzine(char* s,int* niz,int velicina)
{
    int* u;
    int jednaki=1,razmak=1,br_rijeci=0,j=0,ispred_stringa;
    char *p;
    char* q=s;
    
    
    u=niz;
    p=s;
    q=s;
    
    
    
    while(*s != '\0') {
        //if(*s<'A' || (*s>'Z' && *s<'a') || *s>'z') razmak=1;
        if(((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) razmak=1;
        else if(razmak==1) {
            razmak=0;
            br_rijeci++;
        }
        s++;
    }
    s--;
    if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) br_rijeci++;
    

        
        /*while(*p != '\0') {
            while(u<niz+velicina) {
            if((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) {
               p++;
               br_slova++;
               if(*p<'A' || (*p > 'Z' && *p < 'a') || *p > 'z') pomocna=br_slova;
               br_slova=0;
               u++;
            }
            
            printf("Br slova: %d \n", br_slova);
            p++;
         
        
        }*/
        if(*q < 'A' || (*q > 'Z' && *q < 'a') || *q > 'z'){
            q++;
        }
        
        p=q;
        while(*p!='\0'){
            
            if(*p<'A' ||(*p >'Z' && *p<'a') || *p>'z') p++;
            
            if(duzinaRijeci(p)==*u){
                jednaki=1;
                
                if(++j==velicina) break;
               
                u++;
                while((*p>='A' && *p<='Z' && *p!='\0') || (*p>='a' && *p<='z' && *p!='\0')) p++; 
                if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))) p++;
            } 
            else {
                jednaki=0;
                break;
            }
        }
        

    
    if(jednaki==1 && velicina==br_rijeci) return 1;
    else return 0;
}

int main()
{
    /*char a[1000];
    int niz[100],vrijednost,velicina,i;

    printf("Unesite neki tekst: ");
    unesi(a,1000);
    scanf("%d",&velicina);
    printf("Unesite niz: ");
    for(i=0; i<velicina; i++) {
        scanf("%d",&niz[i]);
    }
    vrijednost=provjeri_duzine(a,niz,velicina);
    if (vrijednost == 1) printf("%d", vrijednost);
    else if(vrijednost == 0) printf("%d",vrijednost);*/
    
    char tekst[] = "Ovo je neki primjer teksta";
int niz[] = {3, 2, 4, 7, 6};
int bezveze_niz[] = {1, 2, 3, 4, 5};

printf("%d ", provjeri_duzine(tekst, niz, 5));
printf("%d ", provjeri_duzine(tekst, bezveze_niz, 5));
    return 0;
}
