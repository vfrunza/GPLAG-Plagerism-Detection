#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak=getchar ();
    if (znak=='\n') znak=getchar();
    int i=0;
    while (i<velicina-1 && znak!='\n') {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

void najduzi_bp (char* s1, char* s2) {
    int duz=0, maxduz=0, maxvr=0, trmaxduz=0, trmaxvr=0, max;
    while (*s1!='\0') {
        if ((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) {
            char* d1=s1;
            while ((*d1>='A' && d1<='Z') || (*d1>='a' && *d1<='z')) {
                duz++;
                d1++;
            }
            char* p1=s1;
            char* q1;
            trmaxvr=*s1;
            while (*p1<duz) {
                q1=p1+1;
                while (*q1<duz) {
                   if (*p1==*q1 || *p1==*q1+32) break;
                   else {
                       trmaxduz++;
                }
                   q1++; 
                }
                p1++;
            }
            maxvr=0;
            maxduz=0;
            if (trmaxduz>=maxduz) {
                if(trmaxduz>maxduz) {
                max=maxvr;
                maxvr=trmaxvr;
                max=trmaxvr;;
                }
                else if (trmaxduz==maxduz) {
                  max=maxvr;
                }
            }
        }
        s1++;
    }
    char *n=max;
    while((*n>='A' && *n<='Z') || (*n>='a' && *n<='z')) {
        *n==*s2++;
         s2++;
         n++;
    }
    *s2='\0';
    
}

int main() {
	char tekst1[100];
	char tekst2[100];
	printf ("Unesite tekst: ");
	unesi(tekst1, 100);
	najduzi_bp(tekst1, tekst2);
	printf ("Najduzi je: %s", tekst2);
	
	return 0;
}
