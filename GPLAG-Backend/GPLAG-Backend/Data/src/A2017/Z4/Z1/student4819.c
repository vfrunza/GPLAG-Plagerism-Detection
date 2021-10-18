#include <stdio.h>


 void unesi(char niz[], int velicina) {
     int i=0;
     char znak=getchar();
     if(znak=='\n') znak=getchar();
     
     while(i<velicina-1 && znak !='\n') {
         niz[i]=znak;
         i++;
         znak=getchar();
         
     }
     niz[i]='\0';
 }
 
 

 
 
 char *ubaci_broj(char *s, int broj) {
  
     int pomocni_broj;
     int pomocni_broj2;
     char *kraj;
     char *pocetak=s;
     int brojac=0;
     int brojac_rijeci=0;
    
    
     while(*s!='\0') {
       while(*s!='\0' &&  *s ==' ') s++;
       
        
          if(*s!='\0' &&  *s !=' ') brojac_rijeci++;
          while(*s!='\0' &&  *s !=' ') s++;
          
          if(*s=='\0') break;
         
     }
      
      
     
     s=pocetak;
     while(*s!='\0') {
         while(*s!='\0' && *s==' ') s++;
       
         if(*s!='\0' && ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) {
             brojac++;
           /*  while(*s!='\0' && ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) s++; */
                while(*s!='\0' &&  *s !=' ') s++;
            
             if(brojac!=brojac_rijeci) {
                 if(s!='\0' && *s==' ') s++; 
                
                 pomocni_broj=broj;
                 if(pomocni_broj<0) {
                     kraj=s;
                     
                     while(*kraj!='\0') {
                         kraj++;
                     }
                      kraj++;
                      
                      while(kraj>s) {
                         *kraj=*(kraj-1);
                         kraj--;
                     }
                      pomocni_broj=pomocni_broj*(-1);
                      *s='-';
                      s++;
                     
                     }
                     pomocni_broj2=0;
                     while(pomocni_broj>0) {
                         pomocni_broj2=pomocni_broj2*10+(pomocni_broj%10);
                         pomocni_broj/=10;
                     }
                     
                     
                     while(pomocni_broj2>0) {
                         kraj=s;
                         while(*kraj!='\0') {
                             kraj++;
                         }
                         kraj++;
                         while(kraj>s) {
                             *kraj=*(kraj-1);
                             kraj--;
                             
                         }
                         *s=(pomocni_broj2%10)+'0';
                         s++;
                      
                         pomocni_broj2=pomocni_broj2/10;
                     }
                     
                     
                     if(*s!='\0' && *s!=' ') {
                         kraj=s;
                         while(*kraj!='\0') kraj++;
                         kraj++;
                         while(kraj>s) {
                             *kraj=*(kraj-1);
                             kraj--;
                         }
                         *s=' ';
                     }
                 }
             }
             if(*s=='\0') break;
             s++;
         }
         return pocetak;
     }


int main() {
  
   char s[12] = "hello.world";
  char s2[15] = "hello world";
printf("\"%s\"\n", ubaci_broj(s, 15));
printf("\"%s\"", ubaci_broj(s2, 15));
	   
	return 0;
}





