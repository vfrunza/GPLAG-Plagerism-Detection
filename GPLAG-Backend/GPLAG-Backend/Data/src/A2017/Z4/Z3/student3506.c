#include <stdio.h>

void najduzi_bp(char *s1, char *s2) {
    char *poc_drugog, *poc_prvog, *pocetak2;
    int duz1, duz2=0, i, t;
    while(*s1!='\0') {
        if((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
            poc_drugog=s2;
            duz1=1;
            poc_prvog=s1;
            s1++;
            while((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
                pocetak2=poc_prvog;
                
                while(pocetak2!=s1) {
                    if(*pocetak2>='A' && *pocetak2<='Z') {
                        if((*pocetak2+'a'-'A')==*s1) {
                            t=0;
                            break;
                        }
                    }
                    else if(*pocetak2==*s1) {
                            t=0;
                            break;
                    }
                    pocetak2++;
                }
                if(t==0) {
                    s1=pocetak2+1;
                    break;
                }
                duz1++;
                s1++;
            }
            if(duz1>duz2) {
                for(i=0; i<duz1; i++) {
                    *poc_drugog=*poc_prvog;
                    poc_prvog++;
                    poc_drugog++;
                }
                *poc_drugog='\0';
                duz2=duz1;
            }
            s1--;
        }
        s1++;
    }
}

int main() {
/*	printf("Zadaća 4, Zadatak 3");*/
    char s1[]="to je neki primjer teksta";
    char s2[10];
    najduzi_bp(s1,s2);
    printf("%s", s2);
	return 0;
}
