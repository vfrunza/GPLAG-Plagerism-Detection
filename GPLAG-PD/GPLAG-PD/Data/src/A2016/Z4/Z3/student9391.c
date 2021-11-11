#include <stdio.h>

int izbroji(char *niz)
{
    char *o;
    o=niz;
    while(*o!='\0') {
        o++;
    }
    return o-niz;
}

char *prekopiraj(char *t, const char *s)
{
    int vel=izbroji(s);
    char *t1=t;
    if(t==NULL) return NULL;
    if((t-s<=izbroji(s)) || (s-t<=izbroji(s))) return NULL;
    while(*t++=*s++);
    return t1;
}

void prekopiraj2(void *destinacija, void *izvor, int n)
{
    int i;
    char *csrc = (char *)izvor;
    char *cdest = (char *)destinacija;
    for (i=0; i<n; i++)
        cdest[i] = csrc[i];
}

char *substring(char *s, char *p)
{
    int i, j;
    int flag=0;
    if(s==NULL || p==NULL) return 0;
    for(i=0; s[i]!='\0'; i++) {
        if(s[i]==p[0] && (i==0 || s[i-1]==' ') && (s[i+izbroji(p)]==' ' || s[i+izbroji(p)]=='\0')) {
            for(j=i;; j++) {
                if(p[j-i]=='\0') {
                    flag=1;
                    break;
                }
                if(s[j]==p[j-i]) continue;
                else break;
            }
        } else if(i==izbroji(s)-1 || s[i+1]=='\0' || s[i+1]==' ') {
            for(j=i;; j++) {
                if(p[j-i]=='\0') {
                    flag=1;
                    break;
                }
                if(s[j]==p[j-i]) continue;
                else break;
            }
        }
        if(flag) break;
    }
    if(flag) return(s+i);
    else return 0;
}

void zamijeni(char *string, const char *orig, const char *zamjena)
{
    char pomocni[1024] = { 0 };
    char *p = pomocni;
    const char *tmp = string;
    int duzinaRijeci = izbroji(orig);
    int duzina_zamjene = izbroji(zamjena);

    while (1)
    {
        const char *p = substring(tmp, orig);

        if (p == NULL)
        {
            prekopiraj(p, tmp);
            break;
        }
        prekopiraj2(p, tmp, p - tmp);
        p += p - tmp;
        prekopiraj2(p, zamjena, duzina_zamjene);
        p += duzina_zamjene;

        tmp = p + duzinaRijeci;
    }
    prekopiraj(string, pomocni);
}

char *zamjena_rijeci(char* tekst, char **rijeci, char** zamjene, int broj_rijeci)
{
    int i;
    char *h=tekst;
    for(i=0; i<broj_rijeci; i++)
        zamijeni(tekst, rijeci[i], zamjene[i]);

    return h;
}

int main()
{
    char* rijeci[2] = { "Ovo" };
    char* zamjene[2] = { "AAA" };
    char tekst[100] = "Ovo je ovo je OVO";
    printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));
    //printf("Zadaća 4, Zadatak 3");
    return 0;
}