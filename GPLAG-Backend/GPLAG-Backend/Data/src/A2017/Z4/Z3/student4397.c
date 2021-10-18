#include <stdio.h>

void najduzi_bp(char* p, char* s) {
    
    char *p1=p, *p2;
    int brojac1 = 0,brojac2 = 0,i=0,j=0,ponavlja=0;
    int brojaci[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    while (*p1 != '\0') {
        p2 = p1;
        ponavlja=0;
        while (ponavlja !=1 && *p2!=' ' && *p2!='\0' && (*p2 >= 'A' && *p2 <= 'Z' || *p2 >= 'a' && *p2 <= 'z')) {
            if((*p2>='A' && *p2<='Z')||(*p2>='a' && *p2<='z')) {
                if(*p2<='Z') i=*p2-'A';
            else i=*p2-'a';
            brojaci[i]++;
            for(j=0;j<26;j++) {
                if(brojaci[j]>1) {
                    ponavlja=1;
                    break;
                }
            }
            if((*p2==' ' || ponavlja==1 || *p2=='\0')) break;
            brojac1++;
        }
        p2++;
    }
    for(j=0;j<26;j++) {
        brojaci[j]=0;
    }
    if(brojac1>brojac2) {
        for(j=0;j<brojac1;j++) {
            *s=*(p1+j);
            s++;
        }
        *s='\0';
        s-=brojac1;
        brojac2=brojac1;
    }
    brojac1=0;
    p1++;
}
}
int main() {
    char niz[10];
    najduzi_bp("abcde etankera cdefg", niz);
    printf("Niz: '%s' ", niz);
	return 0;
}
