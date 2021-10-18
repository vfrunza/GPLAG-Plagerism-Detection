#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

char *ubaci_broj(char *tekst, int broj){
    char *start=tekst;
    char *tmp=tekst;
    int i, neg=0, num_size, size=0, tmp_num;
    
    if(broj<0){
        neg=1;
        broj=abs(broj);
        num_size=log10(broj)+2;
    }
    else
        num_size=log10(broj)+1;
    while(*tmp!='\0'){
        if(*tmp==' '){
            char *end=tmp;
            while(*end!='\0') end++;
            
            while(end>tmp){
                *(end+num_size)=*end;
                end--;
            }
            i=0;
            tmp++;
            tmp_num=broj;
            
            if(neg){
                *tmp='-';
                tmp++;
                i++;
                
                while(i<num_size){
                    *tmp++=tmp_num/pow(10,num_size-i-1)+'0';
                    tmp_num=tmp_num%(int)pow(10,num_size-i-1);
                    i++;
                }
            }
            else{
                while(i<num_size){
                    *tmp++=tmp_num/(int)pow(10,num_size-i-1)+'0';
                    tmp_num=tmp_num%(int)pow(10,num_size-i-1);
                    i++;
                }
            }
        }
        
        if(*tmp!=' ' && *(tmp-1)==broj%10+'0'){
            char *end=tmp;
            while(*end!='\0') end++;
            
            while(end>tmp-1){
                *(end+1)=*end;
                end--;
            }
            *tmp=' ';
        }
        if(*tmp!=' ' && *(tmp-1)==' ') tmp++;
        tmp++;
    }
    return start;
}

int main(){
    int num;
    char str[100];
    printf("Unesite string:\n");
    unesi(str, 100);
    printf("Unesite broj:\n");
    scanf("%d", &num);
    printf("%s\n", ubaci_broj(str,num));
    return 0;
}
