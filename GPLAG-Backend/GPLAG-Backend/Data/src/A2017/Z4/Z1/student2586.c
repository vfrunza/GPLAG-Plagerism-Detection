#include <stdio.h>

int broj_cifara(int broj){
	int brojac=0;
	if(broj==0) return 1;
	if(broj<0) broj*=-1;
	while(broj!=0){
		brojac++;
		broj/=10;
	}
	return brojac;
}

int obrni(int broj){
	int c=0;
	while(broj!=0){
		c=c*10+broj%10;
		broj/=10;
	}
	return c;
}

int nula(int broj){
    if(broj%10==0) return 1;
    else return 0;
}

char *ubaci_broj(char *s, int broj){
    int negativan=0, privremeni, treba_li_nula=nula(broj), brojac=0;
    char *vrati=s, *kraj=NULL, *tmp=NULL, *tmp2=NULL;
    if(broj<0){
        negativan=1;
        broj*=-1;
    }
    provjeri:
    while(*s!='\0'){
        while(*s==' '){
            s++;
            if(*s=='\0') return vrati;
        }
        while(*s!=' ' && *s!='\0') s++;
        tmp=s;
        while(*tmp==' '){
            tmp++;
            brojac++;
        }
        if(*tmp=='\0') return vrati;
        if(*s=='\0') goto provjeri;
        kraj=s;
        while(*kraj!='\0') kraj++;
        if(negativan){
            while(kraj>s){
                *(kraj+broj_cifara(broj)+2)=*kraj;
                kraj--;
            }
        }else {
            while(kraj>s){
                *(kraj+broj_cifara(broj)+1)=*kraj;
                kraj--;
            }
        }
        s++;
        privremeni=obrni(broj);
        if(negativan){
            *s='-';
            s++;
        }
        while(privremeni!=0){
            *s=(privremeni%10)+'0';
            s++;
            privremeni/=10;
        }
        if(treba_li_nula){
            *s=0+'0';
            s++;
        }
        if(brojac==1) *s=' ';
        else if(*s!=' '){
            while(*s!=' '){
                kraj=s+1;
                tmp2=s;
                while(*s++=*kraj++);
                *s='\0';
                s=tmp2;
            }
        } else{
            kraj=s+1;
            tmp2=s;
            while (*s++=*kraj++);
            *s='\0';
            s=tmp2;
        }
        s++;
        brojac=0;
    }
    return vrati;
}


int main(){
	char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
	printf("\"%s\"", ubaci_broj(s, 320));
	return 0;
}