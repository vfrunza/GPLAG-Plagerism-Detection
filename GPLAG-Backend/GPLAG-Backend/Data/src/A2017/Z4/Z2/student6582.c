#include <stdio.h>

int provjeri_duzine(char *str, int *niz, int size) {
    int ctr, i=0;
    int rijeci=0;
    char *tmp=str;
    int pronadjeno=0;
    
    while(*tmp != '\0'){
       
        if(!((*tmp>='a' && *tmp<='z') || (*tmp>='A' && *tmp<='Z')))
        pronadjeno=0;
        else{
            if(pronadjeno==0)
            rijeci++;
            pronadjeno=1;
        }
        tmp++;
    }
    
    
    
    if(rijeci!=size) return 0;
    
    while(*str!='\0'){
        if((*str>='a' && *str<='z') || (*str>='A' && *str<='Z')){
            ctr=0;
            while((*str>='a' && *str<='z') || (*str>='A' && *str<='Z')){
                ctr++;
                str++;
            }
            if(ctr!=niz[i]) return 0;
            i++;
        }
        if(*str=='\0') break;
        str++;
    }
    return 1;
}

void unesi(char niz[], int velicina){
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i=0;
    
    while(i<velicina-1 && znak!='\n'){
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

int main(){
    int niz[10];
    int i, size;
    char str[100];
    
    printf("Unesite string:\n");
    unesi(str, 100);
    
    printf("Unesite velicinu niza:\n");
    scanf("%d", &size);
    
    printf("Unesite niz:\n");
    for(i=0;i<size;i++){
        scanf("%d", &niz[i]);
    }
    printf("%d\n", provjeri_duzine(str, niz, size));
    return 0;
}