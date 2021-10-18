#include <stdio.h>



int prebroj_rijeci(char *string){
    char *pok=string;
    int brojac=0;
    
    while (*pok!='\0') {
        if((*pok>='a'&& *pok<='z') || (*pok>='A'&& *pok<='Z')){
            while((*pok>='a'&& *pok<='z')||(*pok>='A'&& *pok<='Z')){
                pok++;
            }
            brojac++;
        }
        if(*pok=='\0')break;
        pok++;
    }
    return brojac;
}

int provjeri_duzine(char *string,int *niz,int vel){
int br_slova=0;
int br_rijeci=0;
int da=1,i=0;
char*p=string;
char*q=string;
br_rijeci=prebroj_rijeci(string);
if(br_rijeci!=vel)return 0;
while(*string!='\0'){
    if(!((*string>='A'&&*string<='Z')||(*string>='a'&&*string<='z')))
    while(!((*string>='A'&&*string<='Z')||(*string>='a'&&*string<='z'))&&*string!='\0')string++;
    p=string;
    while(((*string>='A'&&*string<='Z')||(*string>='a'&&*string<='z'))&&*string!='\0')string++;
    q=string;
    while(p<q){
        br_slova++;
        p++;
    }
    if(br_slova!=niz[i])da=0;
    i++;
    if(i==vel)break;
    br_slova=0;
    if(*string!='\0')string++;
}
return da;
    
    
    
}
int main(){
    char string[50]="Ovo je neki primjer teksta Auto-Stop";
    int broj[10]={3,2,4,7,6,4,4};
    printf("%d",provjeri_duzine(string,broj,5));
    return 0;
    
    
    }