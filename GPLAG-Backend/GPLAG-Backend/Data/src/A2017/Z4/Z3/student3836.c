#include <stdio.h>

void unesi(char niz[], int velicina)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* (char* s1, char* s2){
    
    char *p=s1, *p1, *p2, *r=s1;
   int razmak=1, bs1=0, bs2=0, i, a=1, naj;
   while (*s != '\0') {
   if (*s == ' ')
   razmak=1;
   else if (razmak == 1 && (*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
   razmak=0;
   
   while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
      for(i=0; i<s; i++){
          if(!(*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) break;
          if(*p==*(s+1) && p==s){
              p++; s++;}
          else if(*p==*(s+1)){ 
              p++; s=p;
          }
          else{ bs1++; s++;}
      }
      
      while(!(*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
      s++;
      
      p1=p=s;
       for(i=0; i<s; i++){
          if(!(*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) break;
          if(*p==*(s+1) && p==s){
              p++; s++;}
          else if(*p==*(s+1)){ 
              p++; s=p;
          }
          else{ bs2++; s++;}
      }
      if(bs1>bs2) naj=bs1;
      else if(bs2>bs1) naj=bs2;
      else if(bs1==bs2) naj=bs1;
      
      s--;
       s++;
   }
   
   a++;
   
   }
   s++;
   }
    
}
   
