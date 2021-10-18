#include <stdio.h>
#include <math.h>

char* ubaci_broj (char* s, int broj){
    char p[10];
    char *pok=s;
    int br=0,temp1=broj;
    if(temp1<0) temp1=-temp1;
    while(temp1!=0){
        int temp;
        temp=temp1%10;
        p[br]=temp + '0';
        temp1=temp1/10;
        br++;
    }
    br=br-1;
    if(broj<0) p[++br]='-';
    while(*s==' ') s++;
    
    while(*s!='\0'){
        
            if(*s==' '){
                char *k=s;
                while(*k==' ') k++; 
                if(*k=='\0') break; 
                s++;
                char *kraj=s;
                while(*kraj!='\0') kraj++;
                while(kraj>=s){
                    *(kraj+br+2)=*kraj;
                    kraj--;
                }
                int i;
                for(i=br;i>=0;i--){
                    *s=p[i];
                    s++;
                }
                *s=' ';
                
            }
        s++;
    }
    return pok;
}
int main() {
    char string[100]={"ovo je neki string"};
    int broj=100;
    char *pok;
    pok=ubaci_broj(string,broj);
    while(*pok!='\0'){
        printf("%c",pok);
    }
	return 0;
}
