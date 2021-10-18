#include <stdio.h>
#include <stdlib.h>

void unesi(char ime[], int vel) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < vel && znak != '\n') {
        ime[i] = znak;
        i++;
        znak = getchar();
    }
    ime[i]='\0';
}


int izbroji( char *niz){
    int n=0,i=0;
    while(niz[i]!='\0'){
        n++;
        i++;
    }
    return n;
}


void izbaci_najcescu(char* s){
  char *p[10], *a[10];
  int neslovo=1, br_rijeci=0, i,j,brojac[10]={0},k=0,n=0;
  while(*s!='\0'){
      if (!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))){
          neslovo=1;
      }
      else if(neslovo==1){
          neslovo=0;
          p[br_rijeci]=s;
          a[br_rijeci]=s;
          br_rijeci++;
      }
      s++;
  }
  
  for (i=0;i<br_rijeci-1;i++){
      for (j=i+1;j<br_rijeci;j++){
          a[i]=p[i];

 while (!((*a[i]>='a' && *a[i]<='z') || (*a[i]>='A' && *a[i]<='Z'))){
     if (*a[i]==*p[j]){
         n++;
     }
     else if (*a[i]!=*p[j]){ k++;
      }
      a[i]++;
      p[j]++;
  }
    if (k==0){ brojac[i]++;}
    k=0;
    n=0;
    
      }    
}

for (i=0;i<br_rijeci;i++)
{
    printf ("%2d", brojac[i]);
}
}


int main() {
 
 char recenica[50];
 printf ("Unesite recenicu:\n");
 unesi (recenica,50);
 izbaci_najcescu(recenica);
 
 return 0;
}
