#include <stdio.h>
void unos(char*string,int vel){
   int i=0;
   char c;
   do{
      c=getchar();
      string[i]=c;
      i++;
   }
   while(c !='\n' && i<vel);
   string[i-1]='\0';
}
char* izbaci_najcescu(char* string){
   char*poc=string;
   while(*string !='\0'){
       *string++;
       string=poc;
       return string;
   }
}
int main(){
   char niz[100];
   unos(niz,100);
   printf("%s",izbaci_najcescu(niz));
   return 0;
}
