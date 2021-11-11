#include <stdio.h>
void unesi(char*s,int velicina){
    int i=0;
    char znak=getchar();
    if(znak=='\n')
    znak=getchar();
    while(i<velicina-1 && znak!='\n'){
        *s++=znak;
        znak=getchar();
        i++;
    }
    s[i]='\0';
}
char* kodiraj(char*s,char*p){
    char*poc=s;
    int brojaci[96]={0},i,l,max,maxi,n;
    char*k;
    char*b=p;
    char*q=s;
    char*a;
    char*u=p;
    char*t=p;
    if(*s=='\0'){
        for(i=0;i<96;i++)
            *t++=i+32;
            *(t-1)='\0';
    }
    else{
    for(i=0;i<96;i++){
        k=s;
        while(*k){
            if(*k==i+32)
            brojaci[i]++;
            k++;
        }
    }
    while(u<b+96){
        max=0;
        maxi=0;
        for(i=0;i<96;i++){
            if(brojaci[i]>max){
                maxi=i;
                max=brojaci[i];
                l=i;
            }
        }
        brojaci[l]=-1;
        if(max!=0){
        *u=maxi+32;
        u++;
        }
        else{
                for(i=0;i<96;i++){
                    if(brojaci[i]==0)
                    *u++=i+32;
                }
                break;
        }
    }
    *(u-1)='\0';
    while(*q!='\0'){
        a=p;
        n=0;
        while(*a!='\0'){
            if(*q==*a){
                *q=126-n;
                break;
            }
            n++;
            a++;
        }
        q++;
    }
    }
    return poc;
}
char* dekodiraj(char*s,char*p){
    char*poc=s;
    char*q=p;
    char*l=s;
    while(*l!='\0'){
        *l=q[126-*l];
        l++;
    }
    return poc;
}
int main() {
    char tekst[]="Jeste li dobro kreirali sifrarnik?";
    char tekst2[96]="";
    kodiraj(tekst,tekst2);
    printf("%s",tekst2);
    printf("\n");
    printf("%s",tekst);
    dekodiraj(tekst,tekst2);
    printf("\n");
    printf("%s",tekst);
	return 0;
}
