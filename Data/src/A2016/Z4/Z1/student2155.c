#include <stdio.h>
int uporedi(char *s1,char *s2){
    while(*s1 != '\0' && *s2 != '\0'){
      if(*s1 == *s2 || *s1 == (*s2)+ 32 || *s1 == (*s2) - 32){
          s1++;
          s2++;
      }else break;
    }
    if(*s1 == '\0' && *s2 == '\0')
        return 1;
    return 0;
}
int trazi_rijec(char* s1, char* s2) {
    int brojac = 0;
while (*s1 != '\0') 
{
    while (!(*s1 >= 'A' && *s1 <= 'Z' || *s1 >= 'a' && *s1 <= 'z') && s1 != '\0') 
        s1++;
        if(*s1 == '\0')
            return brojac;
char* p = s1;
char* q = s2;
while ((*p == *q || *p == *q + 32 || *p == *q - 32) && *p!= '\0' && *q !='\0'){
    p++;
    q++;
if (*q == '\0' && (!(*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z') || *p == '\0')){
    brojac++;
    break;
}
}
while ((*s1 >= 'A' && *s1 <= 'Z' || *s1 >= 'a' && *s1 <= 'z') && *s1 != '\0')
    s1++;
}
return brojac;
}
char *izbaci_najcescu(char* s){
   char rijec[100000];
   char *p = s;
   char *maxadresa;
   char maxrijec[100000];
   int max;
   int i = 0;
   char *tmp2 = s;
   char *tmp = s;
/*ako je string sastavljen od znakova vracam s*/
   while(!(*tmp2 >= 'A' && *tmp2 <= 'Z' || *tmp2 >= 'a' && *tmp2 <= 'z') && *tmp2 != '\0'){
       tmp2++;
   }
   if(*tmp2 == '\0')
        return s;
/* nadjem koliko puta se ponavlja prva rijec da imam s cim usporedjivat*/
   while(!(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z') && *p != '\0')
        p++;
    maxadresa = p;
    while(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z'){
        rijec[i++] = *p;
        p++;
    }
    rijec[i] = '\0';
    max = trazi_rijec(s,rijec);
    p = s;
   while(*p != '\0'){
        while(!(*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z') && *p != '\0')
            p++;
        char *q = p;
        i = 0;
       while(*q >= 'A' && *q <= 'Z' || *q >= 'a' && *q <= 'z'){
            rijec[i++] = *q;
        q++;
    }
    rijec[i] = '\0';
    if(trazi_rijec(s,rijec) > max){
        max =trazi_rijec(s,rijec);
        maxadresa = p;
    }
    while((*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z') && *p != '\0')
       p++;
   }
/*stavljam rijec koja se najvise puta ponavlja u maxrijec*/
i = 0;
while(*maxadresa >= 'A' && *maxadresa <= 'Z' || *maxadresa >= 'a' && *maxadresa <= 'z')
    maxrijec[i++] = *(maxadresa++);
maxrijec[i] = '\0';
/* Izbacivanje*/
tmp = s;
while(*tmp != '\0'){
while(!(*tmp >= 'A' && *tmp <= 'Z' || *tmp >= 'a' && *tmp <= 'z') && *tmp != '\0')
    tmp++;
char *q = tmp;
char *p = tmp;
i = 0;
while(*q >= 'A' && *q <= 'Z' || *q >= 'a' && *q <= 'z'){
    rijec[i++]=*q;
    q++;
}
rijec[i]='\0';
if(uporedi(rijec,maxrijec)){
    while(*q != '\0' && *p != '\0'){
        *p=*q;
        p++;
        q++;
    }
    *p = '\0';
}
while((*tmp >= 'A' && *tmp <= 'Z' || *tmp >= 'a' && *tmp <= 'z') && tmp != '\0')
    tmp++;
}
   return s;
}
int main() {
    return 0;
}
