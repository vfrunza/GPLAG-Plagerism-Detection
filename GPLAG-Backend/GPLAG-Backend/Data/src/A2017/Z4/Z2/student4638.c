#include <stdio.h>
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
int provjeri_duzine(char *s,int niz_brojeva[],int velicina) {
    int k=0,l=0,rijec=0,razmak=1,broj_rijeci=0,j=0,i=0;
    int istina;
    int niz_rijec[1000],niz[1000];
    char *p=s;
    while(*s!='\0') {
        if(!(*s<='a' && *s>='z') || (*s<='A' && *s>='Z')) razmak=1;
        else if(razmak==1) {
            razmak=0;
            broj_rijeci++;
        }
 s++;
    }
    s=p;
    while(*s!='\0') {
        if(!(*s<='a' && *s>='z') || (*s<='A' && *s>='Z'))
        rijec++;
        if((*s<='a' && *s>='z') || (*s<='A' && *s>='Z')) {
        niz_rijec[k]=rijec;
        k++;
        rijec=0;
    }
    s++;
}
k=0;
l=0;
for(i=0;i<broj_rijeci;i++)
niz_brojeva[i]=niz[i];
istina=1;
if(velicina==broj_rijeci) {
    for(j=0;j<velicina;j++)
if(niz_brojeva[j]!=niz[j]) {
    istina=0;
    break;
} else return 0;
if(istina==1)
return 1;
else return 0;
}
}
int main () {
 char s[1000];
 int niz[1000],i,n;
 printf("Unesite tekst: ");
 unesi(s,1000);
 printf("Unesite velicinu niza: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 scanf("%d",&niz[i]);
 printf("%d",provjeri_duzine(s,niz,n));
 return 0;
}

