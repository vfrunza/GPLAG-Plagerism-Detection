#include <stdio.h>
int poredirijeci(char*s1, char*s2){
    char*p=s1;
    char*q=s2;
    char temp1, temp2;
    int x=1;
    
    while(((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) && ((*q >= 'A' && *q <= 'Z') || (*q >= 'a' && *q <= 'z')) && *p != '\0' && *q != '\0') {
    temp1=*p;
    temp2=*q;
    
    if(temp1>='A' && temp1<='Z')
    temp1=temp1+32;
    if(temp2>='A' && temp2<='Z')
    temp2=temp2+32;
    if(temp1!=temp2){
        x=0;
        break;
    }
        p++;
        q++;
    }
    
    if(x){
         if (((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) || ((*q >= 'A' && *q <= 'Z') || (*q >= 'a' && *q <= 'z')) )
         x=0;
    }
    return x;
}

int podstring(char*s1, char*s2, int vel){
    char temp1, temp2;
    char*poc=s1;
    int brojac=0;
    
    while(*s1!='\0'){
        char*p=s1;
        char*q=s2;
        temp1=*p;
        temp2=*q;
        
           if (temp1 >= 'A' && temp1 <= 'Z')
            temp1 = temp1 + 32;

        if (temp2 >= 'A' && temp2 <= 'Z')
            temp2 = temp2 + 32;
            
        while(temp1==temp2){
            p++;
            q++;
            temp1=*p;
            temp2=*q;
            
           if ((q == s2 + vel) && (s1 == poc ||  (!((*(s1-1) >= 'A' && *(s1-1) <= 'Z') || (*(s1-1) >= 'a' && *(s1-1) <= 'z')))) && ((!((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))) || *p ==  '\0')) {
               brojac++;
               break;
           } else if(q==s2+vel)
           break;
        }
        s1++;
    }
    return brojac;
}

char* rijecnaj(char*s){
    int brojacrijeci=0;
    int maxrepeats;
    int numrepeats;
    int velr;
    char *poc=NULL;
    char* kraj=NULL;
    char* pocmax=NULL;
    char*koppoc=s;
    
    int flag=1, flag2=1;
    
    while(*s!='\0'){
          if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
              brojacrijeci++;
              flag=1;
              while((*s != '\0') && ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {
                  if(flag){
                      poc=s;
                      flag=0;
                  }
                  s++;
              }
              kraj=s;
              
              if(flag2){
                  velr=kraj-poc;
                  maxrepeats=podstring(koppoc,poc, velr);
                  pocmax=poc;
                  flag2=0;
              } else if(poredirijeci(pocmax,poc)){
                  pocmax=poc;
              } else{
                  velr=kraj-poc;
                  numrepeats=podstring(koppoc,poc, velr);
                  if(numrepeats>maxrepeats){
                      maxrepeats=numrepeats;
                      pocmax=poc;
                  }
              }
              if(*s=='\0')
              break;
          }
          s++;
    }
    if(brojacrijeci=0)
    return NULL;
    return pocmax;
}

char* izbacirijec(char*s, int n){
    char*koppoc=s;
    int brojac=0;
    int flag=0;
    char*poc=NULL;
    char*kraj=NULL;
    
    while(*s!='\0'){
          if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
              brojac++;
              flag=1;
              while(((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))&& *s != '\0') {
                if (flag) { poc=s;
                flag=0;
          }
          s++;
    }
    
    kraj=s;
    if(brojac==n){
        while(((*(poc++))=(*(kraj++))));
    }
    if(*s=='\0')
    break;}
    s++;}
    return koppoc;
    
}

int duzr(char*s){
    int duzina=0;
    while(((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) && *s != '\0') {
        duzina++;
        s++;
    }
    return duzina;
}


char* izbaci_najcescu(char*s){
    char*s3=rijecnaj(s);
    if(s3==NULL)
    return s;
    
    int duzinarijeci=duzr(s3);
    char*poc=NULL;
    char* koppoc=s;
    int flag=0;
    int flag1=0;
    int brojac=0;
    
  while(*s!='\0'){
      if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')){
          brojac++;
          flag=1;
          while(((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) && *s != '\0'){
              if(flag){
                  poc=s;
                  flag=0;
              }
              s++;
          }
          if(poc==s3)
          flag1=1;
          if(poredirijeci(s3,poc)){
              izbacirijec(koppoc, brojac);
              s=s-duzinarijeci;
              brojac--;
              s3=s3-duzinarijeci;
          }
          if(flag1)
          break;
          if(*s=='\0')
          break;
      }
      if(flag1)
      break;
      s++;}
      return koppoc;
  }  
    
    
    
    void unesi(char niz[], int velicina){
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


int main() {
char *tekst[100];
printf("Unesite neki tekst: ");
unesi(tekst,100);
printf("Nakon izbacivanja uneseni tekst glasi: %s", izbaci_najcescu(tekst));
	return 0;
}





