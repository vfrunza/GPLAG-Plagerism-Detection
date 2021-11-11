#include <stdio.h>
#include <ctype.h>
int duzina(char *s)
{
    char *p;
    p=s;
    while(*s!='\0') s++;
    return s-p;
}

int uporedi_stringove(const char *s1, const char *s2)
{
    while(*s1!='\0' && *s2!='\0') {
        if(*s1==*s2+32 || *s1==*s2-32) {
            s1++;
            s2++;
            continue;
        } else if(*s1>64 && *s1<96 && *s2>96) {
            if(*s1+32>*s2) return 1;
            if(*s1+32<*s2) return -1;
        } else if(*s1>96 && *s1<128 && *s2>64 && *s2<96) {
            if(*s1-32>*s2) return 1;
            if(*s1-32<*s2) return -1;
        } else {
            if(*s1>*s2) return 1;
            if(*s1<*s2) return -1;
        }
        s1++;
        s2++;
    }
    if(*s1!='\0') return 1;
    if(*s2!='\0') return -1;
    return 0;
}
int nadji_max (int niz[], int velicina)
{
    int maks=niz[0], i;
    for (i=0; i<velicina; i++)
        if (niz[i]>maks) maks=niz[i];
    return maks;
}
int lokacija (int niz[], int velicina)
{
    int i, maks=nadji_max(niz,velicina);
    for (i=0; i<velicina; i++)
        if (niz[i]==maks) return i;
}
int alfa (char *rijec)
{
    int alfan=0;
    char *p2=rijec;
    if ((*p2>='A' && *p2<='Z')|| (*p2>='a' && *p2<='z')) alfan=1;
    return alfan;
}
int nije_alfa (char *p2)
{
    return ((!((*p2>='A' && *p2<='Z')|| (*p2>='a' && *p2<='z'))) && *p2!='\0');
}
void izbaci_rijec(char *s, char *rijec)
{
    int i, j, duzina_stringa, duzina_rijeci;
    int pronadjen;
    duzina_stringa=duzina(s);
    duzina_rijeci=duzina(rijec);
    if (uporedi_stringove(s,rijec)==0 && alfa(rijec)) {
        s[0]='\0';
        goto kraj;
    }
    for(i=0; i<duzina_stringa-duzina_rijeci; i++) {
        // if (pronadjen==2) continue;
        if (duzina_rijeci==1) {
            for (i=0; i<duzina_stringa; i++)
                if (s[i]==rijec[0]) {
                    pronadjen=2;
                    goto dalje;
                }
        }
        pronadjen=1;
        for(j=0; j<duzina_rijeci; j++) {
            if(s[i+j]!=rijec[j] && !((rijec[j]>='A' && rijec[j]<='Z') || (rijec[j]>='a' && rijec[j]<='z'))|| !((i==0 || nije_alfa(s+i-1)) && (nije_alfa(s+i+duzina_rijeci) || s[i+duzina_rijeci]=='\0'))) {

                pronadjen=0;
                break;
            }
        }
dalje:
        if(pronadjen>=1) {
            if (s[duzina_stringa-1]==rijec[0]) {
                s[duzina_stringa-1]='\0';
                goto dodjela;
            } else for(j=i; j<duzina_stringa-duzina_rijeci; j++) {
                    s[j]=s[j+duzina_rijeci];
                }
            s[j]='\0';
dodjela:
            duzina_stringa=duzina_stringa-duzina_rijeci;
        }
    }
kraj:
    duzina_stringa=duzina_stringa; //dummy
}
char* izbaci_najcescu(char* s)
{
    int z;
    char pomocni[10000]="";
    if (!duzina(s)) return s;
    for (z=0; z<duzina(s); z++) pomocni[z]=s[z];
    char *p=s, *p2=pomocni;
    char *niz_rijeci[100];
    char histogram[100]= {0};
    int i, j=0, k, lok=0, duzina_stringa=duzina(s);
    for (; *p2; p2++) {
        while (nije_alfa(p2)&& *p2!='\0') p2++;
        //if (*p2==' ')
        niz_rijeci[j++]=p2;
        while (alfa(p2)) p2++;
        if (*p2=='\0') {
            // niz_rijeci[j++]=p2; //?
            break;
        }
        *p2='\0';
    }
 //  for (i=0; i<j; i++) printf ("%s\n",niz_rijeci[i]);
    for (i=0; i<j; i++)
        for (k=0; k<j; k++) {
            if (uporedi_stringove(niz_rijeci[i],niz_rijeci[k])==0 && i!=k) histogram[i]++;
        }
     //for (i=0;i<j;i++) printf ("%d ",histogram[i]);
    lok=lokacija(histogram,j);
    izbaci_rijec(s, niz_rijeci[lok]);
    return p;
}
int main()
{
    char t[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
printf("'%s'", izbaci_najcescu(t));

    return 0;
}
